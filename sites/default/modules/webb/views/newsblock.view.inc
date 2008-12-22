<?php

  $view = new stdClass();
  $view->name = 'newsblock';
  $view->description = 'Latest news items';
  $view->access = array (
);
  $view->view_args_php = '';
  $view->page = FALSE;
  $view->page_title = 'Latest news';
  $view->page_header = '';
  $view->page_header_format = '6';
  $view->page_footer = '';
  $view->page_footer_format = '6';
  $view->page_empty = '';
  $view->page_empty_format = '6';
  $view->page_type = 'teaser';
  $view->url = 'news';
  $view->use_pager = TRUE;
  $view->nodes_per_page = '5';
  $view->block = TRUE;
  $view->block_title = 'Latest news';
  $view->block_header = '';
  $view->block_header_format = '6';
  $view->block_footer = '';
  $view->block_footer_format = '6';
  $view->block_empty = '';
  $view->block_empty_format = '6';
  $view->block_type = 'list';
  $view->nodes_per_block = '5';
  $view->block_more = FALSE;
  $view->block_use_page_header = FALSE;
  $view->block_use_page_footer = FALSE;
  $view->block_use_page_empty = FALSE;
  $view->sort = array (
    array (
      'tablename' => 'node',
      'field' => 'created',
      'sortorder' => 'DESC',
      'options' => 'normal',
    ),
  );
  $view->argument = array (
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
      'tablename' => 'term_node_10',
      'field' => 'name',
      'label' => '',
      'options' => 'nolink',
    ),
  );
  $view->filter = array (
    array (
      'tablename' => 'node',
      'field' => 'type',
      'operator' => 'OR',
      'options' => '',
      'value' => array (
  0 => 'news',
),
    ),
  );
  $view->exposed_filter = array (
  );
  $view->requires = array(node, term_node_10);
  $views[$view->name] = $view;
