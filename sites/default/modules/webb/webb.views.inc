<?php

/**
 * Implementation of hook_views_plugins
 */
function webb_views_plugins() {
return array(
    'argument default' => array(
      'webb_node_owner_or_user' => array(
        'title' => t('Node owner or current user'),
        'handler' => 'webb_plugin_argument_default_owner_or_user',
        'parent' => 'fixed',
      ),
    ),
  );
}
