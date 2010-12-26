<?php

/**
 * Implementation of hook_views_default_views().
 */
function stf_notes_views_default_views() {
  $views = array();

  // Exported view: og_notes
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
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'ASC',
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
      'default_action' => 'empty',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => 'Notes on %1',
      'breadcrumb' => '',
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
        'news' => 0,
        'project_project' => 0,
        'project_issue' => 0,
        'character' => 0,
        'board' => 0,
        'edict' => 0,
        'fleet' => 0,
        'logentry' => 0,
        'note' => 0,
        'page' => 0,
        'position' => 0,
        'prez' => 0,
        'rank' => 0,
        'taxdesc' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '16' => 0,
        '14' => 0,
        '15' => 0,
        '10' => 0,
        '11' => 0,
        '12' => 0,
        '18' => 0,
        '13' => 0,
        '17' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
      'override' => array(
        'button' => 'Override',
      ),
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
        '11' => 0,
        '3' => 0,
        '4' => 0,
        '10' => 0,
      ),
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_project_term_vocabulary' => array(
        '13' => 0,
      ),
      'validate_argument_project_term_argument_type' => 'tid',
      'validate_argument_project_term_argument_action_top_without' => 'pass',
      'validate_argument_project_term_argument_action_top_with' => 'pass',
      'validate_argument_project_term_argument_action_child' => 'pass',
    ),
  ));
  $handler->override_option('filters', array(
    'created' => array(
      'operator' => '>=',
      'value' => array(
        'type' => 'offset',
        'value' => '-1 week',
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
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Recent notes');
  $handler->override_option('empty', 'No notes found.');
  $handler->override_option('empty_format', '6');
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
    'name' => 'navigation',
  ));
  $handler = $view->new_display('node_content', 'Node content', 'node_content_1');
  $handler->override_option('types', array(
    'note' => 'note',
  ));
  $handler->override_option('modes', array(
    '0' => 'full',
  ));
  $handler->override_option('argument_mode', 'token');
  $handler->override_option('default_argument', '[og-id]');
  $handler->override_option('show_title', 1);

  $views[$view->name] = $view;

  return $views;
}
