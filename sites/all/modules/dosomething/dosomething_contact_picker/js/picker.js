var authed = false;
function auth(t) {
  if (t == 'gmail') {
    var config = {
      'client_id': '1000659299351.apps.googleusercontent.com',
      'scope': 'https://www.google.com/m8/feeds'
    };
    $('#response').show().html('<p style="text-align: center"><img src="/sites/all/modules/dosomething/dosomething_contact_picker/images/loading.gif" alt="" /> Loading.  Please wait...</p>');
    gapi.auth.authorize(config, function() {
      var t = gapi.auth.getToken();
      console.log('Login complete');
      console.log(t);
      token = t.access_token;
      
      $.post('gapi.php', { 'do': 'blah', 'key': t }, function(response) {
        $('#response').html(response);

        prepare_clicks();
      });
    });
  }
  else if (t == 'yahoo') {
    window.open('/sites/all/modules/dosomething/dosomething_contact_picker/yo/index.php', 'yahoo', 'width=500,height=350,scrollbars=no,resizeable=no,location=no,status=no,titlebar=no,toolbar=no');
  }

  return false;
}

function prepare_clicks() {
  $('#response').slideDown();
  $('#check-all').click(function() {
    $('input.email-checkbox').each(function() {
      if ($(this).attr('checked') == true || $(this).attr('checked') == 'checked') {
        $(this).attr('checked', false);
      }
      else {
        $(this).attr('checked', 'checked');
      }
    });
    return false;
  });

  $('ul#blah li:not(.clicked)').addClass('clicked').click(function() {
  //var choices = parseInt($('#choices-left').text());
    var e = $(this).find('strong').html();
    if ($('#email_list').html().indexOf(e) == -1) {
  //if (choices <= 0) {
//    alert("You can't choose any more emails.  Uncheck some to add more.");
    //return false;
  //}
      $('#email_list').append(e + ', ');
      $(this).find('input').attr('checked', 'checked');
      //$('#choices-left').text(choices - 1);
    }
    else {
      var t = $('#email_list').html();
      t = t.replace(e + ', ', '');
      $('#email_list').html(t);
      $(this).find('input').attr('checked', false);
      //$('#choices-left').text(choices + 1);
    }
  });
}


function test() {
  var v = ($('#email_list').val());
  $('#re').val(v);
}