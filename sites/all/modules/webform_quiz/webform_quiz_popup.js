(function ($) {
  Drupal.behaviors.webform_quiz = {
    attach: function (context, settings) {
      if (!settings.logged_in) {
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
      else {
        Drupal.behaviors.fb.feed({
          'feed_document': settings.quiz_url,
          'feed_title': $('.pane-page-title h1').text(),
          'feed_picture': $('.field-name-field-editorial-image img').attr('src'),
          'feed_caption': $('.panel-top .pane-2 h3').text(),
          'feed_description': $('.field-name-field-body').text(),
          'feed_selector': '.quiz-share',
        });
      }
    }
  };
}(jQuery));
