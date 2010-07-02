<?php

/**
 * Implementation of hook_node_info().
 */
function stf_news_node_info() {
  module_load_include('inc', 'stf_news', 'stf_news.features.node');
  $args = func_get_args();
  return call_user_func_array('_stf_news_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function stf_news_views_default_views() {
  module_load_include('inc', 'stf_news', 'stf_news.features.views');
  $args = func_get_args();
  return call_user_func_array('_stf_news_views_default_views', $args);
}
