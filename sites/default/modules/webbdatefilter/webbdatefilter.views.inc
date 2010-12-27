<?php

/**
 * Implementation of hook_views_data().
 */
function webbdatefilter_views_data() {
  $tables = module_invoke_all('date_api_tables');

  foreach ($tables as $base_table) {
    // The date range filter.
    $data[$base_table]['webbdatefilter'] = array(
      'group' => t('WeBB'),
      'title' => t('WeBB Date range filter (!base_table)', array('!base_table' => $base_table)),
      'help' => t('Filter any Views !base_table date field with range options.', array('!base_table' => $base_table)),
      'filter' => array(
        'handler' => 'webbdatefilter_filter_date',
        'empty name field' => t('Undated'),
        'base' => $base_table,
      ),
    );
  }
  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function webbdatefilter_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'webbdatefilter'),
    ),
    'handlers' => array(
      'webbdatefilter_filter_date' => array(
        'parent' => 'views_handler_filter_date',
      ),
    ),
  );
}

