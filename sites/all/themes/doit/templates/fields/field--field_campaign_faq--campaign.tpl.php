<div class="section" id="faq">
<?php foreach ($items as $delta => $item): $set = current($item['entity']['field_collection_item']); ?>
  <h4><?php print $set['field_faq_question'][0]['#markup']; ?></h4>
  <div><?php print $set['field_faq_answer'][0]['#markup']; ?></div>
<?php endforeach; ?>
</div>
