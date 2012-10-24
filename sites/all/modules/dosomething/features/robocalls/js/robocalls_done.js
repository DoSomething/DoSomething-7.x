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

jQuery(function() {
	var code = (window.location.search.substring(1));
	var person = '';
	var cause = '';
    var limit = 0;

	if (code.indexOf('done=') !== -1 && code !== 'done=true')
	{
		var thecode = (decodeURIComponent(code.replace('done=', '')));
		var c = (base64_decode(thecode));
		var res = jQuery.parseJSON(c);
		person = res['name'];
		cause = res['cause'];
        limit = res['passed_limit'];
	}

	jQuery.fn.dsRobocallsDone(person, cause, limit);

    var ftitle, fdesc;
      switch (cause) {
        case 'Animals':
          ftitle = 'Let your friends know about animals in need with a phone call from ' + person;
          fdesc = '4 million shelter animals were euthanized last year because they couldn\'t find homes, find out how to do something about it here.';
        break;
        case 'Birthday':
          ftitle = 'Wish your firends a happy birthday with a phone call from ' + person;
          fdesc = 'Is your friend a huge fan of ' + person + '? Well, you\'re in luck, click here to have them call your friend and wish them a Happy Birthday now!';
        break;
        case 'Voting':
          ftitle = 'Help your friends find their V-Spot with a phone call from ' + person;
          fdesc = '1.9 million people couldn\'t find their voting location during the last Presidential election, make sure your friends know where theirs is this November 6th.';
        break;
      }

    var obj = {
        method: 'feed',
        link: document.location.href,
        name: ftitle,
        description: fdesc
      };

      jQuery('#robocalls-fb-share-link').click(function () {
        FB.ui(obj);
        return false;
      });
});
