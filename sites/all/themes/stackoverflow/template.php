<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

function stackoverflow_preprocess_node(&$vars) {
  if ($vars['view_mode'] == 'full' && $vars['node']->type == 'question') {
    //drupal_add_library('system', 'drupal.ajax');
  }
}