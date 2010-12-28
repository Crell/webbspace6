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
      'weight' => '3',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
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
      'edict' => 0,
      'fleet' => 0,
      'project_issue' => 0,
      'logentry' => 0,
      'news' => 0,
      'note' => 0,
      'page' => 0,
      'position' => 0,
      'prez' => 0,
      'project_project' => 0,
      'rank' => 0,
      'taxdesc' => 0,
      'webform' => 0,
    ),
    'advanced_view' => 'og_user_characters',
    'advanced_view_args' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'autocomplete_match' => 'contains',
      'size' => 60,
      'label' => 'Character',
      'weight' => '3',
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
      'weight' => '2',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
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
    'display_format' => '$display = $node_field_item[\'value\'];',
    'store' => 1,
    'data_type' => 'varchar',
    'data_length' => '255',
    'data_not_NULL' => '',
    'data_default' => '',
    'data_sortable' => 1,
    'widget' => array(
      'label' => 'Character Name',
      'weight' => '2',
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
      'weight' => '1',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
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
      'board' => 0,
      'character' => 0,
      'edict' => 0,
      'fleet' => 0,
      'project_issue' => 0,
      'logentry' => 0,
      'news' => 0,
      'page' => 0,
      'position' => 0,
      'prez' => 0,
      'project_project' => 0,
      'rank' => 0,
      'taxdesc' => 0,
      'webform' => 0,
    ),
    'advanced_view' => 'reply_notes',
    'advanced_view_args' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_parent_note][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'autocomplete_match' => 'contains',
      'size' => '5',
      'node_link' => array(
        'teaser' => 0,
        'full' => 1,
        'title' => 'Reply',
        'hover_title' => 'Reply to this post',
        'destination' => 'default',
      ),
      'fallback' => 'leave_blank',
      'label' => 'Parent Note',
      'weight' => '1',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_topic
  $fields['note-field_topic'] = array(
    'field_name' => 'field_topic',
    'type_name' => 'note',
    'display_settings' => array(
      'weight' => '4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
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
      'weight' => '4',
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
