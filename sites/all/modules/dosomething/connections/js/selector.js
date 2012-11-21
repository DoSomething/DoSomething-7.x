(function($) {
	FB_extra = {};
	FB_extra.friendSelector = {
		friends: {},
		comments: {},
		count: 0,
		settings: {
			silhouette: 'http://profile.ak.fbcdn.net/static-ak/rsrc.php/v2/yo/r/UlIqmHJn-SK.gif',
			limit: 10,
			cancel: null,
			submit: null,
		},

		init: function(config) {
			$.extend(this.settings, config);

			this.fetch_friends();
			this.create_thumbnails();
			this.set_handlers();
		},

		create_thumbnails: function() {
			if (this.settings.limit > 0) {
				var img = '';

				for (i = 1; i <= this.settings.limit; i++) {
					img = $('<img />').attr('src', this.settings.silhouette).addClass('silhouette').attr('alt', '').attr('rel', i);
					$('#choosers').append(img);
				}
			}
		},

		fetch_friends: function() {
			var h = this;

	 	  	FB.getLoginStatus(function(response) {
		 		FB.api('/me?fields=name,picture', function(response) {
		 			var name = response.name;
		 			var pic = response.picture.data.url;
		 			$('#profile-pic').attr('src', pic);
		 			$('#profile-name').text(name);
		 		});

		 		FB.api({
		 			'method': 'fql.query',
		 			'query': 'SELECT name, uid, pic_square FROM user WHERE uid IN (SELECT uid2 FROM friend WHERE uid1 = me()) ORDER BY name ASC',
		 		}, function(response) {
		 			var elm = '';
		 			for (i in response) {
		 				elm += '<li class="friend" rel="' + response[i].uid + '"><a href="http://www.facebook.com/' + response[i].uid + '" class="u-' + response[i].uid + '"><img src="' + response[i].pic_square + '" width="50" height="50" alt="" /><div>' + response[i].name + '</div><div class="comment"><input type="text" name="comment[' + response[i].uid + ']" class="personal-message" placeholder="Write something..." /> <input type="submit" class="share-button" name="share[' + response[i].uid + ']" value="Share" /></div></a></li>';
		 			}

		 			$('.loading').fadeOut(200);
	 				$('#friends-info').append(elm);	
	 				h.handle_clicks();
		 		});
		 	});
		},

		find_close_friends: function() {
			FB.api({
				'method': 'fql.query',
				'query': 'SELECT flid, owner, name FROM friendlist WHERE owner = me()',
			}, function(lists) {
				for (i in lists) {
					if (lists[i].name == 'Close Friends') {
						FB.api({
							'method': 'fql.query',
							'query': 'SELECT uid, flid FROM friendlist_member WHERE flid = ' + lists[i].flid,
						}, function(members) {
							var mem = [];

							for (m in members) {
								mem[members[m].uid] = true;
							}

							$('.friend').each(function() {
								if (!mem[$(this).attr('rel')]) {
									$(this).addClass('hidden');
								}
								else {
									// Emulate a click on your close friends.
									$(this).click();
								}
							});

							$('#clear-search').click();
							$('#find-close-friends').hide();
							$('#close-close-friends').show();
						});
					}
				}
			});
		},

		handle_clicks: function() {
			var added;
			var h = this;

			$('.my-submit').click(function() {
				$(this).parent().parent().addClass('submitted').fadeOut(250);
				return false;
			});

			$('#friends-info li').mouseover(function() {
				$(this).find('.comment').show();
			});

			$('#friends-info li').mouseout(function() {
				if (!$(this).hasClass('selected')) {
					$(this).find('.comment').hide();
				}
			});

			$('#friends-info li').click(function(e) {
				//var id = $(this).attr('rel');
				$('#friends-info li').removeClass('selected').find('.comment').hide();
				var target = $(e.target);

				// Ignore a click to the PM box
				if ($(this).attr('id') == 'search' || $(this).attr('id') == 'select' || target.hasClass('share-button')) return false;

				if (!$(this).hasClass('selected')) {

					$(this).find('.comment').show();
					added = true;

					$(this).addClass('selected');
				}
				else {
					$(this).find('.comment').hide();
					$(this).removeClass('selected');
					added = false;
				}

				return false;
			});

			$('.share-button').click(function() {
				h.add_image_to_chosen($(this).parent().parent(), true);
				$(this).parent().parent().parent().hide();
				return false;
			});

			$('#find-close-friends').click(function() {
				FB.api('/me/permissions', function (response) {
		            var perms = response.data[0];
		            if (!perms.read_friendlists) {
		            	FB.ui({
							method: 'permissions.request',
							perms: 'read_friendlists',
							display: 'iframe',
						}, h.find_close_friends());
		            }
		            else {
		            	h.find_close_friends();
		            }
		        });

				return false;
			});

			$('#close-close-friends').click(function() {
				$('.friend').removeClass('hidden');
				$('#find-close-friends').show();
				$(this).hide();
			});

			$('#show-selected').click(function() {
				$('.friend').each(function() {
					if (!$(this).hasClass('selected') && !$(this).hasClass('shared')) {
						$(this).addClass('hidden');
					}
				});
			});

			// Deprecated 11/16/12
			// We hardly knew ye...

			// Select all friends
			//$('#select-all').click(function() {
			//	$('.friend:not(.selected)').each(function() {
			//		$(this).click();
			//	});
			//});

			// De-select all friends
			//$('#select-none').click(function() {
			//	$('.friend.selected').each(function() {
			//		$(this).click();
			//	});
			//})

			// Search functionality for your friends.
			$('#search-friends').bind('keyup', function(e) {
				h.filter_friends($(this).val());
			});

			// Clear search "X"
			$('#search a.clear-search').click(function() {
				// Clear the search field.
				$('#search-friends').val('');
				// Reset the friend filter, assuming no value
				h.filter_friends('');
				return false;
			});
		},

		handle_image_click: function() {
			//var id = $(this).attr('class').replace('u-', '');
			//$('li[rel="' + id + '"]').click();
		},

		add_image_to_chosen: function(elm, added) {
			var image, img;
			var h = this;

			var id = parseInt($(elm).attr('rel'));

			if (added) {
				if (!this.settings.limit) {
					image = $(elm).find('img').attr('src');
					var c = ++this.count;
					img = $('<img />').attr('src', image).addClass('u-' + id).attr('alt', '').attr('rel', c).attr('title', $(elm).find('div:not(.comment)').text());
					//img.click(this.handle_image_click);
					$('#choosers').append(img);
				}
			}
			else {
				if (!this.settings.limit) {
					$('img.u-' + id).remove();

					this.count--;
				}
			}
		},

		filter_friends: function(filter) {
            var name;

            numFilteredFriends = 0;
            $('.friend').removeClass('hidden');
            if (filter.length >= 1) {
                filter = filter.toUpperCase();
                $('.friend div:not(.comment)').each(function() {
                	name = $(this).text();
                	if (name.toUpperCase().indexOf(filter) === -1) {
                		$(this).parent().parent().addClass('hidden');
                	}
                });
            }
		},

		set_handlers: function() {
			var h = this;

			// Submit handler
			$('#submit-og-post').click(function() {
				var selected;
				var msgs = {};

				$('.friend').each(function() {
					if ($(this).hasClass('selected')) {
						var id = $(this).attr('rel');
						msgs[id] = $(this).find('.personal-message').val();
					}
				});

				if (typeof h.settings.submit === 'function') { this.settings.submit(); }
				return false;
			});
		},
	};
})(jQuery);