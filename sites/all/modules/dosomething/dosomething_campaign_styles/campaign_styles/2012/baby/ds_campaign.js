(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      $('#campaign-opt-in-help').dialog({
        autoOpen: false,
      }).css('padding-top', '10px').parent().css('background', 'white');
      $('#opt-in-help').click(function () {
        $('#campaign-opt-in-help').dialog('open');
        return false;
      });
      }
    };
})(jQuery);
