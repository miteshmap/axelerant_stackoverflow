<?php

/**
 * page callback: List Page.
 */
function stackoverflow_question_list() {

  $query = db_select('node');
  $query->addField('node', 'nid');
  $query->condition('type', 'question');
  $query->condition('status', NODE_PUBLISHED);
  $query->orderBy('created', 'DESC');
  $query->addTag('node_access');
  $nids = $query->execute()->fetchCol();

  $build = array();

  if (!empty($nids)) {
    $nodes = node_load_multiple($nids);
    foreach ($nodes as $node) {
      $build['node'][$node->nid] = array(
        '#theme' => 'question_row',
        '#node' => $node
      );
    }
  }

  //return theme('question_list',array('items' => $lists));
  return $build;
}

/**
 * Menu callback: Cast vote of question.
 */
function stackoverflow_question_vote_update($node, $ajax, $status) {
  switch ($status) {
    case 'up':
      stackoverflow_update_field_count($node, 'field_number_of_votes');
      break;
    case 'down':
      stackoverflow_update_field_count($node, 'field_number_of_votes', 'del');
      break;
  }

  $is_ajax = $ajax === 'ajax';

  if ($is_ajax) {
    $node = node_load($node->nid);
    $value = $node->field_number_of_votes[LANGUAGE_NONE][0]['value'];
    $commands = array();

    // Perhaps we could remove the table row we just deleted?
    $commands[] = ajax_command_html('.stackoverflow-upanddown .current-score', $value);

    return array(
      '#type' => 'ajax',
      '#commands' => $commands,
    );
  }
  else {
    drupal_set_message(t('Your vote has been received.'));
    drupal_goto();
  }
}
