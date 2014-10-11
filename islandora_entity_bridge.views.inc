<?php

/**
 * @file
 * Views integration for the Islandora Entity Bridge module.
 */

/**
 * Implements hook_views_data_alter().
 */
function islandora_entity_bridge_views_data_alter(&$data) {
  $data['views_entity_islandora_entity_bridge']['datastream_image'] = array(
    'title' => t('Datastream - Image'),
    'help' => 'Embed an image datastream from the Fedora object.',
    'field' => array(
      'handler' => 'views_islandora_entity_bridge_handler_field_datastream_image',
      'type' => 'islandora_entity_bridge',
      'real field' => 'entity object',
    ),
  );

  $data['views_entity_islandora_entity_bridge']['datastream_link'] = array(
    'title' => t('Datastream - Link'),
    'help' => 'Embed a link to a datastream from the Fedora object.',
    'field' => array(
      'handler' => 'views_islandora_entity_bridge_handler_field_datastream_link',
      'type' => 'islandora_entity_bridge',
      'real field' => 'entity object',
    ),
  );

  $data['views_entity_islandora_entity_bridge']['datastream_xml'] = array(
    'title' => t('Datastream - XML'),
    'help' => 'Embed an XML datastream from the Fedora object.',
    'field' => array(
      'handler' => 'views_islandora_entity_bridge_handler_field_datastream_xml',
      'type' => 'islandora_entity_bridge',
      'real field' => 'entity object',
    ),
  );

  $data['views_entity_islandora_entity_bridge']['datastream_xpath'] = array(
    'title' => t('Datastream - XPath'),
    'help' => 'Embed the value of an XML element from the Fedora object via XPath.',
    'field' => array(
      'handler' => 'views_islandora_entity_bridge_handler_field_datastream_xpath',
      'type' => 'islandora_entity_bridge',
      'real field' => 'entity object',
    ),
  );
}
