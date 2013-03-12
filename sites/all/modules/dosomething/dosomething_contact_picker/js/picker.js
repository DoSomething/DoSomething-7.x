$(document).ready(function() {
  $('.remove-that-loader', window.parent.document).hide();
  $('#contacts-scraper-dialog', window.parent.document).css('height', 'auto');
});

var DS = {};
DS.ContactPicker = {
  service: function(s) {
    console.log(path);
    console.log("!");
    jQuery('#loading').show().html('<img src="/sites/all/modules/dosomething/dosomething_contact_picker/images/loading.gif" alt="" /> Loading.  Please wait...');
    eval(s).auth('/sites/all/modules/dosomething/dosomething_contact_picker');
    return false;
  },

  prepare_clicks: function() {
    $('.check-all').click(function() {
      $('.email-checkbox').click();
      return false;
    });

    $('.check-none').click(function() {
      $('.email-checkbox').removeAttr('checked');
      return false;
    });
  },
};