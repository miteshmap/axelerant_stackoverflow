<?php

/**
 * Preprocess question_row theme.
 */
function template_preprocess_question_row(&$vars) {
  $node = $vars['node'];
  $vars['votes_count'] = isset($node->field_number_of_votes[LANGUAGE_NONE][0]['value']) ? $node->field_number_of_votes[LANGUAGE_NONE][0]['value'] : 0;
  $vars['answers_count'] = isset($node->field_number_of_answers[LANGUAGE_NONE][0]['value']) ? $node->field_number_of_answers[LANGUAGE_NONE][0]['value'] : 0;
  $vars['views_count'] = isset($node->field_number_of_views[LANGUAGE_NONE][0]['value']) ? $node->field_number_of_views[LANGUAGE_NONE][0]['value'] : 0;
  $vars['user'] = user_load($node->uid);
}

/**
 * Preprocess question_list
 */
function template_preprocess_question_list(&$vars) {
  $items = $vars['items'];
  $vars['lists'] = array();
  foreach($items as $node) {
    $vars['lists'][] = theme('question_row', array('node' => $node));
  }
}

/**
 * Preprocess for question vote up-down.
 */
function template_preprocess_stackoverflow_vote(&$vars) {
  $node = $vars['entity'];

  if (user_access('stackoverflow vote question')) {
    $vars['show_up_as_link'] = TRUE;
    $vars['show_down_as_link'] = TRUE;
    $vars['link_class_up'] = 'up-active use-ajax';
    $vars['link_class_down'] = 'down-active use-ajax';
    $vars['class_up'] = 'up-active';
    $vars['class_down'] = 'down-active';
  }
  else {
    $vars['show_up_as_link'] = FALSE;
    $vars['show_down_as_link'] = FALSE;
    $vars['link_class_up'] = 'up-inactive';
    $vars['link_class_down'] = 'down-inactive';
    $vars['class_up'] = 'up-inactive';
    $vars['class_down'] = 'down-inactive';
  }

  $vars['link_up'] = url('question/'.$node->nid.'/vote/nojs/up');
  $vars['link_down'] = url('question/'.$node->nid.'/vote/nojs/down');

  $vars['total_points'] = $node->field_number_of_votes[LANGUAGE_NONE][0]['value'];
}
