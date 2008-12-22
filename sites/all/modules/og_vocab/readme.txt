Description
-----------------
Adds a categories tab to all group home pages where group admins may add/edit their own vocabularies. This enables groups to structure their content.

Themes
-------------------
You might want to group your terms by vocab on the node display. Here is a snippt from groups.drupal.org for node.tpl.php which does so:

<?php if ($links || $terms) { ?>
<div class="links">
   <div class="left">
    <?php if ($terms  && !$is_preview) { ?>
       <?php 
			 	  // group terms by vocab
			    foreach ($node->taxonomy as $tid => $term) {
				    $vocabs[$term->vid][$term->tid] = l($term->name, "taxonomy/term/$tid");
				  }
				  krsort($vocabs);

				  //render a line for each vocab. performs a query to get vocab name
				  foreach ($vocabs as $vid => $vocab) {
					  $fullvocab = taxonomy_get_vocabulary($vid);
					  $output .= "<div id=\"node-vocab-$vid\">". $fullvocab->name. ': '. theme('links', $vocab). "</div>";
					}
			 ?>
       <div class="terms"><?php print $output; ?></div>
    <?php } ?>
   </div>
   <?php if ($links) { ?>
     <div class="right">» <?php print $links?></div>
   <?php } ?>&nbsp;
</div>
<?php }; ?>

Author
------------------
Moshe Weitzman <weitzman AT tejasa.com

Sponsors
------------------
Buyblue - http://buyblue.org
Green Party of Canada - http://www.greenparty.ca