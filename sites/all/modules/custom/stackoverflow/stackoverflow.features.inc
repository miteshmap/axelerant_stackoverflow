<?php
/**
 * @file
 * stackoverflow.features.inc
 */

/**
 * Implements hook_node_info().
 */
function stackoverflow_node_info() {
  $items = array(
    'question' => array(
      'name' => t('question'),
      'base' => 'node_content',
      'description' => t('Question content type for the questions.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
