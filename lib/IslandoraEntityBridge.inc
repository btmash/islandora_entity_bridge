<?php

/**
 * Object Class for Islandora Entity Bridge.
 * Create any necessary overrides.
 */
class IslandoraEntityBridge extends Entity {
  /**
   * Override defaultUri().
   */
  protected function defaultUri() {
    return islandora_entity_bridge_uri($this);
  }
}
