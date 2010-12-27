<?php

/**
 * Implementation of hook_node_info().
 */
function stf_notes_node_info() {
  $items = array(
    'note' => array(
      'name' => t('Note'),
      'module' => 'features',
      'description' => t('A note posted on a ship by a member.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function stf_notes_views_api() {
  return array(
    'api' => '2',
  );
}
