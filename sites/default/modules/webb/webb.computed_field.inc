<?php

/**
 * @file
 * Computed Field calculation functions.
 */

/**
 * Computing function for the Note::field_character field.
 *
 * The saved character name is either the name of the character, if applcable,
 * or the name of the user if no character is specified.
 *
 */
function webb_character_name_format(&$node, $field, &$node_field) {
  if ($node->field_character[0]['nid']) {
    // There is a character, so return its formatted full name.
    $character = node_load($node->field_character[0]['nid']);

    return $character->field_display_name[0]['value'];
  }
  else {
    // We're posting as a normal user.  The user's name will already be listed by the theme.
    $account = _webb_user_load($node->uid);

    $name = array();
    if (!empty($account->profile_first_name)) {
      $name[] = $account->profile_first_name;
    }
    if (!empty($account->profile_last_name)) {
      $name[] = $account->profile_last_name;
    }

    $name = count($name) ? implode($name, ' ') : $account->name;

    return $name;
  }
}

/**
 * Computing function for the Character::field_display_name field.
 *
 * The character's display name is based off of its rank, name, and position.
 *
 */
function webb_character_display_name_format(&$node, $field, &$node_field) {

    $ranks = array();
    foreach ($node->field_rank as $rank) {
      $term = taxonomy_get_term($rank['tid']);
      if ($term->name) {
        $ranks[] = $term->name;
      }
    }

    $rank = sizeof($ranks) ? implode(', ', $ranks) . ' ' : '';
    $position = trim(webb_character_position_format($node, $field, $node_field));
    if ($position) {
      $position = ' (' . $position . ')';
    }

    return  $rank . $node->title . $position;
}

/**
 * Computing function for the Character::field_position field.
 *
 * The computed position is simply all pre-defined and custom positions
 * concatenated and comma-delimited.
 *
 */
function webb_character_position_format(&$node, $field, &$node_field) {
  $positions = array();
  foreach ($node->field_position as $position) {
    $term = taxonomy_get_term($position['tid']);
    if ($term->name) {
      $positions[] = $term->name;
    }
  }
  foreach ($node->field_custom_position as $position) {
    if ($position['value']) {
      $positions[] = $position['value'];
    }
  }

  return implode(', ', $positions);
}
