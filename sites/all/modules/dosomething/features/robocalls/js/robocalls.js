(function ($) {
  Drupal.behaviors.robocalls = {
    friends_field_count: 1,
    celeb_friends_field_count: 7,
    friends_limit: 9,
    celebs: [],
    previewing: false,

    attach: function(context, settings) {
      $('.preview').each(function() {
        if ($(this).find('a').attr('href')) {
          var a = $('<audio></audio>').attr('src', $(this).find('a').attr('href'));
          a.insertBefore($(this).find('a'));
        }
      });

      $('.preview a').click(function() {
        if (!Drupal.behaviors.robocalls.previewing) { 
          Drupal.behaviors.robocalls.previewing = true;
          $(this).parent().find('audio').trigger('play');
        }
        else {
          $(this).parent().find('audio').trigger('pause'); 
          Drupal.behaviors.robocalls.previewing = false;
        }
        return false;
      });
    }
  };
})(jQuery);