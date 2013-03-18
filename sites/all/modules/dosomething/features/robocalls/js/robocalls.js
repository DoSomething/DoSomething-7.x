(function ($) {
  Drupal.behaviors.robocalls = {
    friends_field_count: 1,
    celeb_friends_field_count: 7,
    friends_limit: 9,
    celebs: [],
    now_playing: 0,

    attach: function(context, settings) {
      $('.preview').each(function() {
        if ($(this).find('a').attr('href')) {
          var a = $('<audio></audio>').attr('src', $(this).find('a').attr('href'));
          a.insertBefore($(this).find('a'));
        }
      });

      $('#edit-submitted-friends-info-primary-friend-friends-number').mask("(999) 999-9999");

      $('.preview a').click(function() {
        if ($(this).attr('data-tid') != Drupal.behaviors.robocalls.now_playing) { 
          Drupal.behaviors.robocalls.now_playing = $(this).attr('data-tid');
          $('audio').trigger('pause');
          $('.preview a').removeClass('paused');
          $(this).addClass('paused');
          $(this).parent().find('audio').trigger('play');
        }
        else {
          $(this).removeClass('paused');
          $(this).parent().find('audio').trigger('pause');
          Drupal.behaviors.robocalls.now_playing = 0;
        }
        return false;
      });

      if ($('#edit-actions').length) {
        var d = new Date();
        var current_hour = d.getHours();

        // Make sure that people don't send calls after 10pm (their time!)
        if (current_hour >= 22 || current_hour <= 6) {
          $('#edit-actions').html("Now's not a good time to send a call.  Try again tomorrow!");
        }
      }
    }
  };
})(jQuery);