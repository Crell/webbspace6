<?php

  $view = new stdClass();
  $view->name = 'og_ghp_characters';
  $view->description = 'A roster of characters on an og';
  $view->access = array (
  0 => '2',
);
  $view->view_args_php = '';
  $view->page = TRUE;
  $view->page_title = 'Roster';
  $view->page_header = '';
  $view->page_header_format = '1';
  $view->page_footer = '';
  $view->page_footer_format = '1';
  $view->page_empty = '';
  $view->page_empty_format = '1';
  $view->page_type = 'table';
  $view->url = 'board/$arg/characters';
  $view->use_pager = FALSE;
  $view->nodes_per_page = '0';
  $view->sort = array (
    array (
      'tablename' => 'node_data_field_sortorder',
      'field' => 'field_sortorder_value',
      'sortorder' => 'ASC',
      'options' => '',
    ),
    array (
      'tablename' => 'node',
      'field' => 'title',
      'sortorder' => 'ASC',
      'options' => '',
    ),
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
      'tablename' => 'node_data_field_rank',
      'field' => 'field_rank_tid',
      'label' => 'Rank',
      'handler' => 'content_views_field_handler_group',
      'options' => 'default',
    ),
    array (
      'tablename' => 'node',
      'field' => 'title',
      'label' => 'Character',
      'handler' => 'views_handler_field_nodelink',
      'options' => 'link',
    ),
    array (
      'tablename' => 'node_data_field_position_label',
      'field' => 'field_position_label_value',
      'label' => 'Position',
      'handler' => 'content_views_field_handler_group',
      'options' => 'plain',
    ),
    array (
      'tablename' => 'node_data_field_species',
      'field' => 'field_species_value',
      'label' => 'Species',
      'handler' => 'content_views_field_handler_group',
      'options' => 'default',
    ),
    array (
      'tablename' => 'node_data_field_character_height',
      'field' => 'field_character_height_value',
      'label' => 'Height',
      'handler' => 'content_views_field_handler_group',
      'options' => 'default',
    ),
    array (
      'tablename' => 'node_data_field_weight',
      'field' => 'field_weight_value',
      'label' => 'Weight',
      'handler' => 'content_views_field_handler_group',
      'options' => 'default',
    ),
    array (
      'tablename' => 'users',
      'field' => 'name',
      'label' => 'User',
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
  0 => 'Rostered',
),
    ),
  );
  $view->exposed_filter = array (
  );
  $view->requires = array(node_data_field_sortorder, node, node_data_field_rank, node_data_field_position_label, node_data_field_species, node_data_field_character_height, node_data_field_weight, users, node_data_field_rostered);
  $views[$view->name] = $view;
