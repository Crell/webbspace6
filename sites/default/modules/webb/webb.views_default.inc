<?php
/**
 *
 * Implementation of hook_views_default_views().
 */
function webb_views_default_views() {
  /*
   * View 'character_posts'
   */
  $view = new view;
  $view->name = 'character_posts';
  $view->description = 'A list of posts by a given character.';
  $view->tag = 'webb';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Post',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'created' => array(
      'label' => 'Posted',
      'date_format' => 'time ago',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'field_character_nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'node',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'field_character_nid',
      'table' => 'node_data_field_character',
      'field' => 'field_character_nid',
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'webform' => 0,
        'character' => 0,
        'board' => 0,
        'fleet' => 0,
        'logentry' => 0,
        'news' => 0,
        'note' => 0,
        'page' => 0,
        'position' => 0,
        'rank' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '10' => 0,
        '11' => 0,
        '12' => 0,
        '15' => 0,
        '13' => 0,
        '14' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'note' => 'note',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Recent posts');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 1,
    'order' => 'asc',
    'columns' => array(
      'title' => 'title',
      'group_nid' => 'group_nid',
      'created' => 'created',
    ),
    'info' => array(
      'title' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'group_nid' => array(
        'separator' => '',
      ),
      'created' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('node_content', 'Node content', 'node_content_1');
  $handler->override_option('types', array(
    'character' => 'character',
  ));
  $handler->override_option('modes', array(
    '0' => 'full',
  ));
  $handler->override_option('default_argument', 'nid');
  $views[$view->name] = $view;

  /*
   * View 'og_colog'
   */
  $view = new view;
  $view->name = 'og_colog';
  $view->description = 'A list of Log entries on a given OG.';
  $view->tag = 'webb';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'CO Log', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'timestamp' => array(
      'label' => '',
      'link_to_node' => 0,
      'comments' => 0,
      'exclude' => 0,
      'id' => 'timestamp',
      'table' => 'history_user',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
    'created' => array(
      'label' => 'Post date',
      'date_format' => 'medium',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'group_nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => 'Notes on %1',
      'default_argument_type' => 'node',
      'default_argument' => '',
      'validate_type' => 'og_group_types',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'webform' => 0,
        'character' => 0,
        'board' => 0,
        'fleet' => 0,
        'logentry' => 0,
        'news' => 0,
        'note' => 0,
        'page' => 0,
        'position' => 0,
        'rank' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '10' => 0,
        '11' => 0,
        '12' => 0,
        '15' => 0,
        '13' => 0,
        '14' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'status_extra' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_extra',
      'table' => 'node',
      'field' => 'status_extra',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'logentry' => 'logentry',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'read notes',
  ));
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_options', NULL);
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'teaser' => 1,
    'links' => 0,
    'comments' => 0,
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'node/%/log');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'CO Log',
    'description' => '',
    'weight' => '4',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $views[$view->name] = $view;

  /*
   * View 'og_ghp_null'
   */
  $view = new view;
  $view->name = 'og_ghp_null';
  $view->description = 'A view guaranteed to return nothing to work around a moronic design flaw in OG that requires a view.';
  $view->tag = 'webb';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('arguments', array(
    'group_nid' => array(
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(
        'count' => TRUE,
        'override' => FALSE,
        'items_per_page' => 25,
      ),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '%1',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'og_group_types',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'add_table' => 0,
      'relationship' => 'none',
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'poll' => 0,
        'book' => 0,
        'group1' => 0,
        'group2' => 0,
        'page' => 0,
        'story' => 0,
      ),
      'validate_argument_php' => '',
      'require_value' => 0,
      'reduce_duplicates' => 0,
      'default_argument_user' => 0,
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
      ),
      'validate_argument_type' => 'tid',
      'not' => 0,
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'operator' => '=',
      'value' => 1,
      'group' => 0,
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'relationship' => 'none',
      'expose_button' => array(
        'button' => 'Expose',
      ),
    ),
    'status_1' => array(
      'operator' => '=',
      'value' => '0',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_1',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 1);
  $handler->override_option('use_pager', '0');
  $handler->override_option('distinct', 0);
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'teaser' => 1,
    'links' => 1,
  ));
  $views[$view->name] = $view;

  /*
   * View 'og_notes'
   */
  $view = new view;
  $view->name = 'og_notes';
  $view->description = 'A list of notes on a given OG.';
  $view->tag = 'webb';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Notes', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'timestamp' => array(
      'label' => '',
      'link_to_node' => 0,
      'comments' => 0,
      'exclude' => 0,
      'id' => 'timestamp',
      'table' => 'history_user',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
    'field_character_name_value' => array(
      'label' => '',
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_character_name_value',
      'table' => 'node_data_field_character_name',
      'field' => 'field_character_name_value',
      'relationship' => 'none',
    ),
    'created' => array(
      'label' => '',
      'date_format' => 'medium',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'field_parent_note_nid' => array(
      'label' => '',
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 1,
      'id' => 'field_parent_note_nid',
      'table' => 'node_data_field_parent_note',
      'field' => 'field_parent_note_nid',
      'relationship' => 'none',
    ),
    'nid' => array(
      'label' => '',
      'link_to_node' => 0,
      'exclude' => 1,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'group_nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => 'Notes on %1',
      'default_argument_type' => 'node',
      'default_argument' => '',
      'validate_type' => 'og_group_types',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'webform' => 0,
        'character' => 0,
        'board' => 0,
        'fleet' => 0,
        'logentry' => 0,
        'news' => 0,
        'note' => 0,
        'page' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '10' => 0,
        '11' => 0,
        '12' => 0,
        '6' => 0,
        '13' => 0,
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'created' => array(
      'operator' => '>=',
      'value' => array(
        'type' => 'offset',
        'value' => '- 12 weeks',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'note' => 'note',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'read notes',
  ));
  $handler->override_option('title', 'Notes');
  $handler->override_option('items_per_page', 20);
  $handler->override_option('style_plugin', 'tree');
  $handler->override_option('style_options', array(
    'type' => 'ul',
    'main_field' => 'nid',
    'parent_field' => 'field_parent_note_nid',
  ));
  $handler->override_option('row_options', array(
    'inline' => array(
      'title' => 'title',
      'timestamp' => 'timestamp',
    ),
    'separator' => '',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'node/%/notes');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'Notes',
    'description' => '',
    'weight' => '2',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $views[$view->name] = $view;

  /*
   * View 'og_roster'
   */
  $view = new view;
  $view->name = 'og_roster';
  $view->description = 'A roster of characters on a given Group.';
  $view->tag = 'webb';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_positionref_nid' => array(
      'label' => 'Position',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_positionref_nid',
      'table' => 'node_data_field_positionref',
      'field' => 'field_positionref_nid',
      'relationship' => 'none',
    ),
    'field_rankref_nid' => array(
      'label' => 'Rank',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_rankref_nid',
      'table' => 'node_data_field_rankref',
      'field' => 'field_rankref_nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'title_1' => array(
      'label' => 'Rank',
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title_1',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'field_rankref_nid',
    ),
    'title' => array(
      'label' => 'Character',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'field_position_label_value' => array(
      'label' => 'Position',
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_position_label_value',
      'table' => 'node_data_field_position_label',
      'field' => 'field_position_label_value',
      'relationship' => 'none',
    ),
    'field_species_value' => array(
      'label' => 'Species',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_species_value',
      'table' => 'node_data_field_species',
      'field' => 'field_species_value',
      'relationship' => 'none',
    ),
    'field_character_height_value' => array(
      'label' => 'Height',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_character_height_value',
      'table' => 'node_data_field_character_height',
      'field' => 'field_character_height_value',
      'relationship' => 'none',
    ),
    'field_weight_value' => array(
      'label' => 'Weight',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_weight_value',
      'table' => 'node_data_field_weight',
      'field' => 'field_weight_value',
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => 'Member',
      'link_to_user' => 1,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'field_sortorder_value' => array(
      'order' => 'DESC',
      'delta' => -1,
      'id' => 'field_sortorder_value',
      'table' => 'node_data_field_sortorder',
      'field' => 'field_sortorder_value',
      'relationship' => 'field_rankref_nid',
    ),
    'field_sortorder_value_1' => array(
      'order' => 'DESC',
      'delta' => -1,
      'id' => 'field_sortorder_value_1',
      'table' => 'node_data_field_sortorder',
      'field' => 'field_sortorder_value',
      'relationship' => 'field_positionref_nid',
    ),
    'title' => array(
      'order' => 'ASC',
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'group_nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'node',
      'default_argument' => '',
      'validate_type' => 'og_group_types',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'webform' => 0,
        'character' => 0,
        'board' => 0,
        'fleet' => 0,
        'logentry' => 0,
        'news' => 0,
        'note' => 0,
        'page' => 0,
        'position' => 0,
        'rank' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '10' => 0,
        '11' => 0,
        '12' => 0,
        '15' => 0,
        '13' => 0,
        '14' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'character' => 'character',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'field_rostered_value_many_to_one' => array(
      'operator' => 'or',
      'value' => array(
        'Rostered' => 'Rostered',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_rostered_value_many_to_one',
      'table' => 'node_data_field_rostered',
      'field' => 'field_rostered_value_many_to_one',
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Roster');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('items_per_page', 0);
  $handler->override_option('use_pager', '0');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'title_1' => 'title_1',
      'title' => 'title',
      'field_position_label_value' => 'field_position_label_value',
      'field_species_value' => 'field_species_value',
      'name' => 'name',
      'title_2' => 'title_2',
    ),
    'info' => array(
      'title_1' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_position_label_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_species_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'title_2' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'Roster', 'page_1');
  $handler->override_option('path', 'views/roster');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler = $view->new_display('page', 'Admin Roster', 'page_2');
  $handler->override_option('fields', array(
    'title_1' => array(
      'label' => 'Rank',
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title_1',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'field_rankref_nid',
    ),
    'title' => array(
      'label' => 'Character',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'field_position_label_value' => array(
      'label' => 'Position',
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_position_label_value',
      'table' => 'node_data_field_position_label',
      'field' => 'field_position_label_value',
      'relationship' => 'none',
    ),
    'field_species_value' => array(
      'label' => 'Species',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_species_value',
      'table' => 'node_data_field_species',
      'field' => 'field_species_value',
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => 'Member',
      'link_to_user' => 1,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'field_rostered_value' => array(
      'label' => 'Rostered',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_rostered_value',
      'table' => 'node_data_field_rostered',
      'field' => 'field_rostered_value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'edit_node' => array(
      'label' => 'Edit',
      'text' => '',
      'exclude' => 0,
      'id' => 'edit_node',
      'table' => 'node',
      'field' => 'edit_node',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'character' => 'character',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'title_1' => 'title_1',
      'title' => 'title',
      'field_position_label_value' => 'field_position_label_value',
      'field_species_value' => 'field_species_value',
      'field_character_height_value' => 'field_character_height_value',
      'field_weight_value' => 'field_weight_value',
      'name' => 'name',
      'field_rostered_value' => 'field_rostered_value',
    ),
    'info' => array(
      'title_1' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_position_label_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_species_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_character_height_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_weight_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_rostered_value' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler->override_option('path', 'node/%/edit/adminroster');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'Full roster',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler = $view->new_display('page', 'Master Roster', 'page_3');
  $handler->override_option('relationships', array(
    'field_positionref_nid' => array(
      'label' => 'Position',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_positionref_nid',
      'table' => 'node_data_field_positionref',
      'field' => 'field_positionref_nid',
      'relationship' => 'none',
    ),
    'field_rankref_nid' => array(
      'label' => 'Rank',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_rankref_nid',
      'table' => 'node_data_field_rankref',
      'field' => 'field_rankref_nid',
      'relationship' => 'none',
    ),
    'group_nid' => array(
      'label' => 'Board',
      'required' => 0,
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'title_1' => array(
      'label' => 'Rank',
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title_1',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'field_rankref_nid',
    ),
    'title' => array(
      'label' => 'Character',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'field_position_label_value' => array(
      'label' => 'Position',
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_position_label_value',
      'table' => 'node_data_field_position_label',
      'field' => 'field_position_label_value',
      'relationship' => 'none',
    ),
    'field_species_value' => array(
      'label' => 'Species',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_species_value',
      'table' => 'node_data_field_species',
      'field' => 'field_species_value',
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => 'Member',
      'link_to_user' => 1,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'title_2' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 1,
      'id' => 'title_2',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'group_nid',
    ),
  ));
  $handler->override_option('sorts', array(
    'title' => array(
      'order' => 'ASC',
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'group_nid',
    ),
    'field_sortorder_value' => array(
      'order' => 'DESC',
      'delta' => -1,
      'id' => 'field_sortorder_value',
      'table' => 'node_data_field_sortorder',
      'field' => 'field_sortorder_value',
      'relationship' => 'field_rankref_nid',
    ),
    'field_sortorder_value_1' => array(
      'order' => 'DESC',
      'delta' => -1,
      'id' => 'field_sortorder_value_1',
      'table' => 'node_data_field_sortorder',
      'field' => 'field_sortorder_value',
      'relationship' => 'field_positionref_nid',
    ),
    'title_1' => array(
      'order' => 'ASC',
      'id' => 'title_1',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array());
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'character' => 'character',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'field_rostered_value_many_to_one' => array(
      'operator' => 'or',
      'value' => array(
        'Rostered' => 'Rostered',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_rostered_value_many_to_one',
      'table' => 'node_data_field_rostered',
      'field' => 'field_rostered_value_many_to_one',
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'status_1' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_1',
      'table' => 'node',
      'field' => 'status',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'group_nid',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      '3' => 3,
      '4' => 4,
    ),
  ));
  $handler->override_option('items_per_page', 100);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_options', array(
    'grouping' => 'title_2',
    'override' => 1,
    'sticky' => 1,
    'order' => 'asc',
    'columns' => array(
      'title_1' => 'title_1',
      'title' => 'title',
      'field_position_label_value' => 'field_position_label_value',
      'field_species_value' => 'field_species_value',
      'name' => 'name',
      'title_2' => 'title_2',
    ),
    'info' => array(
      'title_1' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_position_label_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_species_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'title_2' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler->override_option('path', 'master-roster');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler = $view->new_display('node_content', 'Board Roster', 'node_content_1');
  $handler->override_option('types', array(
    'board' => 'board',
  ));
  $handler->override_option('modes', array(
    '0' => 'full',
  ));
  $handler->override_option('default_argument', 'nid');
  $views[$view->name] = $view;

  /*
   * View 'og_subscribers'
   */
  $view = new view;
  $view->name = 'og_subscribers';
  $view->description = 'A list of subscribers on a given OG.';
  $view->tag = 'webb';
  $view->view_php = '';
  $view->base_table = 'users';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'nid' => array(
      'id' => 'nid',
      'table' => 'og_uid',
      'field' => 'nid',
      'label' => 'Group',
      'required' => 0,
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'name' => array(
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'label' => 'Name',
      'link_to_user' => 1,
      'relationship' => 'none',
    ),
    'access' => array(
      'label' => 'Last access',
      'date_format' => 'time ago',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'access',
      'table' => 'users',
      'field' => 'access',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'managelink' => array(
      'id' => 'managelink',
      'table' => 'og_uid',
      'field' => 'managelink',
      'label' => 'Manage',
      'relationship' => 'none',
    ),
    'managelinkadmin' => array(
      'id' => 'managelinkadmin',
      'table' => 'og_uid',
      'field' => 'managelinkadmin',
      'label' => 'Admin',
      'relationship' => 'none',
    ),
    'is_manager' => array(
      'id' => 'is_manager',
      'table' => 'og_uid',
      'field' => 'is_manager',
      'label' => '',
      'relationship' => 'none',
    ),
    'is_admin' => array(
      'id' => 'is_admin',
      'table' => 'og_uid',
      'field' => 'is_admin',
      'label' => '',
      'relationship' => 'none',
    ),
    'is_active' => array(
      'id' => 'is_active',
      'table' => 'og_uid',
      'field' => 'is_active',
      'label' => '',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'is_admin' => array(
      'id' => 'is_admin',
      'table' => 'og_uid',
      'field' => 'is_admin',
      'order' => 'DESC',
      'relationship' => 'none',
    ),
    'is_active' => array(
      'id' => 'is_active',
      'table' => 'og_uid',
      'field' => 'is_active',
      'order' => 'ASC',
      'relationship' => 'none',
    ),
    'name' => array(
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'order' => 'ASC',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'id' => 'nid',
      'table' => 'og_uid',
      'field' => 'nid',
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(
        'count' => TRUE,
        'override' => FALSE,
        'items_per_page' => 25,
      ),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => 'Members of %1',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'og_group_types',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'add_table' => 0,
      'relationship' => 'none',
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'poll' => 0,
        'book' => 0,
        'group1' => 0,
        'group2' => 0,
        'page' => 0,
        'story' => 0,
      ),
      'validate_argument_php' => '',
      'require_value' => 0,
      'reduce_duplicates' => 0,
      'default_argument_user' => 0,
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
      ),
      'validate_argument_type' => 'tid',
      'not' => 0,
      'validate_argument_is_member' => 1,
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'id' => 'status',
      'table' => 'users',
      'field' => 'status',
      'operator' => '=',
      'value' => 1,
      'group' => 0,
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'relationship' => 'none',
      'expose_button' => array(
        'button' => 'Expose',
      ),
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Subscribers');
  $handler->override_option('empty_format', '1');
  $handler->override_option('items_per_page', 90);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 1,
    'order' => 'asc',
    'columns' => array(
      'name' => 'name',
      'access' => 'access',
      'managelink' => 'managelink',
      'managelinkadmin' => 'managelinkadmin',
      'is_manager' => 'name',
      'is_admin' => 'name',
      'is_active' => 'name',
    ),
    'info' => array(
      'name' => array(
        'sortable' => 1,
        'separator' => '&nbsp;',
      ),
      'access' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'managelink' => array(
        'separator' => '',
      ),
      'managelinkadmin' => array(
        'separator' => '',
      ),
      'is_manager' => array(
        'separator' => '',
      ),
      'is_admin' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'is_active' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->override_option('path', 'node/%/edit/subscribers');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'Subscribers',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'normal',
    'title' => 'List',
    'description' => '',
    'weight' => '0',
  ));
  $views[$view->name] = $view;

  /*
   * View 'og_supported_positions'
   */
  $view = new view;
  $view->name = 'og_supported_positions';
  $view->description = 'A list of positions supported by a given OG.';
  $view->tag = 'webb';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'group_nid' => array(
      'label' => 'Group node (post)',
      'required' => 0,
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'field_sortorder_value' => array(
      'order' => 'ASC',
      'delta' => -1,
      'id' => 'field_sortorder_value',
      'table' => 'node_data_field_sortorder',
      'field' => 'field_sortorder_value',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'position' => 'position',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'tid' => array(
      'operator' => 'or',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'type' => 'textfield',
      'vid' => '15',
      'id' => 'tid',
      'table' => 'term_node',
      'field' => 'tid',
      'relationship' => 'group_nid',
      'hierarchy' => 0,
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 0);
  $views[$view->name] = $view;

  /*
   * View 'og_supported_ranks'
   */
  $view = new view;
  $view->name = 'og_supported_ranks';
  $view->description = 'A list of ranks supported by a given OG.';
  $view->tag = 'webb';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'group_nid' => array(
      'label' => 'Group node (post)',
      'required' => 0,
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'field_sortorder_value' => array(
      'order' => 'ASC',
      'delta' => -1,
      'id' => 'field_sortorder_value',
      'table' => 'node_data_field_sortorder',
      'field' => 'field_sortorder_value',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'rank' => 'rank',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'tid' => array(
      'operator' => 'or',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'type' => 'textfield',
      'vid' => '14',
      'id' => 'tid',
      'table' => 'term_node',
      'field' => 'tid',
      'relationship' => 'group_nid',
      'hierarchy' => 0,
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 0);
  $views[$view->name] = $view;

  /*
   * View 'og_user_characters'
   */
  $view = new view;
  $view->name = 'og_user_characters';
  $view->description = 'A list of characters owned by the current user on the current OG.';
  $view->tag = 'webb';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'field_display_name_value' => array(
      'label' => '',
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'computed_value',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_display_name_value',
      'table' => 'node_data_field_display_name',
      'field' => 'field_display_name_value',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'field_display_name_value' => array(
      'order' => 'ASC',
      'delta' => -1,
      'id' => 'field_display_name_value',
      'table' => 'node_data_field_display_name',
      'field' => 'field_display_name_value',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'group_nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'php',
      'default_argument' => '',
      'validate_type' => 'og_group_types',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => 'return og_get_group_context()->nid;',
      'validate_argument_node_type' => array(
        'webform' => 0,
        'character' => 0,
        'board' => 0,
        'fleet' => 0,
        'logentry' => 0,
        'news' => 0,
        'note' => 0,
        'page' => 0,
        'position' => 0,
        'rank' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '10' => 0,
        '11' => 0,
        '12' => 0,
        '15' => 0,
        '13' => 0,
        '14' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
      'user_argument_type' => '',
      'restrict_user_roles' => 0,
      'user_roles' => array(),
    ),
    'uid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'php',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'uid',
      'table' => 'users',
      'field' => 'uid',
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => 'if ($node = menu_get_item(\'node\') && $node->type == \'note\') {
        return $node->uid;
      }
      else {
        return $GLOBALS[\'user\']->uid;
      }',
      'validate_argument_node_type' => array(
        'webform' => 0,
        'character' => 0,
        'board' => 0,
        'fleet' => 0,
        'logentry' => 0,
        'news' => 0,
        'note' => 0,
        'page' => 0,
        'position' => 0,
        'rank' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '10' => 0,
        '11' => 0,
        '12' => 0,
        '15' => 0,
        '13' => 0,
        '14' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
      'user_argument_type' => '',
      'restrict_user_roles' => 0,
      'user_roles' => array(),
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'character' => 'character',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $views[$view->name] = $view;

  /*
   * View 'user_characters'
   */
  $view = new view;
  $view->name = 'user_characters';
  $view->description = 'A list of all characters belonging to a specified user.';
  $view->tag = 'webb';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'group_nid' => array(
      'label' => 'Group node (post)',
      'required' => 1,
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'field_display_name_value' => array(
      'label' => 'Character',
      'link_to_node' => 1,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_display_name_value',
      'table' => 'node_data_field_display_name',
      'field' => 'field_display_name_value',
      'relationship' => 'none',
    ),
    'title_1' => array(
      'label' => 'Board',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title_1',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'group_nid',
    ),
  ));
  $handler->override_option('sorts', array(
    'field_display_name_value' => array(
      'order' => 'ASC',
      'delta' => -1,
      'id' => 'field_display_name_value',
      'table' => 'node_data_field_display_name',
      'field' => 'field_display_name_value',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'uid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'user',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'uid',
      'table' => 'users',
      'field' => 'uid',
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'webform' => 0,
        'character' => 0,
        'board' => 0,
        'fleet' => 0,
        'logentry' => 0,
        'news' => 0,
        'note' => 0,
        'page' => 0,
        'position' => 0,
        'rank' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '10' => 0,
        '11' => 0,
        '12' => 0,
        '15' => 0,
        '13' => 0,
        '14' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'character' => 'character',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 1,
    'order' => 'asc',
    'columns' => array(
      'field_display_name_value' => 'field_display_name_value',
      'title_1' => 'title_1',
    ),
    'info' => array(
      'field_display_name_value' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'title_1' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('profile', 'Profile', 'profile_1');
  $handler->override_option('weight', 10);
  $handler->override_option('default_argument', 'uid');
  $views[$view->name] = $view;

  return $views;
}
