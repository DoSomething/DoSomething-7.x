(function ($) {
  Drupal.behaviors.robocalls_celeb = {
    friends_field_count: 1,
    celeb_friends_field_count: 7,
    friends_limit: 9,
    celebs: [],
    previewing: false,

    attach: function(context, settings) {
      if ($('.facebook-share-celeb').length) {
        Drupal.behaviors.fb.feed({
          'feed_document': document.location.href,
          'feed_title': 'MLK',
          'feed_picture': document.location.origin + $('.celeb-image').find('img').attr('src'),
          'feed_caption': 'Check out this call.',
          'feed_description': 'I just sent a call from DoSomething.org\'s Project Prank!',
          'feed_allow_multiple': true,
          'feed_require_login': true,
          'feed_selector': '.facebook-share-celeb'
        }, function(response) {
          console.log(response);
        });
      }

      $('.add-more-friends').click(function() {
        var str = '';
        var n = Drupal.behaviors.robocalls.celeb_friends_field_count;

        for (i = n; i < (n + 3); i++) {
          str += '<div class="field-type-text field-name-field-celeb-friend-phone-5 field-widget-telwidget form-wrapper" id="edit-submitted-field-celeb-friend-phone-5"><div id="submitted-field-celeb-friend-phone-5-add-more-wrapper"><div class="form-item form-type-telfield form-item-submitted-field-celeb-friend-phone-5-und-0-value"><label for="edit-submitted-field-celeb-friend-phone-5-und-0-value">Friend\'s Number #5 </label><input placeholder="Friend\'s Number" type="tel" id="edit-submitted-field-celeb-friend-phone-5-und-0-value" name="submitted[additional_friends][' + i + ']" value="" size="20" maxlength="64" class="form-text form-tel"></div></div></div>';
          Drupal.behaviors.robocalls.celeb_friends_field_count++;
        }

        $(str).appendTo($('#webform-component-your-friends-info'));
        return false;
      });
    }
  };
})(jQuery);