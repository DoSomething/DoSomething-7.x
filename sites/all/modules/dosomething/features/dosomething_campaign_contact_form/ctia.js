(function($) {
  $(document).ready(function () {
    $('#campaign-opt-in-help').dialog({
      autoOpen: false,
    }).css('padding-top', '10px').parent().css('background', 'white');
    $('#opt-in-help, #opt-in-help-mobile').click(function () {
      $('#campaign-opt-in-help').dialog('open');
      return false;
    });
  });
})(jQuery);
