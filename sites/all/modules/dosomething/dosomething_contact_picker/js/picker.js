var authed = false;

function service(s, path) {
  eval(s).auth(path);
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


function submit_emails() {
  var v = ($('#email_list').val());
  $('#re').val(v);

  return true;
}

$(document).ready(function() {
  $('#close-scraper').click(function() {
    window.parent.close_scraper();
  });
})

function scraper_email(subject, body) {
  mail = "mailto:?subject=" + escape(subject)
  mail += '&body=' + escape(body);

  window.location.href = mail;
  return false;
}

