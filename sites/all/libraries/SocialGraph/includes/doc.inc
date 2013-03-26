<?php

namespace SocialGraph\Helper;
use SocialGraph\SocialGraph;

class DocHelper extends SocialGraph {
	private $validators = array();
	private $table = array();
	private $groups = array();
	private $map = array();
	private $containers = array();

	private $parent;

	public function __construct($e) {
	  $this->parent = $e;
	}

	private function _parse_vars($doc) {
		preg_match_all('#([A-Za-z0-9]+)\=(?:\'|")(.*?)(?:\'|")(?:\,|\))#', $doc, $vars);	
		$v = array();
		if (!empty($vars[1]) && !empty($vars[2])) {
	        $v = array_combine($vars[1], $vars[2]);
	    }

		return $v;
	}

	protected function column($class, $property, $notations, $group) {
      $v = $this->_parse_vars($notations);
      if (!empty($group)) {
      	$this->table[$class][(isset($group['prop']) ? $group['prop'] : '')][$v['name']] = $v;
      }
      else {
	    $this->table[$class][$v['name']] = $v;
	  }

      if (isset($v['required']) && $v['required'] == 'true') {
         $this->required[] = $v['name'];
      }
	}

	protected function validate($class, $property, $doc) {
	  $validators = $this->_parse_vars($doc);

      if (!empty($validators['function'])) {
      	if (function_exists($validators['function'])) {
      	   $this->validators[$class][$property]['function'] = $validators['function'];
      	}
      }

      if (!empty($validators['regex'])) {
      	$this->validators[$class][$property]['regex'] = $validators['regex'];
      }
	}

	protected function oneingroup($class, $property, $group) {
		$group = str_replace(array('"', "'"), '', $group);
		$this->groups[$group][$class][$property] = 0;
	}

  protected function contains($class, $property, $group) {
    $group = str_replace(array('"', "'"), '', $group);
    $this->containers[$class][$property] = $group;

    $path = strtolower(preg_replace('#^\/[^\/]+\/#', '', str_replace('\\', '/', $group)));
    require_once __DIR__ . '/../' . $path . '.inc';

    $this->table[$class][$property] = array();
    $this->map[$class][$property] = new $group;

    $reflector = new \ReflectionClass($this->map[$class][$property]);
    $c = $reflector->getProperties();
    foreach ($c AS $key => $prop) {
      $p = $prop->getDocComment();
      $this->parent->_build_column_info($class, $prop->name, $p, array('prop' => $property));
    }
  }

  protected function getTable() {
    return $this->table;
  }

  protected function getValidators() {
    return $this->validators;
  }

  protected function getGroups() {
    return $this->groups;
  }

  protected function getContainers() {
  	return $this->containers;
  }

  protected function getMap() {
  	return $this->map;
  }
}

?>