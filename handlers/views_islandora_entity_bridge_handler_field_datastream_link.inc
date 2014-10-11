<?php

/**
 * @file
 * Views islandora entity bridge handler field datastream link handler class.
 */

class views_islandora_entity_bridge_handler_field_datastream_link extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    $options['datastream'] = array('default' => 'DC');
    $options['multiple'] = array('default' => FALSE);
    $options['list_type'] = array('default' => 'ul');
    $options['custom_separator'] = array('default' => ', ');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['datastream'] = array(
      '#title' => t('Datastream Link'),
      '#description' => t('A link to the datastream'),
      '#type' => 'textfield',
      '#default_value' => $this->options['datastream'],
      '#required' => TRUE,
    );
    $form['multiple'] = array(
      '#title' => t('Allow multiple'),
      '#description' => t('Treat this field as multi-valued.'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['multiple'],
    );
    $form['list_options'] = array(
      '#type' => 'fieldset',
      '#states' => array(
        'visible' => array(
          ':input[name="options[multiple]"]' => array(
            'checked' => TRUE,
          ),
        ),
      ),
    );
    $form['list_type'] = array(
      '#title' => t('List type'),
      '#description' => t('The type of list.'),
      '#type' => 'radios',
      '#default_value' => $this->options['list_type'],
      '#options' => array(
        'ul' => t('Unordered list'),
        'ol' => t('Ordered list'),
        'br' => check_plain('<br />'),
        'other' => t('Custom separator'),
      ),
      '#fieldset' => 'list_options',
    );
    $form['custom_separator'] = array(
      '#type' => 'textfield',
      '#title' => t('Separator'),
      '#default_value' => $this->options['custom_separator'],
      '#states' => array(
        'visible' => array(
          ':input[name="options[list_type]"]' => array(
            'value' => 'other',
          ),
        ),
      ),
      '#fieldset' => 'list_options',
    );
  }

  function query() {
  }

  /**
   * Load the entities for all rows that are about to be displayed.
   */
  function pre_render(&$values) {
    if (!empty($values) && !isset($this->view->entity_type)) {
      list($this->view->entity_type, $this->view->entities) = $this->query->get_result_entities($values, !empty($this->relationship) ? $this->relationship : NULL, $this->field_alias);
    }
  }
  
  function render($values) {
    $content = $this->options['datastream'];
    if (isset($this->view->entities[$this->view->row_index])) {
      $entity = $this->view->entities[$this->view->row_index];
      $content = l($this->options['datastream'], "islandora/object/{$entity->pid}/datastream/{$this->options['datastream']}/VIEW");
    }
    return $content;
  }
}
