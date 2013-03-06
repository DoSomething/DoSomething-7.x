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

      if ($('#edit-actions').length) {
        var d = new Date();
        var current_hour = d.getHours();

        // Make sure that people don't send calls after 10pm (their time!)
        if (current_hour >= 22) {
          $('#edit-actions').html("Sorry, it's too late to send a call now.  Try again tomorrow!");
        }
      }
    }
  };
})(jQuery);