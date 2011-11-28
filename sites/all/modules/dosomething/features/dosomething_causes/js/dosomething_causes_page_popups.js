(function ($) {
  Drupal.behaviors.causePagePopUps = {
    attach: function(context, settings) {
      $('html').addClass('causes-page-js');
      $('.cause-item .cause-description').not('.no-popup').append('<a class="pop-up-open" href="#">open</a>');
      $('.cause-item .pop-up-open').click(function() {
        $('.cause-item')
          .removeClass('showing')
          .children('.pop-up-close').remove()
          ;
        $thisCause = $(this).parent().parent();
        $thisCause
          .addClass('showing')
          .children('h2').before('<a class="pop-up-close" href="#">close</a>')
          ;
        $('.cause-item .pop-up-close').click(function() {
          $thisCause = $(this).parent();
          $thisCause
            .removeClass('showing')
          $(this).remove();
          return false;
        });
        return false;
      });

    }
  }
}(jQuery));

