(function ($) {
  Drupal.behaviors.causePagePopUps = {
    attach: function(context, settings) {
      $('.cause-item .cause-item-pop-up-content').hide();
      $('.cause-item .cause-description').append('<a class="pop-up-open" href="#">open</a>');
      $('.cause-item .pop-up-open').click(function() {
        $(this).parent().parent().addClass('showing');
        $(this).parent().parent().children('.cause-item-pop-up-content').show();
        $(this).parent().parent().children('.cause-description').hide();
        // $(this).hide();
        $(this).parent().parent().children('h2').before('<a class="pop-up-close" href="#">close</a>');
        $('.cause-item .pop-up-close').click(function() {
          $(this).parent().removeClass('showing');
          // $(this).parent().children('.pop-up-open').show();
          $(this).parent().children('.cause-description').show();
          $(this).parent().children('.cause-item-pop-up-content').hide();
          $(this).remove();
          return false;
        });
        return false;
      });

    }
  }
}(jQuery));

