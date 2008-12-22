<?php

  $view = new stdClass();
  $view->name = 'og_characters_complete';
  $view->description = 'A complete list of characters on a given og';
  $view->access = array (
  0 => '2',
);
  $view->view_args_php = '';
  $view->page = TRUE;
  $view->page_title = 'All Characters';
  $view->page_header = '';
  $view->page_header_format = '1';
  $view->page_footer = '';
  $view->page_footer_format = '1';
  $view->page_empty = '';
  $view->page_empty_format = '1';
  $view->page_type = 'table';
  $view->url = 'views/characters_complete';
  $view->use_pager = FALSE;
  $view->nodes_per_page = '0';
  $view->sort = array (
  );
  $view->argument = array (
    array (
      'type' => 'gid',
      'argdefault' => '2',
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
      'tablename' => 'node_data_field_rank',
      'field' => 'field_rank_tid',
      'label' => 'Rank',
      'handler' => 'content_views_field_handler_group',
      'options' => 'default',
    ),
    array (
      'tablename' => 'users',
      'field' => 'name',
      'label' => 'User',
      'sortable' => '1',
    ),
    array (
      'tablename' => 'node_data_field_position_label',
      'field' => 'field_position_label_value',
      'label' => 'Position',
      'handler' => 'content_views_field_handler_group',
      'sortable' => '1',
      'options' => 'default',
    ),
    array (
      'tablename' => 'node_data_field_sortorder',
      'field' => 'field_sortorder_value',
      'label' => 'Sort order',
      'handler' => 'content_views_field_handler_group',
      'sortable' => '1',
      'defaultsort' => 'ASC',
      'options' => 'default',
    ),
    array (
      'tablename' => 'node_data_field_rostered',
      'field' => 'field_rostered_value',
      'label' => 'Rostered',
      'handler' => 'content_views_field_handler_group',
      'sortable' => '1',
      'options' => 'default',
    ),
    array (
      'tablename' => 'node',
      'field' => 'edit',
      'label' => 'Edit',
      'handler' => 'views_handler_node_edit_destination',
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
      'tablename' => 'node_data_field_rostered',
      'field' => 'field_rostered_value_default',
      'operator' => 'OR',
      'options' => '',
      'value' => array (
  0 => 'Unrostered',
  1 => 'Rostered',
),
    ),
  );
  $view->exposed_filter = array (
    array (
      'tablename' => 'node_data_field_rostered',
      'field' => 'field_rostered_value_default',
      'label' => 'Rostered',
      'optional' => '1',
      'is_default' => '0',
      'operator' => '1',
      'single' => '1',
    ),
  );
  $view->requires = array(node, node_data_field_rank, users, node_data_field_position_label, node_data_field_sortorder, node_data_field_rostered);
  $views[$view->name] = $view;
