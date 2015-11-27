
<div class="stackoverflow-upanddown" id="<?php print $entity->nid; ?>">
  <div class="up-score clear-block">
      <?php if ($show_up_as_link): ?>
        <a href="<?php print $link_up; ?>" rel="nofollow" class="<?php print "$link_class_up"; ?>" title="<?php print t('Vote up!'); ?>">
      <?php endif; ?>
      <div class="<?php print $class_up; ?>" title="<?php print t('Vote up!'); ?>"></div>
      <div class="element-invisible"><?php print t('Vote up!'); ?></div>
      <?php if ($show_up_as_link): ?>
        </a>
      <?php endif; ?>
  </div>
  <span class="current-score badge"><?php print $total_points; ?></span>
  <div class="down-score clear-block">
    <?php if ($show_down_as_link): ?>
      <a href="<?php print $link_down; ?>" rel="nofollow" class="<?php print "$link_class_down"; ?>" title="<?php print t('Vote down!'); ?>">
    <?php endif; ?>
    <div class="<?php print $class_down; ?>" title="<?php print t('Vote down!'); ?>"></div>
    <div class="element-invisible"><?php print t('Vote down!'); ?></div>
    <?php if ($show_down_as_link): ?>
      </a>
    <?php endif; ?>
  </div>

</div>
