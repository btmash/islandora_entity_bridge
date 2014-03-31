<?php

/**
 * @file
 * Controller class for Islandora Entity Bridge.
 * This extends the DrupalDefaultEntityController class, adding required
 * special handling for Islandora Entity Bridge Objects.
 */

class IslandoraEntityBridgeController extends EntityAPIController {

  /**
   * Overrides attachLoad().
   */
  protected function attachLoad(&$entities, $revision_id = FALSE) {
    // Figure out any other hooks you want to attach.
    parent::attachLoad($entities, $revision_id);
    foreach ($entities as $entity) {
      $entity->islandora_object = islandora_object_load($entity->pid);
    }
  }

  /**
   * Override the save method.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $replacements = array(
      '<',
      '>',
      'info:fedora/'
    );
    $entity->pid = str_replace($replacements, '', $entity->pid);
    return parent::save($entity, $transaction);
  }
}
