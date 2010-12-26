<?php

/**
 * Implementation of hook_content_default_fields().
 */
function stf_notes_content_default_fields() {
  $fields = array();

  // Exported field: field_character
  $fields['note-field_character'] = array(
    'field_name' => 'field_character',
    'type_name' => 'note',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'character' => 'character',
      'board' => 0,
      'fleet' => 0,
      'logentry' => 0,
      'note' => 0,
      'page' => 0,
      'test' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'nid' => '0',
          'error_field' => 'field_character][nids',
        ),
      ),
      'default_value_php' => '',
      'label' => 'Character',
      'weight' => 0,
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_character_name
  $fields['note-field_character_name'] = array(
    'field_name' => 'field_character_name',
    'type_name' => 'note',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'computed',
    'required' => '1',
    'multiple' => '0',
    'module' => 'computed_field',
    'active' => '1',
    'code' => '//if ($node->nid != 0) return; // Do not allow this value to be edited, only set on creation
$node_field[0][\'value\'] = webb_character_name_format($node, $field, $node_field);
',
    'display' => 1,
    'display_format' => '$display = $node_field_item[\'value\'];',
    'store' => 1,
    'data_type' => 'varchar',
    'data_length' => '255',
    'data_not_null' => 1,
    'data_default' => '',
    'data_sortable' => 1,
    'widget' => array(
      'label' => 'Character Name',
      'weight' => 0,
      'description' => '',
      'type' => 'computed',
      'module' => 'computed_field',
    ),
  );

  // Exported field: field_parent_note
  $fields['note-field_parent_note'] = array(
    'field_name' => 'field_parent_note',
    'type_name' => 'note',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'note' => 'note',
      'advpoll_binary' => 0,
      'board' => 0,
      'character' => 0,
      'fleet' => 0,
      'project_issue' => 0,
      'logentry' => 0,
      'news' => 0,
      'page' => 0,
      'project_project' => 0,
      'advpoll_ranking' => 0,
      'webform' => 0,
    ),
    'advanced_view' => 'og_parent_nodes_allowed',
    'advanced_view_args' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(),
      ),
      'default_value_php' => '',
      'label' => 'Parent Note',
      'weight' => 0,
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_topic
  $fields['note-field_topic'] = array(
    'field_name' => 'field_topic',
    'type_name' => 'note',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'size' => NULL,
      'label' => 'Location',
      'weight' => 0,
      'description' => '',
      'type' => 'text_textfield_ogsuggest',
      'module' => 'webbtopic',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Character');
  t('Character Name');
  t('Location');
  t('Parent Note');

  return $fields;
}
