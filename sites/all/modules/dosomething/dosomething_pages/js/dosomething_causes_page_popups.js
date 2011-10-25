(function ($) {
  Drupal.behaviors.causePagePopUps = { 
    attach: function(context, settings) {
      $('.cause-item .cause-item-pop-up-content').before('<a class="pop-up-open" href="#">open</a>').hide();
      $('.cause-item .pop-up-open').click(function() {
        $(this).parent().children('.cause-item-pop-up-content').show();
        $(this).parent().children('.cause-description').hide();
        $(this).hide();
        $(this).parent().children('h2').before('<a class="pop-up-close" href="#">close</a>');
        $('.cause-item .pop-up-close').click(function() {
          $(this).parent().children('.pop-up-open').show();
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

