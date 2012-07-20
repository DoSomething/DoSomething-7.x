(function ($) {

Drupal.behaviors.inviteFriendsModal = {
  attach: function(context, settings) {
    var token = settings.fb_access_token;
    $('#invite-friends').click(function() {
      var obj = {
        method: 'apprequests',
        display: 'iframe',
        title: 'The DoSomething.org Pics for Pets Project',
        message: 'You’ve been invited to help find shelter animals a new home with Pics for Pets. The more shares, the more food and toy donations the animals can get for their shelters. Help animals find a home!',
        access_token: settings.fb_access_token
      };
      FB.ui(obj);
    });
  }
};

})(jQuery);
