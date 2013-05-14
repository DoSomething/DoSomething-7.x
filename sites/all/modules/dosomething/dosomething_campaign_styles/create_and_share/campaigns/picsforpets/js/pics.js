(function($) {
  Drupal.behaviors.picsforpetsCampaign = {
    authed: false,
    probably_unauthed: false,
    notify_yourself: false,
    started_page: false,

    attach: function(context, settings) { 
      $('.go-filter').click(function(e) {
        var type = $('.type-filter').val();
        var state = $('.state-filter').val();

        // The destination parameter is unbiased.  We need to tell it where to go here.
        var dest = (type != 'all') ? type + ((state != '') ? '-' + state : '') : ((state != '') ? state : 'root');

        document.location.href = '/cas/' + Drupal.settings.campaign.campaign_root + '/mark-clickthrough/' + dest;
        return false;
      });

      // Handles Facebook sharing.
      var share_array = [];
      $('.facebook-share').each(function() {
        var picture = $(this).parent().parent().find('img').attr('src');
        var selector = $(this).attr('class').replace('facebook-share ', '');

        // Add this facebook button to the array of possible buttons on the page (used later*).
        share_array.push(selector);

        // Handles click event.
        $(this).click(function() {
          // Pop Facebook feed.
          var sid = $(this).attr('data-sid');
          Drupal.behaviors.fb.feed({
            'feed_title' : settings.campaign.facebook.share.title,
            'feed_picture': picture,
            'feed_caption': settings.campaign.facebook.share.caption,
            'feed_description': settings.campaign.facebook.share.description,
            'feed_selector': selector,
            'feed_allow_multiple': false,
            'feed_noclick': true
          }, function(response) {
            // Submit the share to the database.
            $.post('/cas/' + Drupal.settings.campaign.campaign_root + '/share/' + sid, { 'origin': document.location.pathname.replace('/', ''), 'alert': true }, function(response) {
              var c = parseInt($('.' + selector + '-count').text());
              $('.' + selector + '-count').text(++c);

              // Attend to share count.
              Drupal.behaviors.picsforpetsCampaign.tip_shares(settings);
            });
          });

          return false;
        });
      });

      // Loads the share counts for all of the submissions, and updates their FB bubble.
      // (* used here)
      Drupal.behaviors.fb.get_counts(share_array, null, function(counts) {
        for (i in counts) {
          $('.' + i + '-count').text(counts[i]);
        }
      });
    },

    tip_shares: function(settings) {
      settings.campaign.shares++;

      // Show the "become a furtographer" popup after 5 shares.
      if (settings.campaign.shares == 5) {
        $.fn.dsCampaignPopup(settings.campaign.campaign_root, 'tip', 0);
      }
    },
  };
})(jQuery);