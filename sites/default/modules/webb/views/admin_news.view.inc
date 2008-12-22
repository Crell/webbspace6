<?php

  $view = new stdClass();
  $view->name = 'admin_news';
  $view->description = 'Latest news items';
  $view->access = array (
  0 => '3',
);
  $view->view_args_php = '';
  $view->page = TRUE;
  $view->page_title = 'Latest news';
  $view->page_header = '';
  $view->page_header_format = '6';
  $view->page_footer = '';
  $view->page_footer_format = '6';
  $view->page_empty = 'There are no news postings matching your search.';
  $view->page_empty_format = '6';
  $view->page_type = 'table';
  $view->url = 'admin/content/news';
  $view->use_pager = TRUE;
  $view->nodes_per_page = '20';
  $view->menu = TRUE;
  $view->menu_title = 'News';
  $view->menu_tab = FALSE;
  $view->menu_tab_weight = '0';
  $view->menu_tab_default = FALSE;
  $view->menu_tab_default_parent = NULL;
  $view->menu_tab_default_parent_type = 'tab';
  $view->menu_parent_tab_weight = '0';
  $view->menu_parent_title = '';
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
      'label' => 'Title',
      'handler' => 'views_handler_field_nodelink_with_mark',
      'options' => 'link',
    ),
    array (
      'tablename' => 'term_node_10',
      'field' => 'name',
      'label' => 'Category',
      'options' => 'link',
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
    array (
      'tablename' => 'term_node_10',
      'field' => 'tid',
      'operator' => 'OR',
      'options' => '',
      'value' => array (
),
    ),
  );
  $view->exposed_filter = array (
    array (
      'tablename' => 'node',
      'field' => 'promote',
      'label' => 'Promoted',
      'optional' => '1',
      'is_default' => '0',
      'operator' => '1',
      'single' => '1',
    ),
    array (
      'tablename' => 'term_node_10',
      'field' => 'tid',
      'label' => 'Category',
      'optional' => '1',
      'is_default' => '0',
      'operator' => '1',
      'single' => '1',
    ),
  );
  $view->requires = array(node, term_node_10);
  $views[$view->name] = $view;
