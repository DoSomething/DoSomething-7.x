var authed = false;

function service(s, path) {
  jQuery('#loading').show().html('<img src="/' + path + '/images/loading.gif" alt="" /> Loading.  Please wait...');
  eval(s).auth(path);
  //jQuery('#connect-message').text('Invite friends to sign this petition');
}

function prepare_clicks() {
  jQuery('#response').slideDown().css('overflow', 'auto');
  jQuery('#check-all').click(function() {
    jQuery('input.email-checkbox').each(function() {
      jQuery(this).attr('checked', 'checked');
      add_email(jQuery(this).parent().find('strong').html());
    });

    return false;
  });

  jQuery('#check-none').click(function() {
    jQuery('input.email-checkbox').each(function() {
      jQuery(this).attr('checked', false);
      remove_email(jQuery(this).parent().find('strong').html());
    });

    return false;
  });

  //Drupal.ajax['edit-submit-emails'].options.beforeSubmit = function(form_values, element, options) {
    // Something?
  //}

  var e;
  // Starting off with every checkbox checked: They need to be in the box
  jQuery('input.email-checkbox').each(function() {
    e = jQuery(this).parent().find('strong').html();
    add_email(e);
  });

  jQuery('ul#blah li:not(.clicked)').addClass('clicked').click(function() {
    var e = jQuery(this).find('strong').html();

    var found = false;
    for (i in emails) {
      if (emails[i] == e) {
        found = true;
        break;
      }
    }

    if (found) {
      remove_email(e);
      jQuery(this).find('input').attr('checked', false);
    }
    else {
      add_email(e);
      jQuery(this).find('input').attr('checked', 'checked');
    }
  });
}

var emails = [];
function add_email(email) {
  emails.push(email);
  //if (jQuery('#email_list').html().indexOf(email) == -1) {
  //  jQuery('#email_list').append(email + ', ');
  //}
}

function remove_email(email) {
  for (var key in emails) {
    if (emails[key] == email) {
      emails.splice(key, 1);
    }
  }

  //var t = jQuery('#email_list').html();
  //t = t.replace(email + ', ', '');
  //jQuery('#email_list').html(t);*/
}


function submit_emails() {
  jQuery('#re').val(emails.join(','));
  return true;
}

jQuery(document).ready(function() {
  if (typeof hide_scraper_loader == 'function') {
    hide_scraper_loader();
  }

  jQuery('#contacts-scraper-dialog', window.parent.document).css('height', 'auto');
});

function scraper_email(subject, body) {
  mail = "mailto:?subject=" + escape(subject)
  mail += '&body=' + escape(body);

  window.location.href = mail;
  return false;
}

function stretch_scraper() {
  jQuery('#email-scraper', window.parent.document).css('height', '700x').css('min-height', '700px');
  jQuery('.email-scraper-dialog', window.parent.document).animate({'height': '750px'});
  return false;
}