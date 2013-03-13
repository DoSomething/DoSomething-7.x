if (typeof $ === 'undefined') {
  var $ = jQuery;
}

$(document).ready(function() {
  $('.remove-that-loader', window.parent.document).hide();
  $('#contacts-scraper-dialog', window.parent.document).css('height', 'auto');

  // Search functionality for your friends.
  $('.search input').bind('keyup', function(e) {
    DS.ContactPicker.filter_contacts($(this).val());
  });

  // For the "x" button
  $('.search').click(function(e) {
    DS.ContactPicker.filter_contacts($(this).val());
  });
});

var DS = {};
if (typeof path === 'undefined') {
  var path = '/sites/all/modules/dosomething/dosomething_contact_picker';
}

DS.ContactPicker = {
  service: function(s) {
    jQuery('#loading').show().html('<img src="' + path + '/images/loading.gif" alt="" /> Loading.  Please wait...');
    eval(s).auth(path);
    return false;
  },

  init_results: function() {
    // Checks all checkboxes
    $('.check-all').click(function() {
      $('.email-checkbox').each(function() {
        if (!$(this).is(':checked')) {
          // Using attr('checked', 'checked') or similar doesn't work here.
          $(this).click();
        }
      });
      return false;
    });

    // Checks no checkboxes
    $('.check-none').click(function() {
      // Removes all "checked" attributes completely.
      $('.email-checkbox').removeAttr('checked');
      return false;
    });

    // Listens for clicks on the results.
    $('#contacts li').click(function(e) {
      // Massive conflict here if this is triggered on the actual checkbox.
      if (e.target.nodeName.toLowerCase() != 'input') {
        var cb = $(this).find('.email-checkbox');
        if (cb.is(':checked')) {
          cb.removeAttr('checked');
        }
        else {
          cb.click();
        }
      }
    });

    // Shows the "check all / none" links, and invite button
    $('.check-area, .invite-button').show();

    // Stretch the scraper to fit all the lovely contacts
    $('#contact-picker-dialog', window.parent.document).css({
      'height': 'auto',
      'overflow': 'auto',
    });
    $('.contact-picker-dialog', window.parent.document).animate({ 'height': '750px' });
  },

  filter_contacts: function(filter) {
    var name, email;

    $('li').removeClass('hidden');
    if (filter.length >= 1) {
      filter = filter.toUpperCase();
      $('li').each(function() {
        name = $(this).find('span').text();
        email = $(this).find('strong').text();

        if (
          name.toUpperCase().indexOf(filter) === -1
          && email.toUpperCase().indexOf(filter) === -1
        ) {
          $(this).addClass('hidden');
        }
      });
    }
  },

  load_data: function(data) {
    $('#loading').fadeOut('fast');
    $('#response').html(data).queue(function() {
      DS.ContactPicker.init_results();
    });
  }
};