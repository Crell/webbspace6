<?php

/**
 * Implementation of hook_content_default_fields().
 */
function stf_characters_content_default_fields() {
  module_load_include('inc', 'stf_characters', 'stf_characters.defaults');
  $args = func_get_args();
  return call_user_func_array('_stf_characters_content_default_fields', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function stf_characters_views_default_views() {
  module_load_include('inc', 'stf_characters', 'stf_characters.features.views');
  $args = func_get_args();
  return call_user_func_array('_stf_characters_views_default_views', $args);
}
