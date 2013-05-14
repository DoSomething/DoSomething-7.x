(function($) {
  Drupal.behaviors.picsforpetsCampaign = {
    authed: false,
    probably_unauthed: false,
    notify_yourself: false,
    started_page: false,

    attach: function(context, settings) { 
      $('.fb-share a').click(function(e) {
        if (!Drupal.behaviors.fb.is_authed() || !Drupal.behaviors.create_and_share.logged_in) {
          $.fn.dsCampaignPopup('share-login', 0, { 'goto': document.location.href });
          return false;
        }

        var img = $(this).parent().parent().parent().find('.simg img').attr('data-original');
        var sid = $(this).attr('rel');

        Drupal.behaviors.fb.image({
          'img_namespace': Drupal.settings.campaign.facebook.share.namespace,
          'img_object': Drupal.settings.campaign.facebook.share.object,
          'img_action': Drupal.settings.campaign.facebook.share.action,
          'img_document': document.location.origin + '/' + Drupal.settings.campaign.campaign_root + '/' + sid,
          'img_message': true,
          'img_picture': img,
          'img_require_login': true,
        }, function(response) {
          $.post('/' + Drupal.settings.campaign.campaign_root + '/fb-share/' + sid, {}, function(response) {
            // Nothing!
          });
        });

        return false;
      });

      $('.go-filter').click(function(e) {
        var type = $('.type-filter').val();
        var state = $('.state-filter').val();

        // The destination parameter is unbiased.  We need to tell it where to go here.
        var dest = (type != 'all') ? type + ((state != '') ? '-' + state : '') : ((state != '') ? state : 'root');

        document.location.href = '/cas/' + Drupal.settings.campaign.campaign_root + '/mark-clickthrough/' + dest;
        return false;
      });

      var share_array = [];
      $('.facebook-share').each(function() {
        var picture = $(this).parent().parent().find('img').attr('src');
        var selector = $(this).attr('class').replace('facebook-share ', '');

        share_array.push(selector);

        $(this).click(function() {
          Drupal.behaviors.fb.feed({
            'feed_title' : settings.campaign.facebook.share.title,
            'feed_picture': picture,
            'feed_caption': settings.campaign.facebook.share.caption,
            'feed_description': settings.campaign.facebook.share.description,
            'feed_selector': selector,
            'feed_allow_multiple': false,
            'feed_noclick': true
          }, function(response) {
            var c = parseInt($('.' + selector + '-count').text());
            $('.' + selector + '-count').text(++c);
          });

          return false;
        });
      });

      Drupal.behaviors.fb.get_counts(share_array, null, function(counts) {
        for (i in counts) {
          $('.' + i + '-count').text(counts[i]);
        }
      });
    },

    tip_shares: function(settings) {
      if (settings.campaign.share_count == 2) {
        $.fn.dsCampaignPopup('tip', 0);
      }
    },
  };
})(jQuery);