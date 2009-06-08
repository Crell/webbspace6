<?php

/**
 * Default argument plugin to extract the user for character handling.
 */
class webb_plugin_argument_default_owner_or_user extends views_plugin_argument_default {
  function argument_form(&$form, &$form_state) {
  }

  function get_argument() {
    $node = menu_get_object('node');
    if ($node && $node->type == 'note') {
      return $node->uid;
    }
    else {
      return $GLOBALS['user']->uid;
    }
  }
}

