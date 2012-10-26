/**
 *  Drupal.behaviors.fb -> Site-wide Facebook integration.
 *  Mainly used through the user interface, but can be extended through custom code as well.
 *  Usage:
 *    Initialize a javascript options object (with curly braces - { }) with the following format:
 *
 *    {
 *       function: {
 *         // parameters
 *       }
 *    }
 *
 *  "function" should be a method referenced below.  This structure also allows for multiple actions.
 *  If several functions are passed in the options object, they will all be initialized, though not necessarily
 *  run automatically (this is dependent on the options that are passed to each function).
 *
 *  See function documentation for paremeters.
 */

(function($) {
  Drupal.behaviors.fb = {
    token: '',
    my_pic: '',
    fb_init: false,
    _feed_callback: null,
    _ograph_callback: null,
    _message_callback: null,
    _request_callback: null,

    /**
     *  Initializes the Facebook object and runs all appropriate functions.
     */
    init: function(options) {
      var fb_init = window.setInterval(function () {
        if (typeof FB !== 'undefined') {
          window.clearInterval(fb_init);
          for (i in options) {
            Drupal.behaviors.fb.run(i, options[i]);
          }
        }
      }, .1);
    },

    // Runs Facebook tasks.
  	run: function(fun) {
  		var a = Array.prototype.slice.call(arguments);
      eval('Drupal.behaviors.fb.' + fun + '(a[1])');

  		/*var f = $('<div></div>').attr('class', 'fb-runner-' + fun).css('display', 'none').click(function() {
  			eval('Drupal.behaviors.fb.' + fun + '(a[1])');
  		});
  		f.appendTo($('body'));

  		// We need a slight timeout to make the pop-up actually work.  Facebook literally waits 'til
  		// the last second to initialize the FB object.  A .5 second delay is enough(!)
  		setTimeout('jQuery(".fb-runner-' + fun + '").click();', 1000);*/
  	},

    /**
     *  Multi-browser safe console.log
     */
    log: function(message) {
      if (typeof console !== 'undefined') {
        console.log(message);
      }
    },

    /**
     *  Creates the mock Facebook dialog that allows us to extend Facebook functionality.
     *  this should not be called outside of the Facebook object.
     */
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
        position: { my: 'top', at: 'top', of: 'body', offset: '0 180' },
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

    /**
     *  Authenticates a user based off of the criteria set in the things object.
     *  If we require users to log in and they are not logged in, they are prompted to do so.
     *  Also confirms the correct permissions (particularly publish_actions) before posting.
     *
     *  @param things
     *    A javascript object of important configuration variables.  The only variable used in this
     *    function is things.require_login.
     *       require_login
     *
     *  @param callback
     *    A callback function to run after a user is logged in and authenticated.  This function
     *    is run automatically if we don't require logging in.
     *
     */
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
                if (response.error) {
                  FB.login(function(response) {
                    callback();
                  }, { scope: 'publish_actions' })
                }
                else {
                  var perms = response.data[0];
                  if (!perms.publish_actions && !asked) {
                    FB.ui({
                      method: 'permissions.request',
                      perms: 'publish_actions',
                      display: 'popoup'
                    }, function(response) {
                      callback();
                    });
                  }
                }
              });
            }
          }
          else {
            // Logged in and authorized.
            FB.api('/me/permissions', function (response) {
              var perms = response.data[0];
              if (!perms.publish_actions) {
                FB.ui({
                  method: 'permissions.request',
                  perms: 'publish_actions',
                  display: 'popup'
                }, function(response) {
                  callback();
                });
              }
              else {
                callback();
              }
            });
          }
        });
      }
      else {
        callback();
      }
    },

    /**
     *  FB.getLoginStatus doesn't always work for authentication -- Another alternative
     *  is to call FB.login.  Facebook will throw a notice that a user is already
     *  logged in if that is so...but that doesn't stop things from happening.
     *
     *  @param callback
     *     A callback function that is run when a user is confirmed logged in.
     *
     */
    auth: function(callback) {
      FB.login(function(response) {
        if (response.authResponse.accessToken) {
          Drupal.behaviors.fb.token = response.authResponse.accessToken;

          if (typeof callback !== 'undefined') {
            callback();
          }
        }
      });
    },

    /**
     *  Feed function -- builds the standard facebook feed dialog.
     *  
     *
     *  @param config
     *    A javascript object of configuration opens.  Available options:
     *       feed_document         (An absolute url of the page to share)
     *       feed_title            (The title of the share)
     *       feed_picture          (The picture that is displayed on the share)
     *       feed_caption          (The caption that appears under the share title)
     *       feed_description      (The description that appears under the caption)
     *       feed_selector         (A selector on the page to call the event on)
     *       feed_allow_multiple   (Uses the TD Friend Selector to allow multiple friends to be posted-to)
     *       feed_require_login    (Initializes the login procedure if a user is not logged in.)
     *
     *  @param callback
     *    A callback function which triggers when a post was succesfully made.
     *    
     */
  	feed: function(config, callback) {
      var things = {
      	link: config.feed_document,
        title: config.feed_title,
        picture: config.feed_picture,
        caption: config.feed_caption,
        description: config.feed_description,
      	selector: config.feed_selector,
        allow_multiple: config.feed_allow_multiple,
        max_friends: config.feed_max_friends || 5,
        selector_title: config.feed_selector_title || Drupal.t('Share with your friends'),
      	require_login: config.feed_require_login,
      };

      if (typeof callback == 'undefined' && typeof Drupal.behaviors.fb._feed_callback == 'function') {
        callback = Drupal.behaviors.fb._feed_callback;
      }

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
        	Drupal.behaviors.fb.feed_runner(things, share, callback);
        });
      }
      else {
        Drupal.behaviors.fb.feed_runner(things, share, callback);
      }

      return false;
  	},

    /**
     *  Processing function for the feed dialog.  Checks if a user can select multiple
     *  friends at once, and if so uses the TD Friend Selector to let them do that.
     *  Otherwise, calls the FB.ui() function.
     */
    feed_runner: function(things, share, callback) {
      // If we are allowing people to post to multiple walls...
      if (things.allow_multiple > 0) {
        Drupal.behaviors.fb.real_auth(things, function() {
          var c;
          if (!things) {
            c = {};
          }
          else {
            c = {
              max_friends: things.max_friends,
              selector_title: things.selector_title
            };
          }

          // Create a mock button on the site to simulate a click-through on the friendSelector
          var fbm = $('<input />').attr('type', 'button').addClass('fb-feed-friend-finder').css('display', 'none');
          fbm.appendTo('body').queue(function() {
            Drupal.friendFinder.t = things;
            Drupal.friendFinder($('.fb-feed-friend-finder'), 'publish_stream', function (friends) {
              var things = {};
              if (Drupal.friendFinder.t) {
                things = Drupal.friendFinder.t;
              }

              if (friends.length > 0) {
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
              }
            }, c, true);
          });
        });
      }
      else {
        FB.ui(share, function() {
          if (typeof callback == 'function') {
            callback();
          }
        });
      }
    },

    /**
     *  Performs Open Graph actions, specifically posting to a user's wall.
     *
     *  @param config
     *    A javascript object of configuration opens.  Available options:
     *       og_namespace         (The namespace of the app to use.)
     *       og_type              (The open graph object to use.)
     *       og_action            (The open graph action to use.)
     *       og_post_title        (The title that will appear in the share dialog.  Ignored in the actual post.)
     *       og_post_image        (An (optional) image to be sent with the Open Graph call.)
     *       og_post_description  (The description that appears under the caption)
     *       og_selector          (A selector on the page to call the event on)
     *       og_allow_multiple    (Uses the TD Friend Selector to allow multiple friends to be posted-to)
     *       og_require_login     (Initializes the login procedure if a user is not logged in.)
     *       og_fake_dialog       (Whether or not to use the "Fake" dialog that lets users post message with the share)
     *       og_post_custom       (Custom variables as set on the user interface.)
     *
     *  @param callback
     *    A callback function which triggers when a post was succesfully made.
     *    
     */
  	ograph: function(config, callback) {
  		// OG Type, action, document, selector, require login, fake dialog
  		var things = {
        namespace: config.og_namespace,
  			type: config.og_type,
  			action: config.og_action,
        title: config.og_title || null,
  			link: config.og_document || document.location.href,
        picture: config.og_post_image,
        description: config.og_post_description,
  			selector: config.og_selector,
  			require_login: config.og_require_login,
  			dialog: config.og_fake_dialog,
        custom_vars: config.og_post_custom
  		};

      if (typeof callback == 'undefined' && typeof Drupal.behaviors.fb._ograph_callback == 'function') {
        callback = Drupal.behaviors.fb._ograph_callback;
      }

  		var fbpost = {
        //'fb:explicitly_shared': true
      };
      // fbpost.TYPE = LINK
  		eval('fbpost.' + things.type + ' = "' + things.link + '";');

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
            Drupal.behaviors.fb.ograph_message(things, fbpost, callback);
          });
        }
        else {
          Drupal.behaviors.fb.ograph_message(things, fbpost, callback);
        }
      }
      else {
        if (things.selector) {
          $('body ' + things.selector).click(function() {
            Drupal.behaviors.fb.run_ograph(things, fbpost, callback);
          });
        }
        else {
          Drupal.behaviors.fb.run_ograph(things, fbpost, callback);
        }
      }

  		return false;
  	},

    /**
     *  Pops up a fake "Facebook" dialog box which lets users share
     *  a message with their open graph post.
     */
    ograph_message: function(things, fbpost, callback) {
      Drupal.behaviors.fb.real_auth(things, function() {
        Drupal.behaviors.fb.fb_dialog('og-post', things, function(response) {
          if (response.comments) {
            fbpost.message = response.comments;
          }
          Drupal.behaviors.fb.run_ograph(things, fbpost, callback);
        });
      });
    },

    /**
     *  Performs the actual Open Graph call, using variables defined in the ograph function.
     */
    run_ograph: function(things, fbpost, callback) {
      Drupal.behaviors.fb.log(fbpost);
      Drupal.behaviors.fb.real_auth(things, function() {
        FB.api(
          '/me/' + things.namespace + ':' + things.action,
          'post',
          fbpost,
          function (response) {
            if (typeof callback == 'function') {
              callback(response);
            }
          }
        );
      });
    },

    /**
     *  Creates an App Request dialog.
     *
     *  @param config
     *    A javascript object of configuration options.  Available options:
     *       app_request_title             (An (optional) title for the app request dialog)
     *       app_request_message           (An (optional) message to send to the user who is receiving the request.)
     *       app_request_selector          (A selector on the page to call the event on)
     *       app_request_require_login     (An (optional) image to be sent with the Open Graph call.)
     *
     *  @param callback
     *    A callback function which triggers when an app request was sent to Facebook.
     *    
     */
    request: function(config, callback) {
      var things = {
        title: config.app_request_title,
        message: config.app_request_message,
        selector: config.app_request_selector,
        require_login: config.app_request_require_login
      };

      if (typeof callback == 'undefined' && typeof Drupal.behaviors.fb._request_callback == 'function') {
        callback = Drupal.behaviors.fb._request_callback;
      }

      var req = {
        method: 'apprequests',
        display: 'iframe',
      };

      if (things.title) {
        req.title = things.title;
      }

      if (things.message) {
        req.message = things.message;
      }

      if (things.require_login) {
        if (things.selector) {
          $('body ' + things.selector).click(function() {
            Drupal.behaviors.fb.auth(function() {
              req.access_token = Drupal.behaviors.fb.token;
              FB.ui(req, function() {
                if (typeof callback == 'function') {
                  callback();
                }
              });
            });
          });
        }
        else {
          Drupal.behaviors.fb.auth(function() {
            req.access_token = Drupal.behaviors.fb.token;
            FB.ui(req, function() {
              if (typeof callback == 'function') {
                callback();
              }
            });
          });
        }
      }
      else {
        // Nothing.  They need to be logged in to use the app request dialog.
      }
    },

    /**
     *  Initializes the Facebook message service.
     *
     *  @param config
     *    A javascript object of configuration options.  Available options:
     *       msg_document          (An (optional) absolute URL to share through the message.)
     *       msg_picture           (An (optional) picture to send with the message.)
     *       msg_selector          (A selector on the page to call the event on)
     *       msg_require_login     (Prompts a user to log into Facebook if they aren't already.)
     *
     *  @param callback
     *    A callback function which triggers when a post was succesfully made.
     *    
     */
    message: function(config, callback) {
      var things = {
        link: config.msg_document,
        image: config.msg_picture,
        selector: config.msg_selector,
        require_login: config.msg_require_login,
        allow_multiple: 0 // Not possible :(
      };

      if (typeof callback == 'undefined' && typeof Drupal.behaviors.fb._message_callback == 'function') {
        callback = Drupal.behaviors.fb._message_callback;
      }

      Drupal.behaviors.fb.real_auth(things, function() {
        Drupal.behaviors.fb.message_dialog(things);
      });
    },

    /**
     *  Builds the Facebook message dialog.
     */
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
