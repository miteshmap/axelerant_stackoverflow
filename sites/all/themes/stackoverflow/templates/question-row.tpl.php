<div class="panel panel-default" id="question-summary-<?php print $node->nid; ?>">
  <div class="panel-body">
    <div class="bs-example col-md-6">
      <ul class="nav nav-pills" role="tablist">
        <li role="presentation">
          <a href="#" title="<?php print ('Votes');?>">
            <span class="glyphicon glyphicon-thumbs-up visible-xs-inline visible-sm-inline" aria-hidden="true"></span>
            <span class="hidden-sm hidden-xs"><?php print t('Votes'); ?></span>
            <span class="badge"><?php print $votes_count; ?></span>
          </a>
        </li>
        <li role="presentation">
          <a href="#" title="<?php print ('Answers');?>">
            <span class="glyphicon glyphicon-ok visible-xs-inline visible-sm-inline" aria-hidden="true"></span>
            <span class="hidden-sm hidden-xs"><?php print t('Answers'); ?></span>
            <span class="badge"><?php print $answers_count; ?>
            </span>
          </a>
        </li>
        <li role="presentation">
          <a href="#" title="<?php print ('Views');?>">
            <span class="glyphicon glyphicon-eye-open visible-xs-inline visible-sm-inline" aria-hidden="true"></span>
            <span class="hidden-sm hidden-xs"><?php print t('Views'); ?></span>
            <span class="badge"><?php print $views_count; ?></span>
          </a>
        </li>
      </ul>
    </div>

    <div class="summary col-md-6">
      <h3 class="no-margin" style="margin: 0px !important;"><?php print l($node->title, 'node/' . $node->nid); ?></h3>
      <div class="started pull-right">
        <small>
          <?php print t('Posted by') .' '. l($user->name, 'user/'.$user->uid) . ' ' . t('%ago ago', array('%ago' => format_interval(REQUEST_TIME - $node->created, 1))); //format_interval(REQUEST_TIME, $node->created); ?>
        </small>
      </div>
    </div>
  </div>
</div>
