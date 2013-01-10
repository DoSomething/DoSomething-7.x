(function($) {
  $(document).ready(function() {
    var fb_init = window.setInterval(function () {
      if (typeof FB !== 'undefined') {
        window.clearInterval(fb_init);
        run_facebook_share_count();
      }
    }, .1);

    var no_fb_click = false;
    $('#facebook-wrapper').click(function() {
      if (no_fb_click === true) {
        return false;
      }

      Drupal.behaviors.fb.feed({}, function(response) {
        if (typeof response !== 'undefined' && typeof response.post_id !== 'undefined') {
          $('#ds-facebook-share-button').addClass('shared').html(Drupal.t('Recommended!'));
          var c = parseInt($('#facebook-count').text());
          $('#facebook-count').text(++c);
          no_fb_click = true;
        }
      });
    });
  });

  function run_facebook_share_count() {
    var page = 'http://www.dosomething.org/actnow/actionguide/create-a-designated-driver-program';
    if (window.location.hash != '') {
      page = window.location.hash.substr(1);
    }

    FB.api({
        method: 'fql.query',
        query: "SELECT total_count, like_count, comment_count, share_count, commentsbox_count, click_count FROM link_stat WHERE url = '" + page + "'",
        return_ssl_resources: 1,
      }, function(response) {
        set_facebook_share_count(response);
      }
    );
  }

  function set_facebook_share_count(config) {
    var c = config[0];
    $('#facebook-count span').text(c.total_count);
  }
})(jQuery);