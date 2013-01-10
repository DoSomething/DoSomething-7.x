(function($) {
  $(document).ready(function() {
    // Waits for Facebook to load before setting the share count.
    var fb_init = window.setInterval(function () {
      if (typeof FB !== 'undefined') {
        window.clearInterval(fb_init);
        run_facebook_share_count();
      }
    }, .1);

    // Set "disabled FB button" status = false
    var no_fb_click = false;
    // When you click on the Facebook wrapper...
    $('#facebook-wrapper').click(function() {
      // Don't do anything if it's disabled.
      if (no_fb_click === true) {
        return false;
      }

      // Run a standard Facebook feed dialog.
      Drupal.behaviors.fb.feed({}, function(response) {
        // Only perform any actions if the response actually posted something.
        if (typeof response !== 'undefined' && typeof response.post_id !== 'undefined') {
          // Disable Facebook "recommend" btuton
          $('#ds-facebook-share-button').addClass('shared').html(Drupal.t('Recommended!'));
          no_fb_click = true;

          // Increase the share count by one.
          var c = parseInt($('#facebook-count').text());
          $('#facebook-count').text(++c);
        }
      });
    });
  });

  // Queries Facebook for the share count on the page that you're looking at.
  function run_facebook_share_count() {
    // Set the page = current page
    var page = document.location.href;

    // Run the FQL query to get share counts.
    FB.api({
        method: 'fql.query',
        query: "SELECT total_count, like_count, comment_count, share_count, commentsbox_count, click_count FROM link_stat WHERE url = '" + page + "'",
        return_ssl_resources: 1,
      }, function(response) {
        // Run the function to set the share count.
        set_facebook_share_count(response);
      }
    );
  }

  // Actually sets the facebook share count
  function set_facebook_share_count(config) {
    // Get the total count...for now.
    var c = config[0];
    // Populate the bubble with the share count.
    $('#facebook-count span').text(c.total_count);
  }
})(jQuery);