<?php

/**
 * @file
 * Utility functions.
 */

/**
 * Utility function to load a cck field instance object.
 *
 * Why this doesn't exist in CCK, I don't know...
 *
 * This is probably D5-only.
 *
 * @param string $field_name
 * @param string $type_name
 * @return object
 */
function webb_get_field_instance($field_name, $type_name) {
  $field = db_fetch_object(db_query("SELECT * FROM {node_field_instance} WHERE field_name='%s' AND type_name='%s'", $field_name, $type_name));
  $field->widget_settings = unserialize($field->widget_settings);
  $field->display_settings = unserialize($field->display_settings);
  return $field;
}

/**
 * Formats a note as the default body string for replies to it.
 */
function webb_quote_note($node) {

  $body = trim($node->body);

  // build the "header" portion of the quote, saying where it came from and when
  $characters = array();
  foreach ($node->field_character_name as $character) {
    $characters[] = $character['value'];
  }
  $character = implode(', ', $characters);
  $locations = array();
  foreach ($node->taxonomy as $location) {
    $locations[] = $location->name;
  }
  $location = implode(', ', $locations);
  $header = t('Posted by @character in @location', array(
    '@character' => $character,
    '@location' => (empty($node->webb['webbtopic_topic']) ? '' : $node->webb['webbtopic_topic']),
  ));
  $body = $header . "\n" . $body;

  // Now quote it by prefixing every line with a magic value
  $quote_char = variable_get('webb_note_quote_char', ':');
  $quote_replace = "\n{$quote_char} ";
  $body = $quote_char . ' ' . preg_replace("/\n/", $quote_replace, $body) . "\n\n";

  return $body;
}

function _webb_is_og_admin($og_nids, $uid=NULL) {
  return _webb_og_is_subscriber($og_nids, $uid, TRUE);
}

function _webb_og_is_subscriber($og_nids, $uid=NULL, $check_admin = FALSE) {
  if (!isset($uid)) {
    global $user;
    $uid = $user->uid;
  }
  // We want to allow both single and multi-og checks.
  if (!is_array($og_nids)) {
    $og_nids = array($og_nids);
  }
  $account = _webb_user_load($uid);

  if ($check_admin) {
    foreach ($account->og_groups as $og => $settings) {
      if ((in_array($og, $og_nids) && isset($settings['is_admin']) && $settings['is_admin']) || user_access('administer organic groups', $account)) {
        return TRUE;
      }
    }
    return FALSE;
  }
  else {
    $subscribed_ogs = array_keys($account->og_groups);
    return (boolean)array_intersect($subscribed_ogs, $og_nids);
  }
}



/**
 * Loads a user by uid, cached
 *
 * user_load() doesn't do caching, because it's dumb, so we wrap a layer of caching around it.
 */
function _webb_user_load($uid) {
  static $users = array();

  if (!isset($users[$uid])) {
    $users[$uid] = user_load(array('uid' => $uid));
  }
  return $users[$uid];
}

/**
 * Gets an associative array of taxonomy terms in a vocabulary.
 */
function _webb_taxonomy_get_terms($vid) {
  $terms = array();
  $select = _taxonomy_term_select('', 'vid', 0, $vid, '', FALSE, FALSE, array());
  foreach ($select['#options'] as $option) {
    list($tid, $term) = each($option->option);
    $terms[$tid] = $term;
  }
  return $terms;
}
