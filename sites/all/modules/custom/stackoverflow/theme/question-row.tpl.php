<div class="panel panel-default" id="question-summary-<?php print $node->nid; ?>">
  <div class="panel-body">
    <div class="bs-example col-md-6">
      <ul class="nav nav-pills" role="tablist">
        <li role="presentation">
          <a href="#">
            <span class="glyphicon glyphicon-align-left" aria-hidden="true"></span>
            <span class="hidden-sm hidden-xs"><?php print t('Votes'); ?></span>
            <span class="badge"><?php print $votes_count; ?></span>
          </a>
        </li>
        <li role="presentation">
          <a href="#">
            <span class="glyphicon glyphicon-align-left" aria-hidden="true"></span>
            <span class="hidden-sm hidden-xs"><?php print t('Answers'); ?></span>
            <span class="badge"><?php print $answers_count; ?>
            </span>
          </a>
        </li>
        <li role="presentation">
          <a href="#">
            <span class="glyphicon glyphicon-align-left" aria-hidden="true"></span>
            <span class="hidden-sm hidden-xs"><?php print t('Views'); ?></span>
            <span class="badge"><?php print $views_count; ?></span>
          </a>
        </li>
      </ul>
    </div>

    <div class="summary col-md-6">
      <h3 class="no-margin" style="margin: 0px !important;"><?php print l($node->title, 'node/'.$node->nid); ?></h3>
      <div class="started pull-right">
        <?php print t('Posted by') .' '. l($user->name, 'user/'.$user->uid); //format_interval(REQUEST_TIME, $node->updated); ?>
      </div>
    </div>
  </div>
</div>
