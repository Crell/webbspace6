<?php
// $Id: ie_css_optimizer.admin.inc,v 1.4 2009/07/18 23:33:35 johnalbin Exp $

/**
 * @file
 * Display administrative forms for this module.
 */

/**
 * Implement HOOK_form_alter().
 */
function _ie_css_optimizer_form_system_performance_settings_alter(&$form, $form_state) {
  // Copied straight from system_performance_settings().
  $directory = file_directory_path();
  $is_writable = is_dir($directory) && is_writable($directory) && (variable_get('file_downloads', FILE_DOWNLOADS_PUBLIC) == FILE_DOWNLOADS_PUBLIC);

  // ANDing $is_writable converts default to a boolean, so we override it here.
  $form['bandwidth_optimizations']['preprocess_css']['#default_value'] = !$is_writable ? 0 : variable_get('preprocess_css', 0);

  // Alter the available options.
  unset($form['bandwidth_optimizations']['preprocess_css']['#options'][1]);
  $form['bandwidth_optimizations']['preprocess_css']['#options']['theme'] = t('Partial optimization for theme CSS development');
//$form['bandwidth_optimizations']['preprocess_css']['#options']['module'] = t('Partial optimization for module CSS development');
  $form['bandwidth_optimizations']['preprocess_css']['#options'][1] = t('Full optimization');
  $form['bandwidth_optimizations']['preprocess_css']['#description'] =
    t('<em>Disabled:</em> Not recommended. Internet Explorer is limited to 31 linked stylesheets and disabling CSS optimization can cause your website to display improperly in that browser.') . '<br />'
    . t('<em>Partial optimization for CSS development:</em> Optimize all stylesheets except for those in active development.') . '<br />'
    . t('<em>Full optimization:</em> This option can interfere with module/theme development, but should be enabled in a production environment.');
}
