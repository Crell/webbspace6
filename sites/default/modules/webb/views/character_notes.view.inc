<?php

  $view = new stdClass();
  $view->name = 'character_notes';
  $view->description = 'Recent notes posted by a character';
  $view->access = array (
);
  $view->view_args_php = '';
  $view->page = TRUE;
  $view->page_title = 'Recent posts';
  $view->page_header = '';
  $view->page_header_format = '6';
  $view->page_footer = '';
  $view->page_footer_format = '6';
  $view->page_empty = '';
  $view->page_empty_format = '6';
  $view->page_type = 'table';
  $view->url = 'node/$arg/posts';
  $view->use_pager = TRUE;
  $view->nodes_per_page = '20';
  $view->sort = array (
    array (
      'tablename' => 'node',
      'field' => 'created',
      'sortorder' => 'DESC',
      'options' => 'normal',
    ),
  );
  $view->argument = array (
    array (
      'type' => 'content: field_character',
      'argdefault' => '1',
      'title' => '',
      'options' => '',
      'wildcard' => '',
      'wildcard_substitution' => '',
    ),
  );
  $view->field = array (
    array (
      'tablename' => 'webbtopic_topic',
      'field' => 'topic',
      'label' => 'Location',
    ),
    array (
      'tablename' => 'og_node_data',
      'field' => 'title',
      'label' => 'Board',
    ),
    array (
      'tablename' => 'node',
      'field' => 'created',
      'label' => 'When',
      'handler' => 'views_handler_field_since',
    ),
    array (
      'tablename' => 'node',
      'field' => 'view',
      'label' => 'View',
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
  0 => 'note',
),
    ),
  );
  $view->exposed_filter = array (
  );
  $view->requires = array(node, webbtopic_topic, og_node_data);
  $views[$view->name] = $view;
