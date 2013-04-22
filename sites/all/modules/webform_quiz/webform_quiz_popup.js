(function ($) {
  Drupal.behaviors.webform_quiz = {
    attach: function (context, settings) {
      Drupal.behaviors.fb.feed({
        'feed_document': settings.quiz_url,
        'feed_title': $('.pane-page-title h1').text(),
        'feed_picture': $('.field-name-field-editorial-image img').attr('src'),
        'feed_caption': $('.panel-top .pane-2 h3').text(),
        'feed_description': $('.field-name-field-body').text(),
        'feed_selector': '.quiz-share',
      });
    }
  };
}(jQuery));
