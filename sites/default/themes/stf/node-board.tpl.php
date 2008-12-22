<div class="node<?php if (!$status) { print " node-unpublished"; } ?>">
  <?php if ($page == 0) : ?>
    <h2 class="title"><a href="<?php print $node_url?>"><?php print $title?></a></h2>
  <?php endif; ?>
  <span class="submitted"><?php print $submitted?></span>
  <span class="taxonomy"><?php print $terms?></span>
  <div class="content"><?php print $field_motd[0]['view']; ?></div>
  <?php if ($links) : ?>
    <div class="links">&raquo; <?php print $links?></div>
  <?php endif; ?>
</div>


<?php if ($node->content['roster']['#value']) : ?>
  <?php echo $node->content['roster']['#value']; ?>
<?php endif; ?>
