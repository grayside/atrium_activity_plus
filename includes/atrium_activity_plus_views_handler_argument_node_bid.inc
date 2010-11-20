<?php
// $Id$

class atrium_activity_plus_views_handler_argument_node_bid extends views_handler_argument_numeric {
  function query() {
    if (count($this->value) > 1) {
      foreach ($this->value as $key => $arg) {
        $this->value[$key] = $this->get_book_bid($arg);
      }
      $this->value = array_unique($this->value);
    }
    else {
      $this->argument = $this->get_book_bid($this->argument);
    }
    parent::query();
  }

  /**
   * Helper function to identify pids from cases.
   */
  function get_book_bid($nid) {
    $node = node_load($nid);
    if (book_type_is_allowed($node->type)) {
      return $node->book['bid'];
    }
    return $nid;
  }
}