<?php

/**
 * @file
 * Views integration for the views_field_view module.
 */

/**
 * Implements hook_views_data_alter().
 */
function islandora_entity_bridge_views_data_alter(&$data) {
  $data['views_entity_islandora_entity_bridge']['datastream'] = array(
    'title' => t('Datastream'),
    'help' => 'Embed a datastream from the fedora object',
    'field' => array(
      'handler' => 'views_islandora_entity_bridge_handler_field_datastream',
      'type' => 'islandora_entity_bridge',
      'real field' => 'entity object',
    ),
  );

  $data['views_entity_islandora_entity_bridge']['datastream_image'] = array(
    'title' => t('Datastream Image'),
    'help' => 'Embed a datastream image from the fedora object',
    'field' => array(
      'handler' => 'views_islandora_entity_bridge_handler_field_datastream_image',
      'type' => 'islandora_entity_bridge',
      'real field' => 'entity object',
    ),
  );

  $data['views_entity_islandora_entity_bridge']['datastream_xpath'] = array(
    'title' => t('Datastream XPATH'),
    'help' => 'Embed a contents of a datastream XPATH from the fedora object',
    'field' => array(
      'handler' => 'views_islandora_entity_bridge_handler_field_datastream_xpath',
      'type' => 'islandora_entity_bridge',
      'real field' => 'entity object',
    ),
  );
}
