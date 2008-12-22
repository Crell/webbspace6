<?php

  $view = new stdClass();
  $view->name = 'user_characters';
  $view->description = 'A list of characters owned by a specified user';
  $view->access = array (
);
  $view->view_args_php = '';
  $view->page = TRUE;
  $view->page_title = 'Characters';
  $view->page_header = '';
  $view->page_header_format = '1';
  $view->page_footer = '';
  $view->page_footer_format = '1';
  $view->page_empty = '';
  $view->page_empty_format = '1';
  $view->page_type = 'table';
  $view->url = 'views/user_characters';
  $view->use_pager = FALSE;
  $view->nodes_per_page = '0';
  $view->sort = array (
    array (
      'tablename' => 'node',
      'field' => 'title',
      'sortorder' => 'ASC',
      'options' => '',
    ),
  );
  $view->argument = array (
    array (
      'type' => 'uid',
      'argdefault' => '1',
      'title' => '',
      'options' => '',
      'wildcard' => '',
      'wildcard_substitution' => '',
    ),
  );
  $view->field = array (
    array (
      'tablename' => 'node',
      'field' => 'title',
      'label' => 'Character',
      'handler' => 'views_handler_field_nodelink',
      'sortable' => '1',
      'options' => 'link',
    ),
    array (
      'tablename' => 'og_node_data',
      'field' => 'title',
      'label' => 'Board',
    ),
    array (
      'tablename' => 'node_data_field_rank',
      'field' => 'field_rank_tid',
      'label' => 'Rank',
      'handler' => 'content_views_field_handler_group',
      'options' => 'default',
    ),
    array (
      'tablename' => 'node_data_field_position_label',
      'field' => 'field_position_label_value',
      'label' => 'Position',
      'handler' => 'content_views_field_handler_group',
      'sortable' => '1',
      'options' => 'default',
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
  );
  $view->exposed_filter = array (
  );
  $view->requires = array(node, og_node_data, node_data_field_rank, node_data_field_position_label);
  $views[$view->name] = $view;
