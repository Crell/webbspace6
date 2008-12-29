<?php

/**
 * Form builder; Configuration form for WeBB settings.
 */
function webb_settings() {
  $form = array();

  foreach (og_get_types('group') as $type) {
    $options[$type] = node_get_types('name', $type);
  }

  $form['webb_og_posting_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Support posting on'),
    '#description' => t('Select which organic group node types support posting notes.'),
    '#options' => $options,
    '#default_value' => variable_get('webb_og_posting_types', array()),
  );

  return system_settings_form($form);
}
