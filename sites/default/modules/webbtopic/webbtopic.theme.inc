<?php

/**
 * Build tags for each topic.
 *
 * @ingroup themeable
 */
function theme_webbtopic_topic($name) {
  if (FALSE !== strpos($name, ',')) {
    $name = '"'. $name .'"';
  }
  $name = check_plain($name);
  return "<span class='webbtopic-topic'>{$name}</span>";
}

/**
 * FAPI theme for an individual text elements.
 *
 * The textfield or textarea is already rendered by the
 * textfield or textarea themes and the html output
 * lives in $element['#children']. Override this theme to
 * make custom changes to the output.
 *
 * $element['#field_name'] contains the field name
 * $element['#delta]  is the position of this element in the group
 */
function theme_text_textfield_ogsuggest($element) {
  drupal_add_js(drupal_get_path('module', 'webbtopic') . '/webbtopic.js', 'module');
  return $element['#children'];
}
