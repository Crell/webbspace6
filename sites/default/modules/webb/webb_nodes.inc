<?php

/**
 * Implementation of hook_access().
 */
function webb_character_access($op, $node, $account) {
  $type = is_string($node) ? $node : (is_array($node) ? $node['type'] : $node->type);

  if ($op == 'create') {
    if (user_access('create '. $type .' content', $account) || (_webb_og_is_subscriber(arg(1), NULL, TRUE))) {
      return TRUE;
    }
  }

  if ($op == 'update') {
    if (user_access('edit any '. $type .' content', $account)
        || (user_access('edit own '. $type .' content', $account) && ($account->uid == $node->uid))
        || (_webb_og_is_subscriber($node->og_groups, NULL, TRUE))) {
      return TRUE;
    }
  }

  if ($op == 'delete') {
    if (user_access('delete any '. $type .' content', $account)
        || (user_access('delete own '. $type .' content', $account) && ($account->uid == $node->uid))
        || (_webb_og_is_subscriber($node->og_groups, NULL, TRUE))) {
      return TRUE;
    }
  }
}

/**
 * Implementation of hook_form().
 *
 * This is just a stub, because we're doing nothing special here.
 */
function webb_character_form($node, $form_state) {
  return node_content_form($node, $form_state);
}


/**
 * Implementation of hook_access().
 */
function webb_board_access($op, $node, $account) {
  $type = is_string($node) ? $node : (is_array($node) ? $node['type'] : $node->type);

  if ($op == 'create') {
    if (user_access('create '. $type .' content', $account) || (_webb_og_is_subscriber(arg(1), NULL, TRUE))) {
      return TRUE;
    }
  }

  if ($op == 'update') {
    if (user_access('edit any '. $type .' content', $account)
        || (user_access('edit own '. $type .' content', $account) && ($account->uid == $node->uid))
        || (_webb_og_is_subscriber($node->og_groups, NULL, TRUE))) {
      return TRUE;
    }
  }

  if ($op == 'delete') {
    if (user_access('delete any '. $type .' content', $account)
        || (user_access('delete own '. $type .' content', $account) && ($account->uid == $node->uid))
        || (_webb_og_is_subscriber($node->og_groups, NULL, TRUE))) {
      return TRUE;
    }
  }
}

/**
 * Implementation of hook_form().
 *
 * This is just a stub, because we're doing nothing special here.
 */
function webb_board_form($node, $form_state) {
  return node_content_form($node, $form_state);
}

