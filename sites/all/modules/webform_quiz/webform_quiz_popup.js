(function ($) {
  Drupal.behaviors.webform_quiz = {
    attach: function (context, settings) {
      // hide the results
      $('#block-system-main .content .panel-row-bottom .panel-first').hide();

      $fblink = $('<div>')
        .addClass('connect-with-facebook')
        .append(settings.fbconnect_button);
      $header = $('<h1>')
        .text('Almost there...');
      $content = $('<div>')
        .text('Connect to see your results.');

      $popup = $('<div>')
        .append($header)
        .append($content)
        .append($fblink)
        .attr('id', 'connect-results-popup')
        .dialog({
          resizable: false,
          draggable: false,
          modal: true,
          width: 1030,
          closeOnEscape: false,
          open: function(event, ui) { $(".ui-dialog-titlebar-close").hide(); }
        });
    }
  };
}(jQuery));
