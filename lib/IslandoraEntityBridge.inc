<?php

/**
 * @file
 * Object Class for Islandora Entity Bridge.
 */

class IslandoraEntityBridge extends Entity {
  /**
   * Overrides defaultUri().
   */
  protected function defaultUri() {
    return islandora_entity_bridge_uri($this);
  }
}
