(function($) {
  Drupal.behaviors.blahCampaign = {
    authed: false,
    probably_unauthed: false,
    notify_yourself: false,
    started_page: false,

    attach: function(context, settings) { 
      // Updates share buttons to disable ones you've already clicked.
      if (typeof Drupal.settings.campaign.shares === 'object') {
        for (i in Drupal.settings.campaign.shares) {
          $('.s-' + Drupal.settings.campaign.shares[i] + ' .vouch-button a[rel="' + Drupal.settings.campaign.shares[i] + '"]').addClass('clicked');
          $('.s-' + Drupal.settings.campaign.shares[i] + ' .bs-button a[rel="' + Drupal.settings.campaign.shares[i] + '"]').addClass('clicked');
        }
      }

      $('.bs-button a.button-submit').click(function() {
        if (!Drupal.behaviors.fb.is_authed() || !Drupal.behaviors.create_and_share.logged_in) {
          $.fn.dsCampaignPopup('share-login', 0, { 'goto': document.location.href });
        }

        if ($(this).hasClass('clicked')) {
          return false;
        }

        var elm = $(this);
        var no_alert = $(this).hasClass('no-alert');

        if ($(this).parent().parent().parent().hasClass('by-me') && Drupal.settings.campaign.origin == 2) {
          $.fn.dsCampaignPopup('bull', elm.attr('rel'), { 'you': true });
          no_alert = true;
        }

        $('.s-' + elm.attr('rel')).find('.vouch-button a').addClass('clicked');
        elm.addClass('clicked');

        var c = parseInt(elm.parent().find('span').text());
        elm.parent().find('span').text(++c);

        $.post('/cas/' + Drupal.settings.campaign.campaign_root + '/vote/down/' + elm.attr('rel'), { 'alert': no_alert, 'origin': document.location.pathname.substr(1,document.location.pathname.length) }, function(response) {
          if (response.status == 1) {
            elm.parent().find('span').text(response.count);
            settings.campaign.share_count++;
            Drupal.behaviors.blahCampaign.tip_shares(settings);

            if (!no_alert && Drupal.settings.campaign.allow_notifications) {
              var name = '';
              if (FB.getUserID()) {
                name = '@[' + FB.getUserID() + ']';
              }
              else {
                name = Drupal.t('Someone');
              }

              Drupal.behaviors.fb.notification({
                'notification_document': settings.campaign.campaign_root, // leave this like this
                'notification_user': response.author,
                'notification_template': settings.campaign.facebook.notification.message.replace('{name}', [name])
              }, function(response) { });
            }
          }
          else {
            elm.removeClass('clicked');
          }
        });

        return false;
      });

      $('.vouch-button a.button-submit').click(function() {
        if (!Drupal.behaviors.fb.is_authed() || !Drupal.behaviors.create_and_share.logged_in) {
          $.fn.dsCampaignPopup('share-login', 0, { 'goto': document.location.href });
        }

        if ($(this).hasClass('clicked')) {
          return false;
        }

        var no_alert = $(this).hasClass('no-alert');
        var elm = $(this);

        elm.addClass('clicked');

        $('.s-' + elm.attr('rel')).find('.bs-button a').addClass('clicked');
        var c = parseInt(elm.parent().find('span').text());
        elm.parent().find('span').text(++c);

        $.post('/cas/' + Drupal.settings.campaign.campaign_root + '/vote/up/' + elm.attr('rel'), { 'alert': no_alert, 'origin': Drupal.settings.campaign.origin }, function(response) {
          if (response.status == 1) {
            elm.parent().find('span').text(response.count);
            settings.campaign.share_count++;
            Drupal.behaviors.blahCampaign.tip_shares(settings);
          }
          else {
            elm.removeClass('clicked');
          }
        });

        return false;
      });

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
    },

    tip_shares: function(settings) {
      if (settings.campaign.share_count == 2) {
        $.fn.dsCampaignPopup('tip', 0);
      }
    },
  };
})(jQuery);