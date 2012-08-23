(function($) {

Drupal.behaviors.dsPfpShare = {
  attach: function (context, settings) {
    // Initialize Facebook's Javascript SDK asyncronously.
    window.fbAsyncInit = function() {
      FB.init({
        appId: '459236750767188',
        status: true,
        cookie: true
      });
    };

    // Retrieve the id of this webform submission.
    if (settings.fbappsAnimals.images == undefined) {
      var sid = settings.fbappsAnimals.sid;
    }
    else {
      var sid = settings.fbappsAnimals.images[settings.fbappsAnimals.index].sid;
    }

    // Grab some metadata.
    var pictureUrl = $('.field-name-field-fb-app-image img').attr('src');
    var petName = $('.hi-pet-name p').text();
    var threeWords = [];
    jQuery.each($('.field-name-field-fb-app-three-words .field-items').children(), function() {
      threeWords.push($(this).text());
    });

    // Use the 'feed' method because it allows us to post metadata.
    var shareUrl = 'https://apps.facebook.com/picsforpets/webform-submission/' + sid;
    var share = {
      method: 'feed',
      name: 'DoSomething.org\'s Pics For Pets Project',
      link: shareUrl,
      picture: pictureUrl,
      caption: petName + ". I'm " + threeWords[0] + ", " + threeWords[1] + ", and " + threeWords[2],
      description: "@DoSomething about homeless animals, share photos of shelter pets and help them find homes. The more shares a pet gets the better chance it'll be adopted, their shelter will also be rewarded for every share!"
    };

    $('#picsforpets-share').click(function () {
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

}(jQuery));
