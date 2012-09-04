(function ($) {

Drupal.behaviors.inviteFriendsModal = {
  attach: function(context, settings) {
    $('.views-widget-sort-order, .views-submit-button').hide();
    $('#picsforpets-invite-friends').click(function() {
      var obj = {
        method: 'apprequests',
        display: 'iframe',
        title: 'The DoSomething.org Pics for Pets Project',
        message: 'You’ve been invited to help find shelter animals a new home with Pics for Pets. The more shares, the more food and toy donations the animals can get for their shelters. Help animals find a home!',
        access_token: settings.picsforpetsFBAuth.access_token,
        show_error: true
      };
      FB.ui(obj);
    });
  }
};

Drupal.behaviors.galleryShareButton = {
  attach: function (context, settings) {
    $('.gallery-share-button').click(function () {
      var sid = parseInt($(this).parent().attr('id'));
      var shareUrl = settings.picsforpetsFBAuth.app_secure_url + '/' + settings.picsforpetsFBAuth.fbFormAlias + '/submission/' + sid;
      var threeWords = [];
      threeWords[0] = 0 in settings.dosomething_picsforpets_general.gallery[sid].threeWords ? settings.dosomething_picsforpets_general.gallery[sid].threeWords[0].raw.safe_value : "Fun";
      threeWords[1] = 1 in settings.dosomething_picsforpets_general.gallery[sid].threeWords ? settings.dosomething_picsforpets_general.gallery[sid].threeWords[1].raw.safe_value : "Cute";
      threeWords[2] = 2 in settings.dosomething_picsforpets_general.gallery[sid].threeWords ? settings.dosomething_picsforpets_general.gallery[sid].threeWords[2].raw.safe_value : "Friendly";
      var share = {
        method: 'feed',
        name: 'DoSomething.org\'s Pics For Pets Project',
        link: shareUrl,
        picture: settings.picsforpetsFBAuth.appBaseURL + '/' + settings.dosomething_picsforpets_general.gallery[sid].pictureUrl,
        caption: settings.dosomething_picsforpets_general.gallery[sid].petName + ". I'm " + threeWords[0] + ", " + threeWords[1] + ", and " + threeWords[2],
        description: "@DoSomething about homeless animals, share photos of shelter pets and help them find homes. The more shares a pet gets the better chance it'll be adopted, their shelter will also be rewarded for every share!"
      };
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
          $.post('/pics-for-pets/share/js/' + sid + '/' + fbuid, function (userShares) {
            // Update the page with the new share count.
            // Increment the displayed share count.
            var countBox = $('#' + sid + ' .gallery-share-count');
            var count = countBox.text();
            count++;
            countBox.text(count);
            // Display a modal dialog depending on the total number of shares
            // the user has made.
            if (userShares == 3) {
              $('<div></div>')
                .load('/pics-for-pets/ajax/thanks-for-sharing #dosomething-picsforpets-general-thanks-form')
                .dialog({
                  title: Drupal.t('Thanks for sharing!'),
                  resizable: false,
                  draggable: false,
                  modal: true,
                  width: 550
                }
              );
            }
            else if (userShares == 5) {
              $('<div></div>')
                .load('/pics-for-pets/ajax/invite-friends #dosomething-picsforpets-invite-form')
                .dialog({
                  title: Drupal.t('Hey, you\'ve shared 5 animals!'),
                  resizable: false,
                  draggable: false,
                  modal: true,
                  width: 550
              });
              Drupal.attachBehaviors();
            }
          });
        }
      });
    });
  }
};

})(jQuery);
