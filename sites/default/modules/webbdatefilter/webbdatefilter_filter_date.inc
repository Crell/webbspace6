<?php

/**
 * Filter to handle the node created field using a select box.
 */
class webbdatefilter_filter_date extends views_handler_filter_date {

	var $real_field = 'created';
	
	function option_definition() {
    $options = parent::option_definition();

    // Add a field to store our select box configuration.
    $options['value']['value_options'] = '';
    
    return $options;
  }

  /**
   * Add a type selector to the value form.
   */
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);
    if (empty($form_state['exposed'])) {
	    $form['value']['value_options'] = array(
	      '#type' => 'textarea',
	      '#title' => t('Options'),
	      '#rows' => 3,
	    	'#default_value' => !empty($this->value['value_options']) ? $this->value['value_options'] : '',
	    );
    }

    // I assume there's a better way to do this, but I'll be damned 
    // if I canfigure it out.  If we're on the exposed filter form
    // rather than the configuration of it, mutate the textfield into
    // a select box based on the configured options.
    
    // @todo There is a bug here somewhere. If the filter is set
    // required, then by default we always get an error on the form until
    // it gets submitted.  If it's not required, there is an "All" option
    // available to the user that will fail.  Fix this at some point. *sigh*
    if ($form_state['form_id'] != 'views_ui_config_item_form') {
    	
    	foreach (explode("\n", $this->value['value_options']) as $option) {
    		list($label, $value) = explode('|', $option);
    		$options[trim($value)] = trim($label);
    	}
    	
    	$form['value']['#type'] = 'select';
    	$form['value']['#options'] = $options;
    	unset($form['value']['#size']);
    }
  }
}
