<?php

/**
 * @file
 * Utility functions.
 */

/**
 * Set the OG context based on the path.
 *
 * OG is really lousy at keeping track of its context.  Therefore, we set it
 * manually based on the path at times, such as a node-add form.  To cover
 * all bases we set the context explicitly as well as fake-out the $_GET array,
 * even though writing into $_GET is horribly evil.
 */
function webb_set_og_context() {
  $group = NULL;

  // menu_get_object assumes the type maps directly to a load routine, so
  // we have to allow for multiple possible load routines since we are using
  // load routines to control access and tab location.  Blargh!
  foreach (array('node', 'webb_postable_node') as $type) {
    if ($group = menu_get_object($type)) {
      break;
    }
  }
  
  // If we didn't find a group yet, we may be on the node/add page.  If so, look
  // for a nid in nodereference_url form and use its group.  This is even uglier.
  if (empty($group)) {
    if (arg(0) == 'node' && arg(1) == 'add' && arg(2) == 'note' && is_numeric(arg(3))) {
      $parent = node_load(arg(3));
      $group = node_load(current($parent->og_groups));
    }
  }
  
  og_set_group_context($group);
  $_GET['gids'] = array($group->nid);
}

/**
 * Determine if the specified type is an OG node that supports the posting system.
 */
function webb_is_post_type($type) {
  return in_array($type, variable_get('webb_og_posting_types', array()));
}

/**
 * Formats a note as the default body string for replies to it.
 */
function   webb_quote_note($node) {

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
