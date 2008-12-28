<?php

/**
 * Implementation of hook_access().
 */
function webb_character_access($op, $node, $account) {

  $type = is_string($node) ? $node : (is_array($node) ? $node['type'] : $node->type);

  if ($op == 'create') {
    if (user_access('create '. $type .' content', $account)
        || (_webb_is_og_admin(arg(1)))) {
      return TRUE;
    }
  }

  if ($op == 'update' || $op == 'delete') {
    if (user_access('edit '. $type .' content', $account)
        || (user_access('edit own '. $type .' content', $account) && ($account->uid == $node->uid))
        || (_webb_is_og_admin($node->og_groups))) {
      return TRUE;
    }
  }
}

/**
 * Implementation of hook_form().
 *
 * This is just a stub, because we're doing nothing special here.
 */
function webb_character_form($node) {
  return node_content_form($node);
}


/**
 * Implementation of hook_access().
 */
function webb_board_access($op, $node, $account) {
  $type = is_string($node) ? $node : (is_array($node) ? $node['type'] : $node->type);

  if ($op == 'create') {
    return user_access('create '. $type .' content');
  }

  if ($op == 'update' || $op == 'delete') {
    if (user_access('edit '. $type .' content')
        || (user_access('edit own '. $type .' content') && ($account->uid == $node->uid))
        || (_webb_is_og_admin($node->nid))) {
      return TRUE;
    }
  }
}

/**
 * Implementation of hook_form().
 *
 * This is just a stub, because we're doing nothing special here.
 */
function webb_board_form($node) {
  return node_content_form($node);
}

