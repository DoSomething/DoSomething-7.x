<?php

namespace SocialGraph;
use SocialGraph\Helper\DocHelper;

class SocialGraph {
  private $crud_functions = array(
    'add',
    'update',
    'delete',
  );

  public $doc;
  public $me;

  public function __construct() {
    $entities = scandir(__DIR__ . '/entities');

    require_once __DIR__ . '/includes/doc.inc';
    $this->doc = new DocHelper($this);

    foreach ($entities AS $key => $entity) {
      if ($entity == '.' || $entity == '..') continue;

      require_once __DIR__ . '/entities/' . $entity;
      $s = ucfirst(str_replace('.inc', '', $entity));
      $class = "\SocialGraph\Entities\\$s";
      $this->{$s} = new $class;

      $reflector = new \ReflectionClass($class);
      $c = $reflector->getProperties();
      foreach ($c AS $key => $property) {
        $p = $property->getDocComment();
        $this->_build_column_info($property->class, $property->name, $p);
      }
    }
   }

   /**
    *  Parses property doc comments to get Graph information,
    *  validation and dependencies.
    * 
    *  @param $class
    *    The property's class.
    *
    *  @param $property
    *    The name of the property.
    *
    *  @param
    *    The doc comments for the property.
    */
   public function _build_column_info($class, $property, $documentation, $additional = array()) {
      if (!empty($documentation)) {
         preg_match_all('#\@Graph\\\(?<function>.*?)\((?<args>.*?)\)#', $documentation, $docFunctions);
         foreach ($docFunctions['function'] AS $key => $function) {
            $func = strtolower($function);

            if (!empty($func)) {
               $this->doc->{$func}($class, $property, $docFunctions['args'][$key], $additional);
            }
         }
      }
   }

   public function __call($method, $args) {
      preg_match('#(?<action>' . implode('|', $this->crud_functions) . ')(?<service>[A-Z]{1}[a-z0-9]+)(?<submethod>[A-Z]{1}[A-Za-z0-9]+)?#', $method, $call);
      if (!empty($call['action']) && !empty($call['service'])) {
         $s = strtolower($call['service']);
         $a = strtolower($call['action']);

         if (!empty($call['submethod'])) {
            array_push($args, ($call['submethod']));
         }

         // If we can find the service invocation of this function, run that instead!
         if (method_exists($s, $a)) {
            $this->{$s}->{$a}($args);
         }
         else {
            // An error running what would otherwise be a perfectly fine function.  Most likely it can't find the service and/or method.
            throw new SocialGraphException('We tried finding the "' . $a . '" method in the "' . $s . '" service, but no luck.  Make sure your service exists in the social_graph/services directory.');
         }
      }
      else {
         // Malformed method call.
         throw new SocialGraphException("Couldn't run malformed method \"{$method}\".  Please read the documentation in social_graph.module for proper method structure.");
      }
   }

   public function getContext($u = array()) {
      global $user;
      $p = profile2_load_by_user($user, 'main');
      $ua = array(
         'uid' => $user->uid,
         'email' => $user->mail,
         'fbid' => fboauth_fbid_load($user->uid),
         'cell' => $p->field_user_mobile[LANGUAGE_NONE][0]['value'],
      );

      $u = array_merge($ua, $u);
      $o = db_or();
      foreach ($u AS $key => $val) {
         $o->condition($key, $val);
      }

      $me = db_select('social_graph_users', 'u')
         ->fields('u')
         ->condition($o)
         ->execute();
      $mei = $me
         ->fetchAll();

      $this->me = reset($mei);
   }

   public function getFriends() {
      if (empty($this->me)) {
         throw new SocialGraphException('You must call getContext() before calling getFriends().');
      }

      $flist = db_select('social_graph_friends', 'f')
         ->condition('f.guid', $this->me->guid);
      $flist->leftJoin('social_graph_users', 'u', 'u.guid = f.friend_guid');
      $flist->fields('u');

      $fr = $flist->execute()->fetchAll();

      return $fr;
   }

   public function add_property($property, $value) {
      if (is_array($value) && count($value) == 1) {
         $value = reset($value);
      }

      // Check to see if the property exists by itself.
      $without = strtolower($property);
      if (property_exists($this, $without)) {
         $this->{$without} = $value;
      }
      // Otherwise, check to see if the property exists with underscores strategically placed next to UpperCase characters.
      else {
         $with = $property;
         // Replace the first character with an underscore character -- because we don't want to lead the property with an underscore!
         $with{0} = strtolower($with{0});
         // Replace uppercase characters with underscores, followed by the lowercase character.
         $with = strtolower(preg_replace('#[A-Z]#', '_\\0', $with));
         
         // Noooow try again...
         if (property_exists($this, $with)) {
            $this->{$with} = $value;
         }
         else {
            throw new SocialGraphException('Could not find property ' . $property);
         }
      }
   }

   private function _check_entities() {
      $errors = array(
         'int' => 'The following fields need to be numeric: !fields.  ',
         'string' => 'The following fields need to be a string: !fields.  ',
      );

      $missing = $oneof = array();
      $validators = $this->doc->getValidators();
      $table = $this->doc->getTable();
      $groups = $this->doc->getGroups();

      foreach ($table AS $entity => $fields) {
         foreach ($fields AS $field) {
            $error = 0;
            $f = $this->{$entity}->{$field['name']};
            if (isset($field['required']) && $field['required'] == 'true') {
               if (empty($f)) {
                  $missing[] = $field['name'];
                  $error++;
               }
            }

            if (!empty($f)) {
               switch ($field['type']) {
                  case 'integer':
                     if (intval($f) == 0) {
                        $malformed['int'][] = $field['name'];
                        $error++;
                     }
                  break;
                  case 'string':
                     if (!stval($f)) {
                        $malformed['string'][] = $field['name'];
                        $error++;
                     }
                  break;
               }
            }

            $v = '';
            if (isset($validators[$entity])) {
               $v = $validators[$entity][$field['name']];
               if (!empty($v)) {
                  if ($v['function']) {
                     if (!$v['function']($f)) {
                        $invalid[] = $field['name'] . ' (given "' . $f . '"; needs to pass "' . $v['function'] . '()" validation)';
                        $error++;
                     }
                  }

                  if ($v['regex']) {
                     if (!preg_match('#^' . $v['regex'] . '$#', $f)) {
                        $invalid[] = $field['name'] . ' (given "' . $f . '"; needs to match "' . $v['regex'] . '")';
                        $error++;
                     }
                  }
               }
            }

            if ($error == 0) {
               foreach ($groups AS $group => $fields) {
                  if (!empty($f) && isset($fields[$entity][$field['name']])) {
                     if (isset($groups[$group][$entity][$field['name']])) {
                        $groups[$group][$entity][$field['name']] = 1;
                     }
                  }
                  else {
                     if (isset($fields[$entity][$field['name']])) {
                        $oneof[$group][] = $field['name'] . ' (' . $entity . ')';
                     }
                  }
               }
            }
         }
      }

      if (!empty($missing)) {
         throw new SocialGraphException("Missing fields: " . implode(', ', $missing));
      }

      if (!empty($malformed)) {
         $elist = '';
         foreach ($malformed AS $type => $fields) {
            $elist .= t($errors["$type"], array('!fields' => implode(', ', $fields)));
         }

         throw new SocialGraphException($elist);
      }

      if (!empty($invalid)) {
         throw new SocialGraphException("Invalid fields: " . implode(', ', $invalid) . ".");
      }

      if (!empty($oneof)) {
         $m = '';
         $ec = 0;
         foreach ($oneof AS $e => $missing) {

            $total = count(dosomething_general_array_vals_multi($groups[$e]));  
            if (count($oneof[$e]) == $total) {
               if ($ec == 0) {
                  $m .= ' one of: ';
               }
               else {
                  $m .= ', and one of: ';
               }

               $m .= implode(', ', $oneof[$e]);
               $ec++;
            }
         }
         
         if ($ec > 0) {
            throw new SocialGraphException('You must have at least' . $m);
         }
      }
   }

   public function createGraphUser() {
      $this->_check_entities();

      $fields = $this->_get_table_structure();
      $fields += array(
         'created' => REQUEST_TIME,
         'ipaddress' => $_SERVER['REMOTE_ADDR'],
         'inviter_guid' => 0,
         'extra' => '',
      );

      try {
         drupal_write_record('social_graph_users', $fields);
      }
      catch (Exception $e) {
         watchdog('social_graph', 'There was an error creating a new social graph user: ' . $e->getMessage());
      }
   }

   public function _get_table_structure() {
      $table = $this->doc->getTable();
      $return = array();

      foreach ($table AS $entity => $fields) {
         foreach ($fields AS $field => $info) {
            $return[$field] = $this->{$entity}->{$field};
         }
      }
      
      return $return;
   }

   public function updateGraphUser() {
      $this->_check_entities();

      try {
         $condition = db_or();
         $condition->condition('uid', $this->user->uid);
         $condition->condition('email', $this->email->email);
         $condition->condition('fbid', $this->facebook->fbid);
         $condition->condition('cell', $this->mobile->cell);

         $fields = $this->_get_table_structure();

         db_update('social_graph_users')
         ->fields($fields)
         ->condition($condition)
         ->execute();
      }
      catch (Exception $e) {
         watchdog('social_graph', t('There was an error updating the social graph user: ' . $e->getMessage()));
      }
   }
}

abstract class SocialGraphService extends SocialGraph {
   abstract public function add($id);
   abstract public function update($id);
   abstract public function delete($id);
}

class SocialGraphException extends \Exception {}
