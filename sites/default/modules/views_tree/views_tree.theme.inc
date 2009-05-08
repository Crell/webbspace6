<?php

/**
 * Theme function for the tree style plugin.
 *
 * We need to do some weirdness that makes more sense as a theme function
 * than as a template.
 *
 * @ingroup themeable
 * @link http://drupal.org/node/355919
 */
function theme_views_tree($view, $options, $rows, $title) {
  $result = $view->result;
  $fields = &$view->field;

  $options['main_field_property'] = $fields[$options['main_field']]->field_alias;
  $options['parent_field_property'] = $fields[$options['parent_field']]->field_alias;

  // Normalize the top level of records to all point to 0 as their parent
  // We only have to do this once, so we do it here in the wrapping function.
  $parents = array();
  foreach ($result as $record) {
    $parents[] = $record->$options['main_field_property'];
  }
  foreach ($result as $record) {
    dpm("Checking Note {$record->nid}, parent is {$record->$options['parent_field_property']}");
    if (! in_array($record->$options['parent_field_property'], $parents)) {
      dpm("Reparenting note {$record->nid}");
      $record->$options['parent_field_property'] = 0;
    }
  }

  return $title . theme('views_tree_inner', $view, $options, $rows, $title, $result, 0);
}

/**
 * Inner recursive theme function for views tree theming.
 *
 * @ingroup themeable
 * @param $view
 * @param $options
 * @param $row
 * @param $title
 * @param $result
 *   An array representing the raw data returned from the query.
 * @param $parent
 *   The id of the parent entry in the call stack.
 */
function theme_views_tree_inner($view, $options, $rows, $title, $result, $parent = NULL) {
  $items = array();
  foreach ($result as $i => $record) {
    if ($record->$options['parent_field_property'] == $parent) {
      $items[] = $rows[$i] . call_user_func(__FUNCTION__, $view, $options, $rows, $title, $result, $record->$options['main_field_property']);
    }
  }
  return count($items) ? theme('item_list', $items, NULL, $options['type']) : '';
}