<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function atrium_activity_plus_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'book_node';
  $context->description = '';
  $context->tag = 'Book';
  $context->conditions = array(
    'bookroot' => array(
      'values' => array(
        'book' => 'book',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-activity_plus_listing-block_4' => array(
          'module' => 'views',
          'delta' => 'activity_plus_listing-block_4',
          'region' => 'content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Book');

  $export['book_node'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'casetracker_node';
  $context->description = '';
  $context->tag = 'Casetracker';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'casetracker_basic_case' => 'casetracker_basic_case',
        'casetracker_basic_project' => 'casetracker_basic_project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-activity_plus_listing-block_1' => array(
          'module' => 'views',
          'delta' => 'activity_plus_listing-block_1',
          'region' => 'content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Casetracker');

  $export['casetracker_node'] = $context;
  return $export;
}
