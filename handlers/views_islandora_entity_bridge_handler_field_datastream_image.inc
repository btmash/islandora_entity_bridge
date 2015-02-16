<?php

/**
 * @file
 * Views islandora entity bridge handler field datastream image handler class.
 */

class views_islandora_entity_bridge_handler_field_datastream_image extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    $options['datastream'] = array('default' => 'TN');
    $options['datastream_width'] = array('default' => '0');
    $options['datastream_height'] = array('default' => '0');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['datastream'] = array(
      '#title' => t('Image Datastream'),
      '#description' => t('An image datastream. Allowed formats are: gif jpeg png.'),
      '#type' => 'textfield',
      '#default_value' => $this->options['datastream'],
      '#required' => TRUE,
    );
    $form['datastream_width'] = array(
      '#title' => t('Datastream Image - Width (px)'),
      '#description' => t('The datastream image width'),
      '#type' => 'textfield',
      '#default_value' => $this->options['datastream_width'],
      '#required' => FALSE,
    );
    $form['datastream_height'] = array(
      '#title' => t('Datastream Image - Height (px)'),
      '#description' => t('The datastream image height'),
      '#type' => 'textfield',
      '#default_value' => $this->options['datastream_height'],
      '#required' => FALSE,
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
    $content = '';
    if (isset($this->view->entities[$this->view->row_index])) {
      $entity = $this->view->entities[$this->view->row_index];
      $path = "islandora/object/{$entity->pid}/datastream/{$this->options['datastream']}/VIEW";
      $content = l($this->options['datastream'], $path);
      if (isset($entity->islandora_object[$this->options['datastream']])) {
        $datastream = islandora_datastream_load($this->options['datastream'], $entity->pid);
        if (in_array($datastream->mimetype, array('image/gif', 'image/jpeg', 'image/png'))) {
          $variables = array(
            'path' => $path,
            'title' => $entity->label,
          );
          if (is_numeric($this->options['datastream_width']) && $this->options['datastream_width'] > 0) {
            $variables['width'] = $this->options['datastream_width'];
          }
          if (is_numeric($this->options['datastream_height']) && $this->options['datastream_height'] > 0) {
            $variables['height'] = $this->options['datastream_height'];
          }
          $content = theme('image', $variables);
        }
        else {
          $content = 'An image datastream was not provided.';
        }
      }
    }
    return $content;
  }
}
