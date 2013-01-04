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
    debug: false,
    fb_init: false,
    _feed_callback: null,
    _ograph_callback: null,
    _message_callback: null,
    _request_callback: null,
    _image_callback: null,
    _notification_callback: null,
    _gate_callback: null,

    /**
     *  Initializes the Facebook object and runs all appropriate functions.
     */
    init: function(options) {
      var fb_init = window.fbAsyncInit;
      window.fbAsyncInit = function() {
        fb_init();

        for (i in options) {
          Drupal.behaviors.fb.run(i, options[i]);
        }
      }
    },

    // Runs Facebook tasks.
  	run: function(fun) {
  		var a = Array.prototype.slice.call(arguments);
      eval('Drupal.behaviors.fb.' + fun + '(a[1])');
  	},

    /**
     *  Multi-browser safe console.log
     */
    clog: function(message) {
      if (typeof console !== 'undefined') {
        console.log(message);
      }
    },

    /**
     *  Logs Facebook actions.
     */
    log: function(action, key, to) {
      var fbid = FB.getUserID();
      if (!fbid) {
        fbid = 0;
      }

      $.post('/fb/log', { 'fbid': fbid, 'link': document.location.href, 'action': action, 'key': key, 'to': to }, function(response) {
        //Drupal.behaviors.fb.clog(response);
      });
    },

    /**
     *  Checks to see if the logged in Facebook user has a permission.
     */
    has_permission: function(permission) {
      FB.api('/me/permissions', function (response) {
        if (response.error) {
          return false;
        }
        else {
          var perms = response.data[0];
          if (!perms[permission]) {
            return false;
          }
          else {
            return true;
          }
        }
      });
    },

    /**
     *  Asks for a permission.
     */
    ask_permission: function(permission, callback) {
      FB.api('/me/permissions', function (response) {
        if (response.error) {
          FB.login(function(response) {
            callback();
          }, { scope: permission })
        }
        else {
          var perms = response.data[0];
          if (!perms[permission]) {
            FB.ui({
              method: 'permissions.request',
              perms: permission,
              display: 'popup'
            }, function(response) {
              callback();
            });
          }
          else {
            callback();
          }
        }
      });
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
      if ($('.og_dialog').length > 0) {
        $('.og_dialog').remove();
      }
      var og;
      og = $('<div></div>').addClass('og_dialog ' + page);

      var to = '';
      if (things.friends) {
        to = '&to=' + things.friends.join(',');
      }

      var tag = '';
      if (things.tagging == 1) {
        tag = '&tagging=1';
      }

      var msg = '';
      if (things.alert_msg) {
        msg = '&message=' + encodeURIComponent(things.alert_msg);
      }

      FB.api('/me/picture', function(response) {
        pic = response.data.url;
        og.load('/fb-connections/' + page + '?img=' + img + '&title=' + title + '&caption=' + caption + '&desc=' + desc + '&mypic=' + pic + to + tag + msg, function() {

          $(this).dialog({
            dialogClass: 'og-post-dialog',
            width: (page == 'custom-selector' ? 800 : 650),
            position: { my: 'top', at: 'top', of: 'body', offset: '0 180' },
            resizable: false,
            modal: (things.modal ? true : false),
            open: function() {
              if ($('#cancel-og-post').length) {
                // This somehow fixes an error where it wouldn't close after the first close
                // Don't ask me why.
                //$('.og_dialog').html('&nbsp;');
              }
            },
            close: function() {
              if (things.modal) {
                if (jQuery('#fb-modal').length > 0) {
                  jQuery('#fb-modal').remove();
                }
              }

              //og.remove();
              //delete og;
            }
          }).queue(function() {
            // Pretend like it's a Facebook dialog feed
            $('.og-post-dialog').css('background', 'transparent').find('.ui-dialog-titlebar').css('display', 'none');

            // Cancel
            $('.close-fb-dialog').click(function() {
              // Fake cancel button to remove "fake" feed
              $('.og_dialog').dialog('close').remove();
              Drupal.friendFinder.clear_friends();
              return false;
            });

            // Submit
            $('#submit-og-post').click(function() {
              if ($('#hidden_comments').length > 0 && $('#hidden_comments').val() != '') {
                things.comments = $('#hidden_comments').val();
              }
              else {
                things.comments = $('#fb_og_comments').val();
              }

              things.explicitly_shared = $('#explicit-share').is(':checked');

              if (things.friend_selector == 'custom') {
                if (!Drupal.behaviors.fb.has_permission('publish_stream')) {
                  Drupal.behaviors.fb.ask_permission('publish_stream', function() {
                    callback(things);
                  });
                }
              }
              else {
                callback(things);
              }

              $('.og_dialog').dialog('close');
              //og.remove();
              //delete og;
            });
          });;
        });
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
                callback(response);
              });
            }
          }
          else if (response.status == 'not_authorized') {
            // Unauthorized
            if (things.require_login == 1) {
              FB.api('/me/permissions', function (response) {
                if (response.error) {
                  FB.login(function(response) {
                    callback(response);
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
                      callback(response);
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
                  callback(response);
                });
              }
              else {
                callback({ status: true });
              }
            });
          }
        });
      }
      else {
        callback({ status: true });
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
     *  Handles authentication through targeted click or page-load trigger.
     *  
     *  @param func
     *    The function to run.
     *
     *  @param things
     *    The things object, with configuration information.
     *
     *  @param callback
     *    Optional callback function.
     */
    auth_handler: function(func, things, callback) {
      // You can't call arguments from this function in the function passed below.  We need to add them to the FB scope to pass them.
      Drupal.behaviors.fb.t = things;
      Drupal.behaviors.fb.callback = callback;

      var handler = ( new Function('return Drupal.behaviors.fb.' + func + '(Drupal.behaviors.fb.t, Drupal.behaviors.fb.callback)'));
      if (things.require_login) {
        if (things.selector) {
          $('body ' + things.selector).click(function() {
            Drupal.behaviors.fb.real_auth(things, function() {
              handler();
            });
          });
        }
        else {
          Drupal.behaviors.fb.real_auth(things, function() {
            handler();
          });
        }
      }
      else {
        handler();
      }
    },

    /**
     *  Feed function -- builds the standard facebook feed dialog.
     *  
     *
     *  @param config
     *    A javascript object of configuration options.  Available options:
     *       feed_document         (An absolute url of the page to share)
     *       feed_title            (The title of the share)
     *       feed_picture          (The picture that is displayed on the share)
     *       feed_caption          (The caption that appears under the share title)
     *       feed_description      (The description that appears under the caption)
     *       feed_selector         (A selector on the page to call the event on)
     *       feed_allow_multiple   (Uses the TD Friend Selector to allow multiple friends to be posted-to)
     *       feed_require_login    (Initializes the login procedure if a user is not logged in.)
     *       feed_dialog_msg       (An optional message that will appear on the top of the share dialog.  Only appears if multi-friend-selecting is enabled.)
     *
     *  @param callback
     *    A callback function which triggers when a post was succesfully made.
     *    
     */
  	feed: function(config, callback) {
      var things = {
      	link: config.feed_document || document.location.href,
        title: config.feed_title,
        picture: config.feed_picture,
        caption: config.feed_caption,
        description: config.feed_description,
      	selector: config.feed_selector,
        allow_multiple: config.feed_allow_multiple,
        max_friends: config.feed_max_friends || 5,
        selector_title: config.feed_selector_title || Drupal.t('Share with your friends'),
        selector_desc: config.feed_selector_desc,
        tagging: config.feed_tagging,
      	require_login: config.feed_require_login,
        alert_msg: config.feed_dialog_msg,
        modal: config.feed_modal || false,
        friend_selector: config.feed_friend_selector || 'td',
        check_remainder: false,
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

      if (things.friend_selector && things.friend_selector == 'custom') {
        things.modal = true;
      }

      if (things.selector) {
      	jQuery('body ' + things.selector).click(function() {
        	Drupal.behaviors.fb.feed_runner(things, share, callback);
          return false;
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
      if (things.modal) {
        var m = $('<div></div>').css({
          'width': '100%',
          'height': jQuery(document).height(),
          'background': '#000',
          'opacity': '0.98',
          'position': 'absolute',
          'z-index': 25,
          'top': '0px',
        }).attr('id', 'fbc-modal');

        m.appendTo(jQuery('body'));
      }

      if (things.allow_multiple > 0) {
        Drupal.behaviors.fb.real_auth(things, function(response) {
          Drupal.behaviors.fb.log('Feed Dialog', 1);
          var c;
          if (!things) {
            c = {};
          }
          else {
            c = {
              max_friends: things.max_friends,
              selector_title: things.selector_title,
              selector_desc: things.selector_desc
            };
          }

          if (things.friend_selector == 'td') {
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
                      Drupal.behaviors.fb.send_feed_post(things.friends[i], fbObj);
                    }

                    // Callback for when all posting has completed.
                    Drupal.behaviors.fb.callback_handler(callback, things);
                  });
                }
              }, c, true);
            });
          }
          else if (things.friend_selector == 'custom') {
            Drupal.behaviors.fb.fb_dialog('custom-selector', things, function(response) {
              var msgs = [];
              var left = [];

              var fbObj = {
                message: '',
                name: response.title,
                picture: response.picture,
                description: response.description,
                caption: response.caption,
                link: response.link
              };

              var mypost = ($('#your-info').hasClass('submitted'));
              if (mypost) {
                var v = $('.my-post').val();
                if (v !== '') {
                  var o = {
                    og_namespace: 'dosomethingapp',
                    og_type: 'petition',
                    og_action: 'sign',
                    og_title: response.title,
                    og_document: response.link,
                    og_post_image: response.picture,
                    og_post_description: response.description,
                    message: v,
                    og_selector: null,
                    og_require_login: false,
                  };

                  if (response.explicitly_shared) {
                    o.explicit = true;
                  }

                  Drupal.behaviors.fb.ograph(o, function(response) {
                    Drupal.behaviors.fb.clog(response);
                  });
                }
              }

              $('.friend').each(function() {
                if ($(this).hasClass('selected')) {
                  var id = $(this).attr('rel');
                  msgs[id] = $(this).find('.personal-message').val();
                }
              });

              for (i in msgs) {
                if (msgs[i] != '' || (msgs[i] == '' && response.check_remainder === false)) {
                  fbObj['message'] = msgs[i];

                  delete msgs[i];
                  Drupal.behaviors.fb.send_feed_post(i, fbObj);
                }
                else {
                  left.push(i);
                }
              }

              if (left.length > 0 && response.check_remainder) {
                Drupal.behaviors.fb.clog('Some friends left.  Loading the final share block...');
                response.friends = left;
                response['alert_msg'] = Drupal.t("Wait! We found some friends that you haven't shared a message with.  Do you want to share on their walls too?");
                Drupal.behaviors.fb.fb_dialog('multi-feed', response, function(response) {
                   var fbObj = {
                     message: response.comments,
                     name: response.title,
                     picture: response.picture,
                     description: response.description,
                     caption: response.caption,
                     link: response.link
                   };

                   for (var i in things.friends) {
                     //Drupal.behaviors.fb.send_feed_post(things.friends[i], fbObj);
                   }

                   // Callback for when all posting has completed.
                   Drupal.behaviors.fb.callback_handler(callback, '');
                });
              }

              if (typeof $.fn.dsPetitionSubmit == 'function') {
                $.fn.dsPetitionSubmit();
              }
            });
          }
        });
      }
      else {
        FB.ui(share, function(response) {
          Drupal.behaviors.fb.callback_handler(callback, response);
          Drupal.behaviors.fb.log('Feed Post', 2);
        });

        if ($('#fbc-modal').length > 0) {
          var img = window.setInterval(function() {
            if ($('.fb_dialog').find('iframe').length == 0) {
              window.clearInterval(img);
              $('#fbc-modal').remove();
            }
          });
        }
      }
    },

    /**
     *  Actually sends the Facebook Feed post.
     *
     *  @param friendid
     *    The facebook ID of the person to send the post to.
     *
     *  @param post
     *    An object of Facebook feed parameters.
     *
     */
    send_feed_post: function(friendid, post) {
      FB.api('/' + friendid + '/feed', 'post', post, function(response) {
         Drupal.behaviors.fb.clog(response);
         Drupal.behaviors.fb.log('Feed Post', 2, friendid);
      });
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
     *       og_dialog_msg        (An optional message that will appear on the top of the share dialog)
     *       og_post_custom       (Custom variables as set on the user interface.)
     *
     *  @param callback
     *    A callback function which triggers when a post was succesfully made.
     *    
     */
  	ograph: function(config, callback) {
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
        alert_msg: config.og_dialog_msg,
        tagging: config.og_tagging,
        custom_vars: config.og_post_custom,
        message: config.message || '',
        explicit: config.explicit || false,
  		};

      if (typeof callback == 'undefined' && typeof Drupal.behaviors.fb._ograph_callback == 'function') {
        callback = Drupal.behaviors.fb._ograph_callback;
      }

  		var fbpost = {
        //'fb:explicitly_shared': true
      };
      // fbpost.TYPE = LINK
  		fbpost[things.type] = things.link;

      if (things.custom_vars) {
        for (i in things.custom_vars) {
          fbpost[i] = things.custom_vars[i];
        }
      }

      // Maintain custom image through the open graph call.
      if (things.picture) {
        fbpost.image = things.picture;
      }

      if (things.message) {
        fbpost.message = things.message;
      }

      if (things.explicit) {
        fbpost['fb:explicitly_shared'] = things.explicit;
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
          Drupal.behaviors.fb.log('Open Graph Dialog', 1);

          if (response.comments) {
            fbpost.message = response.comments;
          }

          if (response.explicitly_shared) {
            fbpost['fb:explicitly_shared'] = response.explicitly_shared;
          }

          Drupal.behaviors.fb.run_ograph(things, fbpost, callback);
        });
      });
    },

    /**
     *  Performs the actual Open Graph call, using variables defined in the ograph function.
     */
    run_ograph: function(things, fbpost, callback) {
      Drupal.behaviors.fb.clog(fbpost);
      Drupal.behaviors.fb.real_auth(things, function() {
        FB.api(
          '/me/' + things.namespace + ':' + things.action,
          'post',
          fbpost,
          function (response) {
            Drupal.behaviors.fb.callback_handler(callback, response);
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
              FB.ui(req, function(response) {
                Drupal.behaviors.fb.callback_handler(callback, response);
              });
            });
          });
        }
        else {
          Drupal.behaviors.fb.auth(function() {
            req.access_token = Drupal.behaviors.fb.token;
            FB.ui(req, function(response) {
              Drupal.behaviors.fb.callback_handler(callback, response);
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
        Drupal.behaviors.fb.message_dialog(things, callback);
      });
    },

    /**
     *  Builds the Facebook message dialog.
     */
    message_dialog: function(things, callback) {
      var m = {
        method: 'send', 
        link: things.link,
      };

      if (things.image) {
        m.picture = things.image;
      }

      if (things.selector) {
        $('body ' + things.selector).click(function() {
          FB.ui(m, function(response) {
            Drupal.behaviors.fb.callback_handler(callback, response);
          });
        })
      }
      else {
        FB.ui(m, function(response) {
          Drupal.behaviors.fb.callback_handler(callback, response);
        });
      }
    },

    /**
     *  Shares a full-sized image on the user's wall.  The image must be at least 480x480px square,
     *  and be a photo taken by a camera, by a human being.
     *
     *  @param config
     *    A javascript object of configuration options.  Available options:
     *       img_namespace           (The Open Graph namespace through which to post the image.)
     *       img_action              (The Open Graph action through which to post the image.)
     *       img_document            (The URI to share.  Defaults to document.location.href)
     *       img_message             (An (optional) message to post with the image.)
     *       img_picture          *  (The URI to the image that will be shared.)
     *       img_picture_selector *  (A DOM element t gather the SRC of the image from.)
     *       img_selector            (An (optional) selector that will trigger the share when clicked.)
     *       img_require_login       (Prompts a user to log into Facebook if they aren't already.)
     *
     *    * No more than one of these may be set, and at least one must always be set.
     *      In addition, the shared image must be *at least* 480x480px (Facebook's rules, not mine)
     *
     *  @param callback
     *    A callback function which triggers when a post was succesfully made.
     *    
     */
    image: function(config, callback) {
      var things = {
        namespace: config.img_namespace,
        object: config.img_object,
        action: config.img_action,
        link: config.img_document || document.location.href,
        message: config.img_message || '',
        image: config.img_picture, // Needs to be at least 480x480
        image_selector: config.img_picture_selector, // Needs to be an img element that is at least 480x480
        selector: config.img_selector, 
        require_login: config.img_require_login
      };

      if (typeof callback == 'undefined' && typeof Drupal.behaviors.fb._image_callback == 'function') {
        callback = Drupal.behaviors.fb._image_callback;
      }

      if (things.image) {
        things.img_url = things.image;
      }
      else if (things.image_selector && $('body ' + things.image_selector).length > 0 && $('body ' + things.image_selector).attr('src')) {
        things.img_url = $('body ' + things.image_selector).attr('src');
      }

      Drupal.behaviors.fb.auth_handler('run_image', things, callback);
    },

    /**
     *  Runs the User Generated Image share.
     *  This function should not be called on its own.
     *  NOTE: We need Facebook permission to make this a public function.
     */
    run_image: function(things, callback) {
      var fbpost = {
          message: things.message,
          'image[0][url]': things.img_url,
          'image[0][user_generated]': true
      };

      fbpost[things.object] = things.link;

      FB.api(
       '/me/' + things.namespace + ':' + things.action,
        'post',
        fbpost,
        function(response) {
          Drupal.behaviors.fb.callback_handler(callback, response);
        }
      );
    },

    /**
     *  Sends a Facebook notification to a user or multiple users.
     *
     *  @param config
     *    A javascript object of configuration options.  Available options:
     *       notification_user       (A single FB user ID, OR a comma-separated list of FB user IDs to send the notification to.)
     *       notification_document   (A fully-formed URL to share through the notification.)
     *       notification_template    (The message to send in the notification.)
     *       notification_selector   (An (optional) selector that will trigger the share when clicked.)
     *       notification_require_login       (Prompts a user to log into Facebook if they aren't already.)
     *
     *  @param callback
     *    A callback function which triggers when a post was succesfully made.
     *    
     */
    notification: function(config, callback) {
      var things = {
        'app_key': '105775762330|pmFm2r3S-p7merbypvN2EANG4UI', // DoSomething.org's app key -- needs to be a canvas app key.  This will be in the UI at a later point.
        user: config.notification_user || 0,
        link: config.notification_document || document.location.href,
        message: config.notification_template,
        selector: config.notification_selector, 
        require_login: config.notification_require_login,
      };

      if (typeof callback == 'undefined' && typeof Drupal.behaviors.fb._notification_callback == 'function') {
        callback = Drupal.behaviors.fb._notification_callback;
      }

      Drupal.behaviors.fb.auth_handler('run_notification', things, callback);
    },

    /**
     *  Handles post processing, including Facebook ID and multiple IDs.
     *  This function should not be called by itself.
     */
    run_notification: function(things, callback) {
      if (!things.user) {
        var fbid = FB.getUserID();
        if (fbid > 0) {
          things.user = fbid;
        }
      }

      // If we can find a comma, it's likely there are several users to send a message to.
      if (things.user.indexOf(',') !== -1) {
        var u = things.user.split(',');
        for (var i in u) {
          things.user = u[i];
          Drupal.behaviors.fb.send_notification(things, callback);
        }
      }
      // Otherwise, presumably only one person to send the message to.
      else {
        Drupal.behaviors.fb.send_notification(things, callback);
      }
    },

    /**
     *  Actually sends the notification.
     *  This function should not be called by itself.
     */
    send_notification: function(things, callback) {
      FB.api(
       '/' + things.user + '/notifications',
        'post',
        {
            'access_token': things.app_key,
            'href': things.link,
            'template': things.message
        },
        function(response) {
          Drupal.behaviors.fb.callback_handler(callback, response);
        }
      );
    },

    /**
     *  Gates a page.
     * 
     *  @param config
     *    An object full of configuration options.  Available options:
     *      config.call_fb (bool): calls the FB.login() function if a user is not logged in.
     *      config.fb_redirect (bool): whether or not to redirect to Facebook for authentication.
     *      config.fb_app_id (int): The numeric ID of the Facebook App to authenticate to.  This *must* be used in conjunction fb_redirect.
     *
     *  @param callback
     *    A callback function to run if a user is authenticated.
     */
    gate: function(config, callback) {
      var things = {
        call_fb: (config.call_fb === true || config.call_fb === false) ? config.call_fb : true,
        fb_redirect: config.fb_redirect || null,
        fb_app_id: (config.fb_redirect && config.fb_app_id) ? config.fb_app_id : null
      };

      if (typeof callback == 'undefined' && typeof Drupal.behaviors.fb._notification_callback == 'function') {
        callback = Drupal.behaviors.fb._notification_callback;
      }

      FB.getLoginStatus(function(response) {
        if (response.status == 'connected' && response.authResponse.userID) {
          // Nothing.  They're authorized.
          //Drupal.behaviors.fb.clog('User is authenticated.  Doing nothing.');
        }
        else {
          if (things.call_fb) {   
            FB.login(function(response) {
              if (response.status == 'connected') {
                callback();
              }
            }, { scope: 'email' });
          }
          else if (things.fb_redirect) {
            window.location.href = 'https://www.facebook.com/login.php?api_key=' + things.fb_app_id + '&skip_api_login=1&display=page&cancel_url=http%3A%2F%2F' + document.location.host + '%2Ffboauth%2Fconnect%3Fdestination%3D' + document.location.pathname.replace('/', '') + '%26error_reason%3Duser_denied%26error%3Daccess_denied%26error_description%3DThe%2Buser%2Bdenied%2Byour%2Brequest.&fbconnect=1&next=https%3A%2F%2Fwww.facebook.com%2Fdialog%2Fpermissions.request%3F_path%3Dpermissions.request%26app_id%3D' + things.fb_app_id + '%26redirect_uri%3Dhttp%253A%252F%252F' + document.location.host + document.location.pathname + '%252Ffboauth%252Fconnect%253Fdestination%253D' + document.location.pathname.replace('/', '') + '%26display%3Dpage%26response_type%3Dcode%26perms%3Demail%252Cuser_birthday%26fbconnect%3D1%26from_login%3D1%26client_id%3D' + things.fb_app_id + '&rcount=1';
          }
        }
       });
    },

    callback_handler: function(callback, response) {
      if (typeof callback == 'function') {
        callback(response);
      }

      if (Drupal.behaviors.fb.debug == true) {
        Drupal.behaviors.fb.clog(response);
      }
    }
  };
})(jQuery);
