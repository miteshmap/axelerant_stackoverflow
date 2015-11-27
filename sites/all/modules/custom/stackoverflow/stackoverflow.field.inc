<?php


/**
 * Implements hook_field_formatter_info().
 */
function stackoverflow_field_formatter_info() {
  return array(
    'number_vote' => array(
      'label' => t('Vote'),
      'field types' => array('number_integer', 'number_float'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function stackoverflow_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $settings = $display['settings'];

  switch ($display['type']) {
    case 'number_vote':
      foreach ($items as $delta => $item) {
        $element[$delta] = array(
          '#theme' => 'stackoverflow_vote',
          '#attached' => array(
            'css' => array(drupal_get_path('module', 'stackoverflow') . '/css/stackoverflow.css'),
            'library' => array(array('system', 'drupal.ajax')),
          ),
          '#value' => $item['value'],
          '#entity' => $entity,
        );
      }
      break;
  }

  return $element;
}