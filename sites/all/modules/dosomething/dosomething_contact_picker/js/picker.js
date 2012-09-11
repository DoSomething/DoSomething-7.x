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
  $('input#check-all').click(function() {
    var status = $(this).attr('checked');
    if (status == 'checked') {
      $('input.email-checkbox').attr('checked', 'checked');
    }
    else {
      $('input.email-checkbox').attr('checked', false);
    }
  });

  $('ul#blah li:not(.clicked)').addClass('clicked').click(function() {
  var choices = parseInt($('#choices-left').text());
    var e = $(this).find('strong').html();
    if ($('#email_list').html().indexOf(e) == -1) {
  if (choices <= 0) {
    alert("You can't choose any more emails.  Uncheck some to add more.");
    return false;
  }
      $('#email_list').append(e + ', ');
      $(this).find('input').attr('checked', 'checked');
      $('#choices-left').text(choices - 1);
    }
    else {
      var t = $('#email_list').html();
      t = t.replace(e + ', ', '');
      $('#email_list').html(t);
      $(this).find('input').attr('checked', false);
      $('#choices-left').text(choices + 1);
    }
  });
}


  function test() {
    var v = ($('#email_list').val());
    $('#re').val(v);
  }

$(document).ready(function() {
});