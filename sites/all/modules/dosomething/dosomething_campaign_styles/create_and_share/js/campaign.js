(function($) {
  Drupal.behaviors.create_and_share = {
    attach: function(context, settings) { 
      if ($('body').hasClass('not-logged-in')) {
        Drupal.behaviors.dsCrazyScripts.logged_in = false;
      }

      /**
       *  Handles flagging for campaign posts.  Users need to have permission to flag posts to use this.
       */
      $('.flag a').click(function() {
      	if (Drupal.settings.can_flag_posts) {
          var i = $(this);
          var l = $(this).parent().parent().parent();
          $.post('/cas/' + Drupal.settings.campaign.campaign_root + '/flag/' + $(this).attr('data-sid'), {}, function(response) {
            if (response == 1) {
              l.addClass('flagged');
              i.children('span').text('Unflag');
            }
            else if (response == 0) {
              l.removeClass('flagged');
              i.children('span').text('Flag');
            }
          });
        }

        return false;
      });

      if ($('.single-post-share a.share-on-facebook').length) {
        $('.single-post-share a.share-on-facebook').click(function() {
          $('.fb-share a').click();
          return false;
        });
      }

      if (top.location != self.location) {
        top.location = self.location.href
      }

      if (Drupal.settings.campaign.allow_lazy_loading) {
        if ($('img.lazy').length > 0) {
          $('img.lazy').lazyload();
        }
      }

      // Fix for SUPER weird first-image cache problem.
      if ($('img[data-num="2"]').length > 0) {
        $('img[data-num="2"]').each(function() {
          var $src = $(this).attr('src');
          $(this).attr('src', $src + '?' + new Date().getTime());
        });
      }
    },

    fb_invite_friends_post: function(sid, reload) {
      $('.bull-crazy-popup,.share-crazy-popup').remove();
  
      Drupal.behaviors.fb.ask_permission('publish_stream', { 'display': 'iframe' }, function(res) {
      if (!(typeof res === 'object' && res.perms == 'publish_stream')) {
          return false;
        }
  
        var img = 'http://files.dosomething.org/files/campaigns/crazy13/logo.png';
        var path = 'http://www.dosomething.org/' + Drupal.settings.campaign.campaign_root + '/friends';
        if (sid > 0) {
          if (typeof my_post === 'object' && my_post.sid == sid) {
            if (my_post.image) {
              img = my_post.image;
          }
            else {
              img = $('.s-' + sid + '-picture img').attr('src');
            }
          }
        else {
            img = $('.s-' + sid + '-picture img').attr('src');
          }
  
          path = 'http://www.dosomething.org/' + Drupal.settings.campaign.campaign_root + '/friends/' + sid;
        }
  
        Drupal.behaviors.fb.feed({
          feed_document: path,
          feed_title: Drupal.settings.campaign.facebook.posts.title,
          feed_picture: img,
          feed_caption: Drupal.settings.campaign.facebook.posts.caption,
          feed_description: Drupal.settings.campaign.facebook.posts.description,
          feed_allow_multiple: true,
          feed_max_friends: 25,
          feed_modal: false,
          feed_friend_selector: 'td',
        }, function(response) {
          $.post('/' + Drupal.settings.campaign.campaign_root + '/submit-vouch-request/' + sid, { 'friends': response.friends, 'origin': Drupal.settings.campaign.origin }, function(v) {});
        });
  
        return false;
      });

      return false;
    },

    fb_invite_friends: function() {
      Drupal.behaviors.fb.ask_permission('publish_stream', { 'display': 'iframe' }, function(res) {
        if (!(typeof res === 'object' && res.perms == 'publish_stream')) {
          return false;
        }

        Drupal.behaviors.fb.feed({
          feed_document: Drupal.settings.campaign.facebook.invite.document,
          feed_title: Drupal.settings.campaign.facebook.invite.title,
          feed_picture: Drupal.settings.campaign.facebook.invite.image,
          feed_caption: Drupal.settings.campaign.facebook.invite.caption,
          feed_description: Drupal.settings.campaign.facebook.invite.description,
          feed_allow_multiple: true,
          feed_max_friends: 25,
          feed_modal: false,
          feed_friend_selector: 'td',
        }, function(response) {});
  
        return false;
      });

      return false;
    },

    fb_auth: function(type, status) {
      var status;
      Drupal.behaviors.fb.is_authed(function(response) {
        if (response.status == 'unknown' || response.status == 'not_authorized') {
          status = 0;
        }
        else {
          status = 1;
        }
      });
  
      if (!status || $('body').hasClass('not-logged-in')) {
        if (type == 'login') {
          $.fn.dsCrazyPopup('login', 0);
          return false;
        }
        else {
          $.fn.dsCrazyPopup('submit', 0);
          return false;
        }
  
        return true;
      }
      else {
        return true;
      }
    }
  };

  $.fn.extend({
    dsCampaignPopup: function (name, sid, settings) {
      if (!settings) { settings = {}; }
      if (settings.reload) {
        jQuery('.s-' + sid + '-picture img').attr('src', jQuery('.s-' + sid + '-picture img').attr('src') + '?' + new Date().getTime());
      }

      // Ignore if the popup is already open.
      if ($('.' + name + '-crazy-popup').length > 0) return;
        $.post('/cstemplate/' + name + '/' + sid, { 'goto': settings.goto, 'you': (Drupal.behaviors.dsCrazyScripts.notify_yourself || settings.you), 'source': document.location.pathname }, function(response) {
          var t = $('<div></div>');
          t.html(response);

          t.dialog({
            resizable: false,
            draggable: false,
            modal: true,
            width: 550,
            height: 325,
            'dialogClass': (name == 'share-login' ? 'login' : name) + '-crazy-popup',
            open: function() {
              // Sets the minimum height for content in the dialog box
              $('.ui-dialog-content').css('min-height', '325px');
            },
            close: function() {
              $('.' + name + '-crazy-popup').remove();
            }
        });
      });

      return false;
    }
  });  
})(jQuery);