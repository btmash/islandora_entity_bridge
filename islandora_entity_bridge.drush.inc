<?php

/**
 * Implements hook_drush_command().
 */
function islandora_entity_bridge_drush_command() {
  $items = array();

  $items['islandora_entity_bridge_populate_entity_bridge'] = array(
    'aliases' => array('cdcpeb'),
    'description' => 'Populate entity bridge',
    'bootstrap' => DRUSH_BOOSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**********
 * Populate Entity Bridge Mappings.
 */

function drush_islandora_entity_bridge_populate_entity_bridge() {
  $batch = array(
    'operations' => array(),
    'finished' => 'drush_islandora_entity_bridge_populate_entity_bridge_finished',
    'title' => t('Loading entities...'),
    'init_message' => t('Preparing to import image datastreams'),
    'progress_message' => t('Submitting content...'),
    'error_message' => t('Content could not get reimported'),
  );

  $connection = new IslandoraTuque();
  $query = 'SELECT ?object FROM <#ri> WHERE {
    ?object <dc:identifier> ?identifier ;
    } ORDER BY ?object';
  $results = $connection->repository->ri->sparqlQuery($query);

  foreach ($results as $result) {
    $pid = $result['object']['value'];
    $batch['operations'][] = array(
      'drush_islandora_entity_bridge_populate_entity_bridge_object', array($pid),
    );
  }

  batch_set($batch);
  $batch =& batch_get();
  $batch['progressive'] = FALSE;
  drush_backend_batch_process();
}

function drush_islandora_entity_bridge_populate_entity_bridge_object($pid, &$context) {
  $context['message'] = t("Populating Fedora PID @pid", array('@pid' => $pid));
  $object = islandora_object_load($pid);
  islandora_entity_bridge_islandora_object_modified($object);
}

function drush_islandora_entity_bridge_populate_entity_bridge_finished() {
  drupal_set_message('Successfully prepopulated entity bridge mapping table.');
}
