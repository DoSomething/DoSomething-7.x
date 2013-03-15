(function ($) {
  Drupal.behaviors.robocalls_celeb = {
    friends_field_count: 1,
    celeb_friends_field_count: 7,
    friends_limit: 9,
    celebs: [],
    previewing: false,

    attach: function(context, settings) {
      // Clear ?c=etc. if it's there.
      if (document.location.search && document.location.search.indexOf('c=') != -1) {
        var msie = /*@cc_on!@*/0;
        if (!msie) {
          var h = new Object();
          history.pushState(h, '', window.location.href.replace(/\?c=.+/, ''));
        }
      }

      $('#edit-submitted-your-friends-info-field-celeb-friend-phone-und-0-value, #edit-submitted-your-friends-info-field-celeb-friend-phone-2-und-0-value, #edit-submitted-your-friends-info-field-celeb-friend-phone-3-und-0-value, #edit-submitted-your-friends-info-field-celeb-friend-phone-4-und-0-value, #edit-submitted-your-friends-info-field-celeb-friend-phone-5-und-0-value, #edit-submitted-your-friends-info-field-celeb-friend-phone-6-und-0-value').mask("(999) 999-9999");

      if ($('.facebook-button').length) {
        Drupal.behaviors.fb.feed({
          'feed_document': document.location.href,
          'feed_title': 'I just prank called my friends with a call from ' + Drupal.settings.calloffame.name,
          'feed_picture': document.location.origin + $('.celeb-image').find('img').attr('src'),
          'feed_caption': '',
          'feed_description': 'Seriously, check out DoSomething.org\'s Project Prank.',
          'feed_allow_multiple': true,
          'feed_require_login': true,
          'feed_selector': '.facebook-button'
        }, function(response) {
          
        });
      }

      $('.add-more-friends').click(function() {
        var str = '';
        var n = Drupal.behaviors.robocalls.celeb_friends_field_count;

        for (i = n; i < (n + 3); i++) {
          str += '<div class="field-type-text field-name-field-celeb-friend-phone-5 field-widget-telwidget form-wrapper" id="edit-submitted-field-celeb-friend-phone-5"><div id="submitted-field-celeb-friend-phone-5-add-more-wrapper"><div class="form-item form-type-telfield form-item-submitted-field-celeb-friend-phone-5-und-0-value"><label for="edit-submitted-field-celeb-friend-phone-5-und-0-value">Friend\'s Number #5 </label><input placeholder="Friend\'s Number" type="tel" id="edit-submitted-field-celeb-friend-phone-5-und-0-value" name="submitted[additional_friends][' + i + ']" value="" size="20" maxlength="64" class="additional-friends form-text form-tel"></div></div></div>';
          Drupal.behaviors.robocalls.celeb_friends_field_count++;
        }

        $(str).appendTo($('#webform-component-your-friends-info'));
        $('.additional-friends').mask("(999) 999-9999");
        return false;
      });

      //Move "Send to more friends" to numbers area
      $('#webform-component-your-friends-info').after($('.add-more-friends'));
      
    }
  };
})(jQuery);
