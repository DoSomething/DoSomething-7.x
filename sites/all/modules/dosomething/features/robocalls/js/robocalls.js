function base64_decode(data){var b64="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";var o1,o2,o3,h1,h2,h3,h4,bits,i=0,ac=0,dec="",tmp_arr=[];if(!data){return data}data+='';do{h1=b64.indexOf(data.charAt(i++));h2=b64.indexOf(data.charAt(i++));h3=b64.indexOf(data.charAt(i++));h4=b64.indexOf(data.charAt(i++));bits=h1<<18|h2<<12|h3<<6|h4;o1=bits>>16&0xff;o2=bits>>8&0xff;o3=bits&0xff;if(h3==64){tmp_arr[ac++]=String.fromCharCode(o1)}else if(h4==64){tmp_arr[ac++]=String.fromCharCode(o1,o2)}else{tmp_arr[ac++]=String.fromCharCode(o1,o2,o3)}}while(i<data.length);dec=tmp_arr.join('');return dec}

(function ($) {
  Drupal.behaviors.robocalls = {
    friends_field_count: 1,
    celeb_friends_field_count: 7,
    friends_limit: 9,
    celebs: [],

    attach: function(context, settings) {
      var call = {};
      if (document.location.search && document.location.search.indexOf('call=')) {
        var str = document.location.search.replace(/\?call=/, '');
        d = base64_decode(str);
        console.log(d);
        call = $.parseJSON(base64_decode(document.location.search.replace(/\?call=/, '')));
        console.log(call.call_sid);
        var msie = /*@cc_on!@*/0;
        if (false) {
          var h = new Object();
          history.pushState(h, '', window.location.href.replace(/\?call=.+/, ''));
        }
      }

      $('.views-field-nothing').hover(function() {
        $(this).find('.hover-state').show();
      });


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
      else if ($('.facebook-share-call').length) {
        //Drupal.behaviors.fb.feed({
        //  feed_document: '',
        //});
      }

      var new_field, f = '';
      new_field = '<fieldset class="webform-component-fieldset form-wrapper" id="webform-component-friends-info--primary-friend"><div class="fieldset-wrapper"><div class="form-item webform-component webform-component-select" id="webform-component-friends-info--primary-friend--select-call">#SELECT</div><div class="form-item webform-component webform-component-textfield" id="webform-component-friends-info--primary-friend--friends-number">#INPUT</div></div></fieldset>';

      var celebs = '';
      if (typeof Drupal.settings.calloffame != 'undefined') {
        for (i in Drupal.settings.calloffame.celebs) {
          celebs += '<option value="' + i + '">' + Drupal.settings.calloffame.celebs[i] + '</option>';
        }
      }

      select = '<select id="edit-submitted-friends-info-primary-friend-select-call" name="submitted[friends_info][primary_friend][more_calls][#N]" class="form-select"><option value="" selected="selected">Select Call</option>' + celebs + '</select>';
      input = '<input type="text" id="edit-submitted-friends-info-primary-friend-friends-number" name="submitted[friends_info][primary_friend][more_friends][#N]" value="" size="60" maxlength="128" class="form-text" placeholder="Friend\'s Number" />';

      n = Drupal.behaviors.robocalls.friends_field_count;
      for (var i = n; i < (n + 2); i++) {
        f += new_field.replace('#SELECT', select.replace('#N', i)).replace('#INPUT', input.replace('#N', i));
        Drupal.behaviors.robocalls.friends_field_count++;
      }

      $(f).insertAfter('#webform-component-friends-info--primary-friend');
      $('option[value=""]').text('Select Call');

      $('.add-more-friends-front').click(function() {
        var n = Drupal.behaviors.robocalls.friends_field_count;
        if (n >= Drupal.behaviors.robocalls.friends_limit) {
          $('.add-more-friends-front').remove();
          return false;
        }

        var new_field, f = '';
        new_field = '<fieldset class="webform-component-fieldset form-wrapper" id="webform-component-friends-info--primary-friend"><div class="fieldset-wrapper"><div class="form-item webform-component webform-component-select" id="webform-component-friends-info--primary-friend--select-call">#SELECT</div><div class="form-item webform-component webform-component-textfield" id="webform-component-friends-info--primary-friend--friends-number">#INPUT</div></div></fieldset>';

        select = '<select id="edit-submitted-friends-info-primary-friend-select-call" name="submitted[friends_info][primary_friend][more_calls][#N]" class="form-select"><option value="" selected="selected">Select Call</option>' + celebs + '</select>';
        input = '<input type="text" id="edit-submitted-friends-info-primary-friend-friends-number" name="submitted[friends_info][primary_friend][more_friends][#N]" value="" size="60" maxlength="128" class="form-text" placeholder="Friend\'s Number" />';

        n = Drupal.behaviors.robocalls.friends_field_count;
        for (var i = n; i < (n + 3); i++) {
          f += new_field.replace('#SELECT', select.replace('#N', i)).replace('#INPUT', input.replace('#N', i));
          Drupal.behaviors.robocalls.friends_field_count++;
        }

        if (Drupal.behaviors.robocalls.friends_field_count >= Drupal.behaviors.robocalls.friends_limit) {
          $('.add-more-friends-front').remove();
        }

        $(f).appendTo('#webform-component-friends-info');
        return false;
      });

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