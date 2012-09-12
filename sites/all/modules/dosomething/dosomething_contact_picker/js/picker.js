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
      $(this).attr('checked', 'checked');
      add_email($(this).parent().find('strong').html());
    });

    return false;
  });

  $('#check-none').click(function() {
    $('input.email-checkbox').each(function() {
      $(this).attr('checked', false);
      remove_email($(this).parent().find('strong').html());
    });

    return false;
  });

  // Starting off with every checkbox checked: They need to be in the box
  $('input.email-checkbox').each(function() {
    var e = $(this).parent().find('strong').html();
    add_email(e);
  });

  $('ul#blah li:not(.clicked)').addClass('clicked').click(function() {
    var e = $(this).find('strong').html();
    if ($('#email_list').html().indexOf(e) == -1) {
      add_email(e);
      $(this).find('input').attr('checked', 'checked');
    }
    else {
      remove_email(e);
      $(this).find('input').attr('checked', false);
    }
  });
}

function add_email(email) {
  if ($('#email_list').html().indexOf(email) == -1) {
    $('#email_list').append(email + ', ');
  }
}

function remove_email(email) {
    var t = $('#email_list').html();
    t = t.replace(email + ', ', '');
    $('#email_list').html(t);
}


function test() {
  var v = ($('#email_list').val());
  $('#re').val(v);
}