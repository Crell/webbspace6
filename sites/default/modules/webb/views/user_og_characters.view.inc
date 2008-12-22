<?php

  $view = new stdClass();
  $view->name = 'user_og_characters';
  $view->description = 'A list of characters owned by the current user in the current OG';
  $view->access = array (
);
  $view->view_args_php = '';
  $view->page = TRUE;
  $view->page_title = '';
  $view->page_header = '';
  $view->page_header_format = '1';
  $view->page_footer = '';
  $view->page_footer_format = '1';
  $view->page_empty = '';
  $view->page_empty_format = '1';
  $view->page_type = 'list';
  $view->url = 'og/character/my';
  $view->use_pager = FALSE;
  $view->nodes_per_page = '0';
  $view->sort = array (
  );
  $view->argument = array (
  );
  $view->field = array (
    array (
      'tablename' => 'node_data_field_position_label',
      'field' => 'field_position_label_value',
      'label' => '',
      'handler' => 'content_views_field_handler_group',
      'options' => 'plain',
    ),
  );
  $view->filter = array (
    array (
      'tablename' => 'node',
      'field' => 'status',
      'operator' => '=',
      'options' => '',
      'value' => '1',
    ),
    array (
      'tablename' => 'node',
      'field' => 'type',
      'operator' => 'OR',
      'options' => '',
      'value' => array (
  0 => 'character',
),
    ),
    array (
      'tablename' => 'node',
      'field' => 'currentuid',
      'operator' => '=',
      'options' => '',
      'value' => '***CURRENT_USER***',
    ),
  );
  $view->exposed_filter = array (
  );
  $view->requires = array(node_data_field_position_label, node);
  $views[$view->name] = $view;
