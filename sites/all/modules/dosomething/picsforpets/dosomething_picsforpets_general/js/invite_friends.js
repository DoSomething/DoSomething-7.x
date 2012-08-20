(function ($) {

Drupal.behaviors.inviteFriendsModal = {
  attach: function(context, settings) {
    window.fbAsyncInit = function() {
      FB.init({
        appId: '459236750767188',
        status: true,
        cookie: true
      });
    };

    $('.views-widget-sort-order, .views-submit-button').hide();
    $('#picsforpets-invite-friends').click(function() {
      var obj = {
        method: 'apprequests',
        display: 'iframe',
        title: 'The DoSomething.org Pics for Pets Project',
        message: 'You’ve been invited to help find shelter animals a new home with Pics for Pets. The more shares, the more food and toy donations the animals can get for their shelters. Help animals find a home!'
        //access_token: settings.fb_access_token
      };
      FB.ui(obj);
    });
  }
};

Drupal.behaviors.galleryShareButton = {
  attach: function (context, settings) {
    window.fbAsyncInit = function() {
      FB.init({
        appId: '459236750767188',
        status: true,
        cookie: true
      });
    };
    //var shareUrl = 'https://apps.facebook.com/picsforpets/webform-submission/' + sid;
    var share = {
      method: 'feed',
      name: 'Pics For Pets'
      //link: shareUrl,
      //picture: pictureUrl,
      //caption: petName,
      //description: "I'm " + threeWords[0] + ", " + threeWords[1] + ", and " + threeWords[2]
    };

    $('.gallery-share-button').click(function () {
      FB.ui(share, function(response) {
        // If the share was unsuccessful or the user clicked cancel, response
        // will be undefined. Otherwise it will be an object that contains the
        // post_id of the share.
        if (typeof response !== 'undefined') {
          // Use FB's JS SDK to retrieve and store the user's facebook id.
          var fbuid = FB.getUserID();
          // Make POST request to this URL to update the share count on the
          // webform submission, passing in the webform submission id and the
          // user's facebook id as URL arguments.
          $.post('https://apps.facebook.com/picsforpets/pics-for-pets/share/js/' + sid + '/' + fbuid, function (userShares) {
            // Update the page with the new share count.
            $('.picsforpets-share-count').text(userShares);
            // Display a modal dialog depending on the total number of shares
            // the user has made.
            if (userShares == 3) {
              $('<div></div>')
                .load('/pics-for-pets/ajax/thanks-for-sharing')
                .dialog({
                  title: Drupal.t('Thanks for sharing!'),
                  resizable: false,
                  draggable: false,
                  modal: true,
                  width: 550
                });
            }
            else if (userShares == 5) {
              var $message = $('<div>')
              .append($('<h2>').append(Drupal.t('Invite your friends to help more animals find homes!')))
              .append($('<div>').append(Drupal.t('Invite')))
              .dialog({
                title: Drupal.t('You\'ve helped 5 animals!'),
                resizable: false,
                draggable: false,
                modal: true,
                width: 550
              });
            }
          });
        }
      });
    });
  }
};

})(jQuery);
