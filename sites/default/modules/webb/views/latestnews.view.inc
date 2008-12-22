<?php

  $view = new stdClass();
  $view->name = 'latestnews';
  $view->description = 'Latest news items';
  $view->access = array (
);
  $view->view_args_php = '';
  $view->page = TRUE;
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
    array (
      'tablename' => 'node',
      'field' => 'promote',
      'operator' => '=',
      'options' => '',
      'value' => '1',
    ),
  );
  $view->exposed_filter = array (
  );
  $view->requires = array(node);
  $views[$view->name] = $view;
