(function($) {
	Drupal.behaviors.clubsShare = {
		field_count: {
			'cell': 6,
			'email': 6,
		},

		attach: function(context, settings) {
			var buttons = $('.share-button');
			buttons.click(function() {
				var rel = $(this).attr('rel');
				$('.full-share-container:not(#' + rel + '-share-container)').hide();

				$('#response').html('&nbsp;');
				$('#manual-emails').hide();
				$('#check-area, #submit-emails-block').hide();

				// Hide the TD Friend selector if it's still somehow showing.
				if ($('#TDFriendSelector_buttonClose').length > 0) {
					$('#TDFriendSelector_buttonClose').click();
				}

				$('#' + rel + '-share-container').toggle();
				Drupal.behaviors.clubsShare.switch_image_and_button(rel);
				return false;
			});

			var add = $('.add-more');
			add.click(function() {
				var rel = $(this).attr('rel');

				var c = ( new Function('return Drupal.behaviors.clubsShare.field_count.' + rel + ';'))();
				for (var i = c; i < (c+3); i++) {
					var input = $('<input type="text" class="' + rel + '-share-' + rel + ' form-text" id="edit-' + rel + '-' + i + '" name="' + rel + '[' + i + ']" value="" size="60" maxlength="128" />');
					$('.' + rel + '-field-container').append(input);
					(new Function('Drupal.behaviors.clubsShare.field_count.' + rel + '++;'))();
				}
				return false;
			});

			$('p#rather a').click(function() {
				$('#response').html('&nbsp;');
				$('#manual-emails').slideToggle('fast');
				$('#check-area').hide();
				$('#submit-emails-block').show();
				return false;
			});

			$('.gmail a').click(function() {
				Drupal.behaviors.clubsShare.clear_buckets();
				service('google', 'sites/all/modules/dosomething/dosomething_contact_picker');
				return false;
			});

			$('.yahoo').click(function() {
				Drupal.behaviors.clubsShare.clear_buckets();
				service('yahoo', '/sites/all/modules/dosomething/dosomething_contact_picker');
				return false;
			});

			$('.share-button[rel="fb"]').click(function() {
				var c = {
		            'feed_document':  	   fb_link,
		            'feed_title':          fb_title,
		            'feed_picture':        fb_image,
		            'feed_caption': 	   fb_blurb || '',
		            'feed_description':    Drupal.t('Become a member of our DoSomething.org Club to take action together and make a difference in our community.'),
		            'feed_selector':       null,
		            'feed_allow_multiple': true,
		            'feed_require_login':  true
				};

				Drupal.behaviors.fb.feed(c, function(response) {
					console.log(response);
				});
			});
		},

		clear_buckets: function() {
			$('#response').html('&nbsp;');
			$('#manual-emails').slideUp('fast');
		},

		switch_image_and_button: function(rel) {
			var img = $('#' + rel + '-share').find('img');
			var e = img.attr('src');
			var button = $('#' + rel + '-button a');

			// Resets all images to "off" (i.e. colored) status
			$('.share-button img').each(function() {
				var src = $(this).attr('src');
				$(this).attr('src', src.replace('-on', '-off'));
			});
			// Resets all yellow buttons
			$('.share-button').removeClass('gray');

			if (e.indexOf('-off') !== -1) {
				img.attr('src', '/sites/all/modules/dosomething/features/dosomething_clubs/images/' + rel + '-on.png');
				button.addClass('gray');
			}
			else {
				img.attr('src', '/sites/all/modules/dosomething/features/dosomething_clubs/images/' + rel + '-off.png');
				button.removeClass('gray');
			}
		}
	};
})(jQuery);