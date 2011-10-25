(function ($) {
  Drupal.behaviors.causePagePopUps = {
    attach: function(context, settings) {
      $('html').addClass('causes-page-js');
      // $('.cause-item .cause-item-pop-up-content').hide();
      $('.cause-item .cause-description').append('<a class="pop-up-open" href="#">open</a>');
      $('.cause-item .pop-up-open').click(function() {
        $('.cause-item')
          .removeClass('showing')
          // .children('.cause-description-pre').show().end()
          // .children('.cause-description').show().end()
          // .children('.cause-item-pop-up-content').hide().end()
          .children('.pop-up-close').remove()
          ;
        $thisCause = $(this).parent().parent();
        $thisCause
          .addClass('showing')
          // .children('.cause-item-pop-up-content').show().end()
          // .children('.cause-description-pre').hide().end()
          // .children('.cause-description').hide().end()
          .children('h2').before('<a class="pop-up-close" href="#">close</a>')
          ;
        $('.cause-item .pop-up-close').click(function() {
          $thisCause = $(this).parent();
          $thisCause
            .removeClass('showing')
            // .children('.cause-description-pre').show().end()
            // .children('.cause-description').show().end()
            // .children('.cause-item-pop-up-content').hide();
          $(this).remove();
          return false;
        });
        return false;
      });

    }
  }
}(jQuery));

