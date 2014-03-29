<?php

/**
 * Displays the content type admin overview page.
 */
function islandora_entity_bridge_overview_cmodels() {
  module_load_include('inc', 'islandora', 'includes/utilities');

  $field_ui = module_exists('field_ui');
  $header = array(
    t('Name'),
  );
  if ($field_ui) {
    $header[] = array('data' => t('Operations'), 'colspan' => 2);
  };
  $header = array(t('Name'), array('data' => t('Operations'), 'colspan' => $field_ui ? '2' : '2'));
  $rows = array();

  foreach (islandora_get_content_models(TRUE) as $content_model) {
    $pid = $content_model['pid'];
    $row = array($content_model['label']);
    if ($field_ui) {
      $row[] = array('data' => l(t('manage fields'), 'admin/structure/ieb_cmodel/manage/' . $content_model['pid'] . '/fields'));
      $row[] = array('data' => l(t('manage display'), 'admin/structure/ieb_cmodel/manage/' . $content_model['pid'] . '/display'));
    }
    $rows[] = $row;
  }
  $build['ieb_cmodel_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No cmodels added.'),
  );

  return $build;
}
