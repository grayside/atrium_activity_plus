<?php
// $Id$

/**
 * @file
 *  Define Views handlers for use by Atrium Activity Plus module.
 */

/**
 * Implementation of hook_views_data().
 */
function atrium_activity_plus_views_data() {
  $data['casetracker_case']['node_pid'] = array(
    'title' => t('Project from Case'),
    'real field' => 'pid',
    'argument' => array(
      'handler' => 'atrium_activity_plus_views_handler_argument_node_pid',
      'help' => t('Filter Case Tracker activity by project as identified from the current node.'),
    ),
  );
  $data['book']['node_bid'] = array(
    'title' => t('Book from Page'),
    'real field' => 'bid',
    'argument' => array(
      'handler' => 'atrium_activity_plus_views_handler_argument_node_bid',
      'help' => t('Filter Book activity per book as identified by the current node.'),
    ),
  );
  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function atrium_activity_plus_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'atrium_activity_plus') . '/includes',
    ),
    'handlers' => array(
      'atrium_activity_plus_views_handler_argument_node_pid' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
      'atrium_activity_plus_views_handler_argument_node_bid' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
    ),
  );
}