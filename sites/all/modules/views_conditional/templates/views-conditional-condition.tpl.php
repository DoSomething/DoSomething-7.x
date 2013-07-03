<li data-id="<?php echo $key; ?>" data-type="<?php echo $type; ?>">
  <?php if ($key > 1): ?><span class="form-item"><img class="tree" src="/<?php echo drupal_get_path('module', 'views_conditional') . '/images/navbit.gif'; ?>" alt=""><?php echo ucfirst($type); ?></span><?php endif; ?>
  <input type="hidden" name="<?php echo $template; ?>[type]" value="<?php echo $type; ?>" />
  <div class="form-item form-type-select form-item-field">
    <select class="first-field form-select" id="edit-options-if" name="<?php echo $template; ?>[field]">
      <?php echo $field_list; ?>
    </select>
  </div>
  <div class="form-item form-type-select form-item-options-conditions-condition first">
    <select id="edit-options-conditions-condition" name="<?php echo $template; ?>[condition]" class="form-select">';
      <?php echo $condition_list; ?>
    </select>
  </div>
  <div class="form-item form-type-textfield form-item-options-conditions-equalto">
    <input type="text" id="edit-options-conditions-equalto" name="<?php echo $template; ?>[equals]" value="<?php echo $equals; ?>" size="60" maxlength="128" class="form-text viewsImplicitFormSubmission-processed" />
  </div>
  <div id="options" class="first">
    <?php if ($group == 'group'): ?><a href="#" class="add-sub" data-type="and">Add "And"</a> <span class="divider">|</span> <a href="#" class="add-sub" data-type="or">Add "Or"</a><?php if ($key > 1): ?> <span class="divider">|</span><?php endif; endif; ?>
    <?php if ($key > 1): ?><a href="#" class="delete">Remove this</a><?php endif; ?>
  </div>
  <?php if (!empty($children)): echo $children; endif; ?>
</li>