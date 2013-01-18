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
        var fbobj = {
          method: 'feed',
          link: settings.quiz_url,
          picture: $('.field-name-field-editorial-image img').attr('src'),
          name: 'I\'m ' + $('.pane-page-title h1').text(),
          caption: $('.panel-top .pane-2 h3').text(),
          description: $('.field-name-field-body').text() 
        };

        $('.quiz-share').click(function () {
          FB.ui(fbobj);
          return false;
        });
      }
    }
  };
}(jQuery));
