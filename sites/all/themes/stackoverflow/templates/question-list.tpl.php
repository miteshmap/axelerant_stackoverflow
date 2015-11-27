<div id="qlist-wrapper">
  <div id="question-mini-list">
    <?php
      if (!empty($lists)):
        foreach($lists as $list):
          print $list;
        endforeach;
      else:
        print t('No Questions found');
      endif;
    ?>
  </div>
</div>