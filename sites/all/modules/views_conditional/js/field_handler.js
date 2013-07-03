/**
 * Views Conditional Field Handler
 *
 * Views Conditional 2.0 offers the ability to run multiple conditions at the same time.  This file
 * handles the processing of adding new "conditional groups" and regular "conditions".  As a summary:
 *
 * "Conditional groups" are groups of conditions that will be processed together.  "Condtional groups" are the
 * "top level" of conditions, and are really just a regular condition that defines the first condition in a series.
 * Conditional groups may be either AND or OR conditions.
 *
 * "Conditions" must always fall under a conditional group, to be processed along with its sibling(s) under that same
 * group.  Conditions may be either AND or OR conditions.
 *
 */

(function($) {
  Drupal.behaviors.ViewsConditionalFieldHandler = {
    condition_count: 0,

    attach: function() {
      var master_template = 'options[conditions][#ID]';
      var child_template = 'options[conditions][#PID][children][#ID]';

      var select_field = $('.form-item-options-hidden-field-select').clone();
      var select;

      var i = '<li><input type="hidden" name="' + child_template + '[type]" value="#TYPE" /><span class="form-item"><img class="tree" src="/sites/all/modules/views_conditional/images/navbit.gif" alt="" /> #LABEL</span><div class="form-item form-type-select form-item-field">#SELECT</div><div class="form-item form-type-select form-item-options-conditions-condition"><select id="edit-options-conditions-condition" name="' + child_template + '[condition]" class="form-select"><option value="1">Is Equal to</option><option value="2">Is NOT equal to</option><option value="3">Is Greater than</option><option value="4">Is Less than</option><option value="5">Is Empty</option><option value="6">Is NOT empty</option><option value="7">Contains</option><option value="8">Does NOT contain</option></select></div><div class="form-item form-type-textfield form-item-options-conditions-equalto"><input type="text" id="edit-options-conditions-equalto" name="' + child_template + '[equals]" value="" size="60" maxlength="128" class="form-text viewsImplicitFormSubmission-processed"></div><div id="options"><a href="#" class="add-sub" data-type="and">Add "And"</a> <span class="divider">|</span> <a href="#" class="add-sub" data-type="or">Add "Or"</a> <span class="divider">|</span> <a href="#" class="delete">Remove this</a></div></li>';
      var mi = '<li><input type="hidden" name="' + master_template + '[type]" value="#TYPE" /><span class="form-item"><img class="tree" src="/sites/all/modules/views_conditional/images/navbit.gif" alt="" /> #LABEL</span><div class="form-item form-type-select form-item-field">#SELECT</div><div class="form-item form-type-select form-item-options-conditions-condition"><select id="edit-options-conditions-condition" name="' + master_template + '[condition]" class="form-select"><option value="1">Is Equal to</option><option value="2">Is NOT equal to</option><option value="3">Is Greater than</option><option value="4">Is Less than</option><option value="5">Is Empty</option><option value="6">Is NOT empty</option><option value="7">Contains</option><option value="8">Does NOT contain</option></select></div><div class="form-item form-type-textfield form-item-options-conditions-equalto"><input type="text" id="edit-options-conditions-equalto" name="' + master_template + '[equals]" value="" size="60" maxlength="128" class="form-text viewsImplicitFormSubmission-processed"></div><div id="options"><a href="#" class="add-sub" data-type="and">Add "And"</a> <span class="divider">|</span> <a href="#" class="add-sub" data-type="or">Add "Or"</a> <span class="divider">|</span> <a href="#" class="delete">Remove this</a></div></li>';
      var data_id = 0;
      if (typeof last_elm !== 'undefined') {
        data_id = last_elm;
      }

      reload_clicks = function() {
        $('.add-sub').unbind('click');
        $('.add-sub').click(function() {
          var pid = $(this).parent().parent().attr('data-id');
          var mtype = $(this).parent().parent().attr('data-type');
          data_id++;
          var type = $(this).attr('data-type');

          select_field.find('select').attr('id', '').attr('name', child_template + '[field]');
          select = select_field.html();

          type = type.charAt(0).toUpperCase() + type.substr(1);
          if ($(this).parent().parent().find('.sub').length > 0) {
            item = $(i);
            item.find('.divider, .add-sub').remove();
            item = item[0].outerHTML.replace(/\#LABEL/g, type).replace(/\#SELECT/g, select).replace(/\#MTYPE/g, '[' + mtype + ']').replace(/\#TYPE/g, type.toLowerCase()).replace(/\#PID/g, pid).replace(/\#ID/g, data_id);

            $(item).attr('data-id', data_id).appendTo($(this).parent().parent().find('.sub').first());
            reload_clicks();
          }
          else {
            item = $(i);
            item.find('.divider, .add-sub').remove();
            item = item[0].outerHTML.replace(/\#LABEL/g, type).replace(/\#SELECT/g, select).replace(/\#MTYPE/g, '[' + mtype + ']').replace(/\#TYPE/g, type.toLowerCase()).replace(/\#PID/g, pid).replace(/\#ID/g, data_id);

            var list = $('<ul></ul>').addClass('sub');
            $(item).attr('data-id', data_id).appendTo(list);
            list.appendTo($(this).parent().parent());
            reload_clicks();
          }

          return false;
        });

        // Add a "master" (e.g. group) field
        $('.add-master').unbind('click');
        $('.add-master').click(function() {
          var type = $(this).attr('data-type');
          data_id++;

          select_field.find('select').attr('id', '').attr('name', master_template + '[field]');
          select = select_field.html();

          type = type.charAt(0).toUpperCase() + type.substr(1);
          item = mi.replace(/\#LABEL/g, type).replace(/\#SELECT/g, select).replace(/\#MTYPE/g, '').replace(/\#TYPE/g, type.toLowerCase()).replace(/\#PID/g, '');
          item = item.replace(/\#ID/g, data_id);
          var $append = $(item).attr('data-id', data_id).attr('data-type', type.toLowerCase());
          $append.find('img').remove();
          $append.appendTo($('#conditions-container'));
          reload_clicks();
        });

        // Delete button.
        $('.delete').unbind('click');
        $('.delete').click(function() {
          var $parent = $(this).parent().parent();

          // Resetting all values will remove the field on submit.
          $parent.find('select').val("");
          $parent.find('input').val("");
          $parent.slideUp('fast');
          return false;
        });
      };

      reload_clicks();
    }
  };
})(jQuery);