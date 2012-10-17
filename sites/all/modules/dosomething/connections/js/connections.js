(function($) {
  Drupal.behaviors.fb = {
    token: '',
    my_pic: '',

  	attach: function(context, settings) {
  	},

    // Initializes facebook and begins running tasks.
    init: function(options) {
      for (i in options) {
        Drupal.behaviors.fb.run(i, options[i]);
      }
    },

    // Runs Facebook tasks.
  	run: function(fun) {
  		var a = Array.prototype.slice.call(arguments);
  		var f = $('<div></div>').attr('class', 'fb-runner-' + fun).css('display', 'none').click(function() {
  			eval('Drupal.behaviors.fb.' + fun + '(a)');
  		});
  		f.appendTo($('body'));

  		// We need a slight timeout to make the pop-up actually work.  Facebook literally waits 'til
  		// the last second to initialize the FB object.  A .5 second delay is enough(!)
  		setTimeout('jQuery(".fb-runner-' + fun + '").click();', 1000);
  	},

    log: function(message) {
      if (typeof console !== 'undefined') {
        console.log(message);
      }
    },

    fb_dialog: function(page, things, callback) {
      var img, title, desc, caption;
      if (things.picture && things.picture != "''") {
        img = encodeURIComponent(things.picture);
      }
      else {
        img = encodeURIComponent($('meta[property="og:image"]').attr('content'));
      }

      if (things.title && things.title != "''") {
        title = encodeURIComponent(things.title);
      }
      else {
        title = encodeURIComponent($('meta[property="og:title"]').attr('content'));
      }

      if (things.description && things.description != "''") {
        desc = encodeURIComponent(things.description);
      }
      else {
        desc = encodeURIComponent($('meta[property="og:description"]').attr('content'));
      }

      if (things.caption && things.caption != "''") {
        caption = encodeURIComponent(things.caption);
      }
      else {
        caption = "";
      }

        var pic = '';
        var og = $('<div></div>').attr('class', 'og_dialog');

        var to = '';
        if (things.friends) {
          to = '&to=' + things.friends.join(',');
        }

        FB.api('/me/picture', function(response) {
          pic = response.data.url;
          og.load('/fb-connections/' + page + '?img=' + img + '&title=' + title + '&caption=' + caption + '&desc=' + desc + '&mypic=' + pic + to, function() {
            $('.close-fb-dialog').click(function() {
              // Fake cancel button to remove "fake" feed
              $('.og_dialog').dialog('close');
              Drupal.friendFinder.clear_friends();
              return false;
            });

            $('#submit-og-post').click(function() {
              things.comments = $('#fb_og_comments').val();

              callback(things);
              $('.og_dialog').dialog('close');
              og.html('&nbsp;');
            });
          });
        });
        og.dialog({
          dialogClass: 'og-post-dialog',
          width: 650,
          resizable: false,
          open: function() {
            if ($('#cancel-og-post').length) {
              // This somehow fixes an error where it wouldn't close after the first close
              // Don't ask me why.
              $('.og_dialog').html('&nbsp;');
            }
          }
        }).queue(function() {
          // Pretend like it's a Facebook dialog feed
          $('.og-post-dialog').css('background', 'transparent').find('.ui-dialog-titlebar').css('display', 'none');
        });
    },

    real_auth: function(things, callback) {
      if (things.require_login) {
        FB.getLoginStatus(function(response) {
          if (response.status == 'unknown') {
            // Not logged in.
            if (things.require_login == 1) {
              FB.login(function(response) {
                callback();
              });
            }
          }
          else if (response.status == 'not_authorized') {
            // Unauthorized
            if (things.require_login == 1) {
              FB.api('/me/permissions', function (response) {
                var perms = response.data[0];
                if (!perms.publish_actions) {
                  FB.ui({
                    method: 'permissions.request',
                    perms: 'publish_actions',
                    display: 'popup'
                  });
                }
              });
            }
          }
          else {
            // Logged in and authorized.
            callback();
          }
        });
      }
      else {
        callback();
      }
    },

    auth: function(callback) {
      FB.login(function(response) {
        Drupal.behaviors.fb.token = response.authResponse.accessToken;

        if (typeof callback !== 'undefined') {
          callback();
        }
      });
    },

  	feed: function(args) {
      var config = args[1];
      var things = {
      	link: config.feed_document,
        title: config.feed_title,
        picture: config.feed_picture,
        caption: config.feed_caption,
        description: config.feed_description,
      	selector: config.feed_selector,
        allow_multiple: config.feed_allow_multiple,
      	require_login: config.feed_require_login,
      };

      var share = {
        method: 'feed',
        //display: 'iframe',
        link: things.link,
        name: things.title,
      };

      /**
       *  Makes facebook revert to page elements if these aren't set.
       */

      // Title
      if (things.title) {
        share.name = things.title;
      }

      // Picture
      if (things.picture) {
        share.picture = things.picture;
      }

      // Caption
      if (things.caption) {
        share.caption = things.caption;
      }

      // Description
      if (things.description) {
        share.description = things.description;
      }

      if (things.selector) {
      	jQuery('body ' + things.selector).click(function() {
        	Drupal.behaviors.fb.feed_runner(things, share, function() {
            // Done callback
          });
        });
      }
      else {
        Drupal.behaviors.fb.feed_runner(things, share, function() {
          // Done callback
        });
      }

      return false;
  	},

    feed_runner: function(things, share, callback) {
      if (things.allow_multiple > 0) {
        var fbm = $('<input />').attr('type', 'button').addClass('fb-feed-friend-finder').css('display', 'none');
        fbm.appendTo('body').queue(function() {
          Drupal.friendFinder.t = things;
          Drupal.friendFinder($('.fb-feed-friend-finder'), 'publish_stream', function (friends) {
            var things = {};
            if (Drupal.friendFinder.t) {
              things = Drupal.friendFinder.t;
            }

            things.friends = friends;
            Drupal.behaviors.fb.fb_dialog('multi-feed', things, function(response) {
              var fbObj = {
                message: response.comments,
                name: response.title,
                picture: response.picture,
                description: response.description,
                caption: response.caption,
                link: response.link
              };

              for (var i in things.friends) {
                FB.api('/' + things.friends[i] + '/feed', 'post', fbObj, function(response) {
                  Drupal.behaviors.fb.log(response);
                });
              }

              // Callback for when all posting has completed.
              if (typeof callback == 'function') {
                callback();
              }
            });
          }, true);
        });
      }
      else {
        FB.ui(share);
        if (typeof callback == 'function') {
          callback();
        }
      }
    },

  	ograph: function(args) {
  		// OG Type, action, document, selector, require login, fake dialog
      var config = args[1];
  		var things = {
        namespace: config.og_namespace,
  			type: config.og_type,
  			action: config.og_action,
  			link: config.og_document,
        picture: config.og_post_image,
        description: config.og_post_description,
  			selector: config.og_selector,
  			require_login: config.og_require_login,
  			dialog: config.og_fake_dialog,
        custom_vars: config.og_post_custom
  		};

  		var fbpost = {};
      // fbpost.TYPE = ACTION
  		eval('fbpost.' + args[2] + ' = "' + args[4] + '";');

      if (things.custom_vars) {
        for (i in things.custom_vars) {
          eval('fbpost.' + i + ' = "' + things.custom_vars[i] + '";');
        }
      }

      // Maintain custom image through the open graph call.
      if (things.picture) {
        fbpost.image = things.picture;
      }

      if (things.dialog == 1) {
        if (things.selector) {
          $('body ' + things.selector).click(function() {
            Drupal.behaviors.fb.ograph_message(things, fbpost);
          });
        }
        else {
          Drupal.behaviors.fb.ograph_message(things, fbpost);
        }
      }
      else {
        if (things.selector) {
          $('body ' + things.selector).click(function() {
            Drupal.behaviors.fb.run_ograph(things, fbpost);
          });
        }
        else {
          Drupal.behaviors.fb.run_ograph(things, fbpost);
        }
      }

  		return false;
  	},

    ograph_message: function(things, fbpost) {
      Drupal.behaviors.fb.real_auth(things, function() {
        Drupal.behaviors.fb.fb_dialog('og-post', things, function(response) {
          if (response.comments) {
            fbpost.message = response.comments;
          }
          Drupal.behaviors.fb.run_ograph(things, fbpost);
        });
      });
    },

    run_ograph: function(things, fbpost) {
      Drupal.behaviors.fb.log(fbpost);
      Drupal.behaviors.fb.real_auth(things, function() {
        FB.api(
          '/me/' + things.namespace + ':' + things.action,
          'post',
          fbpost,
          function (response) {
            if (typeof console !== 'undefined') {
              Drupal.behaviors.fb.log(response);
            }
          }
        );
      });
    },

    request: function(args) {
      var things = {
        title: args[1],
        message: args[2],
        selector: args[3],
        require_login: args[4]
      };

      var req = {
        method: 'apprequests',
        display: 'iframe',
        title: things.title,
        message: things.message,
      };

      if (things.require_login) {
        if (things.selector) {
          $('body ' + things.selector).click(function() {
            Drupal.behaviors.fb.auth(function() {
              req.access_token = Drupal.behaviors.fb.token;
              FB.ui(req);
            });
          });
        }
        else {
          Drupal.behaviors.fb.auth(function() {
            req.access_token = Drupal.behaviors.fb.token;
            FB.ui(req);
          });
        }
      }
      else {
        // Nothing.  They need to be logged in to use the app request dialog.
      }
    },

    message: function(args) {
      var things = {
        link: args[1],
        image: args[2],
        selector: args[3],
        require_login: args[4],
        allow_multiple: args[5]
      };

      Drupal.behaviors.fb.real_auth(things, function() {
        Drupal.behaviors.fb.message_dialog(things);
      });
    },

    message_dialog: function(things) {
      var m = {
        method: 'send', 
        link: things.link,
      };

      if (things.image) {
        m.picture = things.image;
      }

      if (things.selector) {
        $('body ' + things.selector).click(function() {
          FB.ui(m);
        })
      }
      else {
        FB.ui(m);
      }
    }
  };
})(jQuery);
