<?php
// $Id: ie_css_optimizer.pages.inc,v 1.3 2009/07/18 22:34:31 johnalbin Exp $

/**
 * @file
 * Optimize CSS files for development in Internet Explorer.
 *
 * @TODO: Re-write this entire file to make patching core easier. Add a
 * ie_css_optimizer_get_css() that can be used as a drop-in replacement for
 * drupal_get_css().
 */

/**
 * Aggregate all but 30 of the active theme's stylesheets.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function _ie_css_optimizer_preprocess_page(&$vars, $hook) {
  // Count the number of link tags that will be used.
  $number_of_link_tags = 0;
  $style_imports = array();

  // Check for Conditional Stylesheet's link tags.
  $conditional_styles = variable_get('conditional_styles_' . $GLOBALS['theme'], '');
  $number_of_link_tags += substr_count($conditional_styles, '<link');

  // $vars['directory'] points at the page.tpl.php, which may not be in the
  // active theme. So we create our own path to theme.
  $themes = list_themes();
  $theme_path = dirname($themes[$GLOBALS['theme']]->filename);

  // Loop through all of the stylesheets.
  foreach (array_keys($vars['css']) AS $media) {
    // Each media type is aggregated separately.
    $number_of_link_tags++;
    foreach (array_keys($vars['css'][$media]) AS $type) {
      if ($type == 'module') {
        // Setup theme overrides for module styles.
        $theme_styles = array();
        foreach (array_keys($vars['css'][$media]['theme']) as $theme_style) {
          $theme_styles[] = basename($theme_style);
        }
      }
      foreach (array_keys($vars['css'][$media][$type]) AS $path) {
        // If the theme supplies its own style using the name of the module style, skip its inclusion.
        // This includes any RTL styles associated with its main LTR counterpart.
        if ($type == 'module' && in_array(str_replace('-rtl.css', '.css', basename($path)), $theme_styles)) {
          // Unset the file to prevent its inclusion when CSS aggregation is enabled.
          unset($vars['css'][$media][$type][$path]);
          continue;
        }
        // Exempt the active theme's styles from aggregation.
        if ($type == 'theme' && strpos($path, $theme_path) === 0) {
          if ($number_of_link_tags < 31) {
            // Implement the style using its own link tag.
            $vars['css'][$media][$type][$path] = FALSE;
            $number_of_link_tags++;
          }
          else {
            // Implement the style using an @import statement.
            $style_imports[$media][] = $path;
            unset($vars['css'][$media][$type][$path]);
          }
        }
        // Some module styles are marked as exempt from aggregation.
        elseif (!$vars['css'][$media][$type][$path]) {
          $number_of_link_tags++;
        }
      }
    }
  }

  // Reset the styles variable with the new aggregation.
  $vars['styles'] = drupal_get_css($vars['css']);

  // If we have over 31 link tags, include the @import stylesheets.
  if (!empty($style_imports)) {
    foreach (array_keys($style_imports) AS $media) {
      $output = '';
      foreach ($style_imports[$media] AS $path) {
        if (file_exists($path)) {
          $output .= '  @import "' . $vars['base_path'] . $path . '";' . "\n";
        }
      }
      if ($output) {
        $vars['styles'] .= '<style type="text/css" media="' . $media . '">' . "\n$output</style>\n";
      }
    }
  }

  // Add conditional stylesheets, since we just overwrote them.
  if (module_exists('conditional_styles')) {
    $vars['styles'] .= $conditional_styles;
  }
}
