<?php

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
    if ($record->$options['parent_field_property'] != $parent) {
      continue;
    }
    $items[] = $rows[$i] . call_user_func(__FUNCTION__, $view, $options, $rows, $title, $result, $record->$options['main_field_property']);
  }
  return count($items) ? theme('item_list', $items, NULL, $options['type']) : '';
}