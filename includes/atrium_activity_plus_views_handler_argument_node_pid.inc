<?php
// $Id$

class atrium_activity_plus_views_handler_argument_node_pid extends views_handler_argument_numeric {
  function query() {
    if (count($this->value) > 1) {
      foreach ($this->value as $key => $arg) {
        $this->value[$key] = $this->get_casetracker_pid($arg);
      }
      $this->value = array_unique($this->value);
    }
    else {
      $this->argument = $this->get_casetracker_pid($this->argument);
    }
    parent::query();
  }

  /**
   * Helper function to identify pids from cases.
   */
  function get_casetracker_pid($nid) {
    $node = node_load($nid);
    if (casetracker_is_case($node->type)) {
      return $node->casetracker->pid;
    }
    return $nid;
  }
}