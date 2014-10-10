<?php

/**
 * @file
 * Views islandora entity bridge handler field datastream xml handler class.
 */

class views_islandora_entity_bridge_handler_field_datastream_xml extends views_handler_field {
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
      '#title' => t('XML Datastream'),
      '#description' => t('An XML datastream. Please be sure to select an XML datastream.'),
      '#type' => 'textfield',
      '#default_value' => $this->options['datastream'],
      '#required' => TRUE,
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
      // We should probably check the MIME type of the datastream somehow
      // before we continue.
      $xml = file_get_contents("{$GLOBALS['base_url']}/islandora/object/{$entity->pid}/datastream/{$this->options['datastream']}/VIEW");
      $doc = new DOMDocument('1.0');
      $doc->preserveWhiteSpace = FALSE;
      $doc->formatOutput = TRUE;
      $doc->loadXML($xml);
      $content = htmlentities($doc->saveXML());
    }
    return $content;
  }
}
