<?php

function stackoverflow_question_list_callback() {
  $query = db_select('node');
  $query->addField('node', 'nid');
  $query->condition('type', 'question');
  $query->condition('status', NODE_PUBLISHED);
  $query->orderBy('created', 'DESC');
  $query->addTag('node_access');
  $nids = $query->execute()->fetchCol();

  $items = array();

  if (!empty($nids)) {
    $nodes = node_load_multiple($nids);
    foreach ($nodes as $node) {
      $items[$node->nid] = theme('question_row', array('node' => $node));
    }
  }

  return theme('question_list', array('lists' => $items));
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
