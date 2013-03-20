<?php

class DocHelper extends SocialGraph {
	private $validators = array();
	private $table = array();
	private $groups = array();

	public function __construct() {}

	private function _parse_vars($doc) {
		preg_match_all('#([A-Za-z0-9]+)\=(?:\'|")(.*?)(?:\'|")(?:\,|\))#', $doc, $vars);	
		$v = array();
		if (!empty($vars[1]) && !empty($vars[2])) {
	        $v = array_combine($vars[1], $vars[2]);
	    }

		return $v;
	}

	protected function column($class, $property, $notations) {
      $v = $this->_parse_vars($notations);
      $this->table[$class][$v['name']] = $v;

      if (isset($v['required']) && $v['required'] == 'true') {
         $this->required[] = $v['name'];
      }
	}

	protected function validate($class, $property, $doc) {
	  $alidators = $this->_parse_vars($doc);

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

	protected function getTable() {
	   return $this->table;
	}

	protected function getValidators() {
	   return $this->validators;
	}

	protected function getGroups() {
	   return $this->groups;
	}
}

?>