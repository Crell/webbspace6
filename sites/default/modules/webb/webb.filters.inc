<?php

/**
 * Implementation of hook_filter().
 */
function webb_filter($op, $delta = 0, $format = -1, $text = '') {
  // The "list" operation provides the module an opportunity to declare both how
  // many filters it defines and a human-readable name for each filter. Note that
  // the returned name should be passed through t() for translation.
  if ($op == 'list') {
    return array(
      0 => t('WeBB note quote filter'),
    );
  }

  switch ($delta) {

    // First we define the simple string substitution filter.
    case 0:

      switch ($op) {
        // This description is shown in the administrative interface, unlike the
        // filter tips which are shown in the content editing interface.
        case 'description':
          return t('Wrap lines that begin with a configurable "quote" character so they can be styled.');

        // We don't need the "prepare" operation for this filter, but it's required
        // to at least return the input text as-is.
        case 'prepare':
          return $text;

        // The actual filtering is performed here. The supplied text should be
        // returned, once any necessary substitutions have taken place.
        case 'process':
          $lines = explode("\n", $text);
          $num_lines = sizeof($lines);
          $quote_char = variable_get('webb_note_quote_char', ':');
          for ($i=0; $i < $num_lines; ++$i) {
            if ($lines[$i][0] == $quote_char) {
              $lines[$i] = theme('webb_note_quoted_line', $lines[$i], $quote_char);
            }
          }
          return implode("\n", $lines);

        // Since we allow the administrator to define the string that gets
        // substituted when "foo" is encountered, we need to provide an
        // interface for this customization. Note that the value of $format
        // needs to be provided as part of the form name, so that different
        // customization can be done for this filter in each of the different
        // input formats that may use it.
        case 'settings':
          $form['webb_note_quote_filter'] = array(
            '#type' => 'fieldset',
            '#title' => t('WeBB note quote filter'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
          );
          $form['webb_note_quote_filter']["webb_note_quote_filter_$format"] = array(
            '#type' => 'textfield',
            '#title' => t('Quoting prefix character'),
            '#default_value' => variable_get('webb_note_quote_char', ':'),
            '#description' => t('The character to prefix to a line to indicate that it is quoted.  Do not include a leading or trailing space.'),
          );
          return $form;
      }
      break;
  }
}

/**
 * Implementation of hook_filter_tips().
 */
function webb_filter_tips($delta, $format, $long = FALSE) {
  switch ($delta) {
    case 0:
      if ($long) {
        return t('Every line beginning with %char will be treated as "quoted" from the previous message.', array(
          '%char' => variable_get('webb_note_quote_char', ':'),
        ));
      }
      else {
        return t('Every line beginning with %char will be treated as "quoted" from the previous message.', array(
          '%char' => variable_get('webb_note_quote_char', ':'),
        ));
      }
      break;
  }
}
