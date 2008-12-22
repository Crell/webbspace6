<?php

$view = new stdClass();
  $view->name = 'og_notes';
  $view->description = 'A list of posts on a given og/board';
  $view->access = array (
);
  $view->view_args_php = '';
  $view->page = TRUE;
  $view->page_title = 'Notes';
  $view->page_header = '';
  $view->page_header_format = '1';
  $view->page_footer = '';
  $view->page_footer_format = '1';
  $view->page_empty = '';
  $view->page_empty_format = '1';
  $view->page_type = 'list';
  $view->url = 'node/$arg/notes';
  $view->use_pager = FALSE;
  $view->nodes_per_page = '0';
  $view->sort = array (
    array (
      'tablename' => 'webb_note_lookup',
      'field' => 'created_lookup',
      'sortorder' => 'ASC',
      'options' => 'normal',
    ),
  );
  $view->argument = array (
    array (
      'type' => 'gid_lookup',
      'argdefault' => '7',
      'title' => '',
      'options' => '',
      'wildcard' => '',
      'wildcard_substitution' => '',
    ),
    array (
      'type' => 'rss_feed',
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
      'label' => '',
      'handler' => 'views_handler_field_nodelink_with_mark',
      'options' => 'link',
    ),
    array (
      'tablename' => 'node',
      'field' => 'created',
      'label' => '',
      'handler' => 'views_handler_field_date_small',
    ),
    array (
      'tablename' => 'node_data_field_character_name',
      'field' => 'field_character_name_value',
      'label' => '',
      'handler' => 'content_views_field_handler_group',
      'options' => 'default',
    ),
    array (
      'tablename' => 'node_data_field_parent_note',
      'field' => 'field_parent_note_nid',
      'label' => '',
      'handler' => 'content_views_field_handler_group',
      'options' => 'default',
    ),
    array (
      'tablename' => 'node',
      'field' => 'nid',
      'label' => '',
    ),
    array (
      'tablename' => 'webbtopic_topic',
      'field' => 'topic',
      'label' => '',
    ),
  );
  $view->filter = array (
    array (
      'tablename' => 'webb_note_lookup',
      'field' => 'created',
      'operator' => '>=',
      'options' => '-604800',
      'value' => 'now',
    ),
    array (
      'tablename' => 'webbtopic_topic',
      'field' => 'topic',
      'operator' => 'contains',
      'options' => '',
      'value' => '',
    ),
  );
  $view->exposed_filter = array (
    array (
      'tablename' => 'webbtopic_topic',
      'field' => 'topic',
      'label' => 'In topic',
      'optional' => '1',
      'is_default' => '1',
      'operator' => '1',
      'single' => '1',
    ),
    array (
      'tablename' => 'webb_note_lookup',
      'field' => 'created',
      'label' => 'Posted in the last',
      'optional' => '1',
      'is_default' => '1',
      'operator' => '1',
      'single' => '1',
    ),
  );
  $view->requires = array(webb_note_lookup, node, node_data_field_character_name, node_data_field_parent_note, webbtopic_topic);
  $views[$view->name] = $view;
