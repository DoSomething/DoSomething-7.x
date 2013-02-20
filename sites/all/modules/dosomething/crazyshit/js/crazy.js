(function($) {
   Drupal.behaviors.dsCrazyScripts = {
	 authed: false,
	 probably_unauthed: false,
	 notify_yourself: false,
	 logged_in: true,
	 started_page: false,

   	 attach: function(context, settings) { 
	    var o = this;
	    if (document.location.hash && parseInt(document.location.hash)) {
		   var h = document.location.hash.replace('#', '');
		   $('html, body').animate({ scrollTop: $('.s-' + h).offset().top }, 'slow');
	    }

	    if ($('body').hasClass('not-logged-in')) {
	    	Drupal.behaviors.dsCrazyScripts.logged_in = false;
	    }

        if (top.location != self.location) {
          top.location = self.location.href
        }

	    Drupal.behaviors.dsCrazyScripts.fb_refresh(function() {
            if (Drupal.behaviors.fb.is_authed()) {
               Drupal.behaviors.dsCrazyScripts.authed = true;
            }
	    });

	    window.setTimeout(function() {
	       if (!Drupal.behaviors.dsCrazyScripts.logged_in && Drupal.behaviors.fb.is_authed()) {
             Drupal.behaviors.dsCrazyScripts.fb_status();
           }
	    }, 500);

	    if (Drupal.settings.crazy.allow_lazy_loading) {
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

	    // Updates share buttons to disable ones you've already clicked.
	    if (typeof Drupal.settings.crazy.shares === 'object') {
	    	for (i in Drupal.settings.crazy.shares) {
	    		// Crazy
	    		//if (Drupal.settings.crazy.shares[i].type == 10) {
				//	$('.s-' + Drupal.settings.crazy.shares[i].sid + ' .crazy-button a[rel="' + Drupal.settings.crazy.shares[i].sid + '"]').addClass('clicked');
				//}
				// Vouch
			$('.s-' + Drupal.settings.crazy.shares[i].sid + ' .vouch-button a[rel="' + Drupal.settings.crazy.shares[i].sid + '"]').addClass('clicked');
			$('.s-' + Drupal.settings.crazy.shares[i].sid + ' .bs-button a[rel="' + Drupal.settings.crazy.shares[i].sid + '"]').addClass('clicked');
			//	if (Drupal.settings.crazy.shares[i].type == 11) {
			//		$('.s-' + Drupal.settings.crazy.shares[i].sid + ' .vouch-button a[rel="' + Drupal.settings.crazy.shares[i].sid + '"]').addClass('clicked');
			//	}
			//	// BS
			//	else if (Drupal.settings.crazy.shares[i].type == 2) {
			//		$('.s-' + Drupal.settings.crazy.shares[i].sid + ' .bs-button a[rel="' + Drupal.settings.crazy.shares[i].sid + '"]').addClass('clicked');
			//	}
	    	}
	    }

	    $('.bs-button a.button-submit').click(function() {
	       if (!Drupal.behaviors.fb.is_authed() || !Drupal.behaviors.dsCrazyScripts.logged_in) {
               	Drupal.behaviors.fb.clog("User is unauthed or not logged in.");
               	Drupal.behaviors.fb.clog("Auth status: " + Drupal.behaviors.fb.is_authed());
               	Drupal.behaviors.fb.clog("Logged in status: " + Drupal.behaviors.dsCrazyScripts.logged_in);
			  $.fn.dsCrazyPopup('login', 0, { 'goto': document.location.href });
			  return false;
	       }

	       if ($(this).hasClass('clicked')) {
	       	Drupal.behaviors.fb.clog("Element has clicked class already.");
			  return false;
	       }


	       var elm = $(this);
	       var na = $(this).hasClass('no-alert');

	       if ($(this).parent().parent().parent().hasClass('by-me') && Drupal.settings.crazy.origin == 2) {
	          $.fn.dsCrazyPopup('bull', elm.attr('rel'), { 'you': true });
	          na = true;
	       }

		   $('.s-' + elm.attr('rel')).find('.vouch-button a').addClass('clicked');
	       elm.addClass('clicked');

	       var c = parseInt(elm.parent().find('span').text());
		   elm.parent().find('span').text(++c);


	       $.post('/' + Drupal.settings.crazy.crazy_root + '/submit-bullshit', { 'rel': elm.attr('rel'), 'alert': na, 'origin': Drupal.settings.crazy.origin }, function(response) {
	      	  if (response.status == 1) {
	      		elm.parent().find('span').text(response.count);
	      		settings.crazy.share_count++;
	      		o.tip_shares(settings);

	      		if (!na && Drupal.settings.crazy.allow_notifications) {
	      			var name = '';
	      			if (FB.getUserID()) {
	      				name = '@[' + FB.getUserID() + ']';
	      			}
	      			else {
	      				name = Drupal.t('Someone');
	      			}

		      		Drupal.behaviors.fb.notification({
		      			'notification_document': 'crazy', // leave this like this
		      			'notification_user': response.author,
		      			'notification_template': name + " called BS on your story about the craziest thing you did to save money.  Click here to get support!"
		      		}, function(response) { 
		      			//console.log(response);
		      		});
		      	}
	          }
	          else {
	          	elm.removeClass('clicked');
	          }
	    	});

	      return false;
	    });

	    $('.vouch-button a.button-submit').click(function() {
               if (!Drupal.behaviors.fb.is_authed() || !Drupal.behaviors.dsCrazyScripts.logged_in) {
               	Drupal.behaviors.fb.clog("User is unauthed or not logged in.");
               	Drupal.behaviors.fb.clog("Auth status: " + Drupal.behaviors.fb.is_authed());
               	Drupal.behaviors.fb.clog("Logged in status: " + Drupal.behaviors.dsCrazyScripts.logged_in);
                  $.fn.dsCrazyPopup('login', 0, { 'goto': document.location.href });
                  return false;
               }

               if ($(this).hasClass('clicked')) {
			       	Drupal.behaviors.fb.clog("Element has clicked class already.");
                  return false;
               }

	      var na = $(this).hasClass('no-alert');
	      var elm = $(this);

	      elm.addClass('clicked');

		$('.s-' + elm.attr('rel')).find('.bs-button a').addClass('clicked');
		var c = parseInt(elm.parent().find('span').text());
		elm.parent().find('span').text(++c);


	      $.post('/' + Drupal.settings.crazy.crazy_root + '/submit-vouch', { 'rel': elm.attr('rel'), 'alert': na, 'origin': Drupal.settings.crazy.origin }, function(response) {
	      	if (response.status == 1) {
	      		elm.parent().find('span').text(response.count);
	      		settings.crazy.share_count++;
	      		o.tip_shares(settings);
	      	}
	      	else {
	      		elm.removeClass('clicked');
	      	}
	      });

	      return false;
	    });


	    $('.fb-share a').click(function(e) {
           if (!Drupal.behaviors.fb.is_authed() || !Drupal.behaviors.dsCrazyScripts.logged_in) {
              $.fn.dsCrazyPopup('login', 0, { 'goto': document.location.href });
              return false;
           }

	    	var img = $(this).parent().parent().parent().find('.simg img').attr('data-original');
	    	var sid = $(this).attr('rel');

	    	Drupal.behaviors.fb.image({
	    	   'img_namespace': Drupal.settings.crazy.facebook.share.namespace,
	    	   'img_object': Drupal.settings.crazy.facebook.share.object,
	    	   'img_action': Drupal.settings.crazy.facebook.share.action,
	    	   'img_document': document.location.origin + '/' + Drupal.settings.crazy.crazy_root + '/' + sid,
	    	   'img_message': true,
	    	   'img_picture': img,
	    	   'img_require_login': true,
	    	}, function(response) {
	    		$.post('/crazy/fb-share/' + sid, {}, function(response) {
	    			// Nothing!
	    		});
	    	});
	    	return false;
	    });
	 },

	 tip_shares: function(settings) {
		if (settings.crazy.share_count == 2) {
			$.fn.dsCrazyPopup('tip', 0);
		}
	 },

	 fb_refresh: function(callback) {
	 	if (!Drupal.behaviors.dsCrazyScripts.started_page) {
		 	var oa = window.fbAsyncInit;
		 	window.fbAsyncInit = function() {
				oa();
				Drupal.behaviors.dsCrazyScripts.started_page = true;
			    // If we're on the friends page...
			    if (Drupal.settings.crazy.origin == 2 || Drupal.settings.crazy.origin == 3) {

			    	// Occasionally users can log out of Facebook and still count as "authenticated"
			    	// That's bad.  So let's make sure they're actually connected.
			    	// Furthermore, FB.getUserID() doesn't work here.
			    	Drupal.behaviors.dsCrazyScripts.fb_status();
			    }

			    if (typeof callback === 'function') {
				callback();
			    }
			};
		}
	 },

	 fb_status: function() {
		 Drupal.behaviors.fb.gate({
		   gate_call_fb: 2,
		   gate_app_id: Drupal.settings.crazy.fb_app_id
		 }, function(response) {  });
	 },
  };

  $.fn.extend({
    dsCrazyPopup: function (name, sid, settings) {
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
	        'dialogClass': name + '-crazy-popup',
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

function fb_invite_friends_post(sid, reload) {
	jQuery('.bull-crazy-popup,.share-crazy-popup').remove();

	Drupal.behaviors.fb.ask_permission('publish_stream', { 'display': 'iframe' }, function(res) {
		if (!(typeof res === 'object' && res.perms == 'publish_stream')) {
		   return false;
		}

		var img = 'http://files.dosomething.org/files/campaigns/crazy13/logo.png';
		var path = 'http://www.dosomething.org/' + Drupal.settings.crazy.crazy_root + '/friends';
		if (sid > 0) {
			if (typeof my_post === 'object' && my_post.sid == sid) {
				if (my_post.image) {
					img = my_post.image;
				}
				else {
					img = jQuery('.s-' + sid + '-picture img').attr('src');
				}
			}
			else {
				img = jQuery('.s-' + sid + '-picture img').attr('src');
			}

			path = 'http://www.dosomething.org/' + Drupal.settings.crazy.crazy_root + '/friends/' + sid;
		}

		Drupal.behaviors.fb.feed({
			feed_document: path,
	        feed_title: Drupal.settings.crazy.facebook.posts.title,
	        feed_picture: img,
	        feed_caption: Drupal.settings.crazy.facebook.posts.caption,
	        feed_description: Drupal.settings.crazy.facebook.posts.description,
	        feed_allow_multiple: true,
	        feed_max_friends: 25,
	        feed_modal: false,
	        feed_friend_selector: 'td',
		}, function(response) {
			jQuery.post('/' + Drupal.settings.crazy.crazy_root + '/submit-vouch-request/' + sid, { 'friends': response.friends, 'origin': Drupal.settings.crazy.origin }, function(v) {
				//console.log(v);
			});
			//console.log(response);
		});

		return false;
	});

	return false;
}

function fb_invite_friends() {
	Drupal.behaviors.fb.ask_permission('publish_stream', { 'display': 'iframe' }, function(res) {
		if (!(typeof res === 'object' && res.perms == 'publish_stream')) {
           return false;
        }

		Drupal.behaviors.fb.feed({
			feed_document: Drupal.settings.crazy.facebook.invite.document,
			feed_title: Drupal.settings.crazy.facebook.invite.title,
			feed_picture: Drupal.settings.crazy.facebook.invite.image,
			feed_caption: Drupal.settings.crazy.facebook.invite.caption,
			feed_description: Drupal.settings.crazy.facebook.invite.description,
			feed_allow_multiple: true,
			feed_max_friends: 25,
			feed_modal: false,
			feed_friend_selector: 'td',
		}, function(response) {
			//console.log(response);
		});

		return false;
	});

	return false;
}

function fb_auth(type, status) {
	Drupal.behaviors.fb.is_authed(function(response) {
	   if (response.status == 'unknown' || response.status == 'not_authorized') {
	      status = 0;
	   }
	   else {
	      status = 1;
	   }
	});

	if (!status || jQuery('body').hasClass('not-logged-in')) {
		if (type == 'login') {
			jQuery.fn.dsCrazyPopup('login', 0);
			return false;
		}
		else {
			jQuery.fn.dsCrazyPopup('submit', 0);
			return false;
		}

		return true;
	}
	else {
		return true;
	}
}
