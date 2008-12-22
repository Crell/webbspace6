<div class="node<?php if ($sticky) { print " sticky"; } ?><?php if (!$status) { print " node-unpublished"; } ?>">
  <?php if ($page == 0) : ?>
    <h2 class="title"><a href="<?php print $node_url?>"><?php print $title?></a></h2>
  <?php endif; ?>
  <div class="submitted"><?php echo $submitted; ?></div>
  <div class="content">
    <?php // print $field_body[0]['view']; ?>
    <?php print $node->content['body']['#value']; ?>
  </div>
  
  <?php if ($links) : ?>
    <div class="links">&raquo; <?php print $links?></div>
  <?php endif; ?>
  
  <?php if ($node->content['notes']['#value']) : ?>
    <div class="note_list"><?php echo $node->content['notes']['#value']; ?></div>
  <?php endif; ?>
</div>
