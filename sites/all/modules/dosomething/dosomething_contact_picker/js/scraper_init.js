(function ($) {
  $.fn.extend({
    dsPetitionsInviteEmails: function (petition) {
      // Whelp, these were breaking things, so let's just destroy them.
      // This is bad practice.
      delete Drupal.behaviors.dosomethingLoginRegister;
      delete Drupal.behaviors.dosomethingLoginLogin;
      delete Drupal.behaviors.dosomethingPetitions;
      
      var popup = $('<div></div>').attr('id', 'contacts-scraper-dialog');
      popup.append($('<iframe></iframe>').attr('id', 'email-scraper').css('width', '500px').css('height', '600px').css('border', '0px').css('background', '#fff').attr('src', '/contacts-scraper/' + petition));
      // popup!
      popup.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550
      });

      return false;
    }
  });
})(jQuery);

function base64_decode (data) {
    var b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    var o1, o2, o3, h1, h2, h3, h4, bits, i = 0,
        ac = 0,
        dec = "",
        tmp_arr = [];

    if (!data) {
        return data;
    }

    data += '';

    do { // unpack four hexets into three octets using index points in b64
        h1 = b64.indexOf(data.charAt(i++));
        h2 = b64.indexOf(data.charAt(i++));
        h3 = b64.indexOf(data.charAt(i++));
        h4 = b64.indexOf(data.charAt(i++));

        bits = h1 << 18 | h2 << 12 | h3 << 6 | h4;

        o1 = bits >> 16 & 0xff;
        o2 = bits >> 8 & 0xff;
        o3 = bits & 0xff;

        if (h3 == 64) {
            tmp_arr[ac++] = String.fromCharCode(o1);
        } else if (h4 == 64) {
            tmp_arr[ac++] = String.fromCharCode(o1, o2);
        } else {
            tmp_arr[ac++] = String.fromCharCode(o1, o2, o3);
        }
    } while (i < data.length);

    dec = tmp_arr.join('');

    return dec;
}

function invite_find_emails() {
  var code = jQuery('#invite_data').val();
  jQuery.fn.dsPetitionsInviteEmails(code);
  return false;
}

function launch_fb_share() {
  jQuery('#petition-fb').click();
}

function close_scraper() {
  jQuery('#contacts-scraper-dialog').dialog('close');
}