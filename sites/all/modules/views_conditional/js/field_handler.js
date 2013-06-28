(function($) {
  Drupal.behaviors.fieldHandler = {
    condition_count: 1,

    attach: function() {
      var family = { 'and': { 1: { 'and': [], 'or': [] } }, 'or': {} };
      var i = '<li><span class="form-item"><img class="tree" src="/sites/all/modules/views_conditional/images/navbit.gif" alt="" /> #LABEL</span><div class="form-item form-type-select form-item-field"><select class="first-field form-select" id="edit-options-if" name="options[if]"><option value="0">- no field selected -</option><option value="field_picture">Field: Picture</option><option value="field_embedded_video">Content: Video</option><option value="views_ifempty">Views If Empty: Views If Empty</option><option value="title">Content: Title</option><option value="created">Content: Post date</option><option value="field_subtitle">Content: Subtitle</option><option value="body_1">Campaign Blog Text</option><option value="views_ifempty_1">Views If Empty: Views If Empty</option><option value="body">Content: Body</option></select></div><div class="form-item form-type-select form-item-options-conditions-condition"><select id="edit-options-conditions-condition" name="options[conditions][condition]" class="form-select"><option value="1">Is Equal to</option><option value="2">Is NOT equal to</option><option value="3">Is Greater than</option><option value="4">Is Less than</option><option value="5">Is Empty</option><option value="6">Is NOT empty</option><option value="7">Contains</option><option value="8">Does NOT contain</option></select></div><div class="form-item form-type-textfield form-item-options-conditions-equalto"><input type="text" id="edit-options-conditions-equalto" name="options[conditions][equalto]" value="" size="60" maxlength="128" class="form-text viewsImplicitFormSubmission-processed"></div><div id="options"><a href="#" class="delete">Remove this</a></div></li>';
      var data_id = 1;

      reload_clicks = function() {
        $('.add-and').unbind('click');
        $('.add-and').click(function() {
          var pid = $(this).parent().parent().attr('data-id');
          var nid = ++data_id;
          if (typeof family[pid] == 'undefined') {
            family[pid] = { 'or': [], 'and': [] };
          }

          family[pid]['and'].push(nid);

          if ($(this).parent().parent().find('.sub').length > 0) {
            item = i.replace('#LABEL', 'And');
            $(item).attr('data-id', nid).appendTo($(this).parent().parent().find('.sub').first());
            reload_clicks();
            delete item;
          }
          else {
            item = i.replace('#LABEL', 'And');
            var list = $('<ul></ul>').addClass('sub');
            $(item).attr('data-id', nid).appendTo(list);
            list.appendTo($(this).parent().parent());
            reload_clicks();
            delete item;
          }

          console.log(family);
          return false;
        });

        $('.add-or').unbind('click');
        $('.add-or').click(function() {
          var pid = $(this).parent().parent().attr('data-id');
          var nid = ++data_id;

          if (typeof family[pid] == 'undefined') {
            family[pid] = { 'or': [], 'and': [] };
          }

          family[pid]['or'].push(nid);

          if ($(this).parent().parent().find('.sub').length > 0) {
            item = i.replace('#LABEL', 'Or');
            $(item).attr('data-id', nid).appendTo($(this).parent().parent().find('.sub').first());
            reload_clicks();
            delete item;
          }
          else {
            item = i.replace('#LABEL', 'Or');
            var list = $('<ul></ul>').addClass('sub');
            $(item).attr('data-id', nid).appendTo(list);
            list.appendTo($(this).parent().parent());
            reload_clicks();
            delete item;
          }

          console.log(family);
          return false;
        });

        $('.add-master').unbind('click');
        $('.add-master').click(function() {
          var type = $(this).attr('data-type');
          var nid = ++data_id;

          if (typeof family[type][nid] == 'undefined') {
            family[type][nid] = { 'or': [], 'and': [] };
          }

          item = i.replace('#LABEL', type);
          var $append = $(item).attr('data-id', nid)
          $append.find('img').remove();
          $append.appendTo($('#conditions-container'));
          reload_clicks();
          delete item;
        });

        $('.delete').unbind('click');
        $('.delete').click(function() {
          $(this).parent().parent().fadeOut('fast');
        });
      };

      reload_clicks();
    }
  };
})(jQuery);