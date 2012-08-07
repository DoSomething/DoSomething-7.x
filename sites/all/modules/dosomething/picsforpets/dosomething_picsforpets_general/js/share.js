(function($) {

Drupal.behaviors.dsPfpShare = {
  attach: function (context, settings) {
    window.fbAsyncInit = function() {
      FB.init({
        appId: '459236750767188',
        status: true,
        cookie: true
      });
    };
    if (settings.fbappsAnimals.images == undefined) {
      var sid = settings.fbappsAnimals.sid;
    }
    else {
      var sid = settings.fbappsAnimals.images[settings.fbappsAnimals.index].sid;
    }

    // Grab some text and a picture to share on the user's wall.
    var pictureUrl = $('.field-name-field-fb-app-image img').attr('src');
    var petName = $('.hi-pet-name p').text();
    var threeWords = [];
    jQuery.each($('.field-name-field-fb-app-three-words .field-items').children(), function() {
      threeWords.push($(this).text());
    });

    var shareUrl = 'https://apps.facebook.com/zivtechdev/webform-submission/' + sid;
    var share = {
      method: 'stream.share',
      u: shareUrl
    };

    $('#picsforpets-share').click(function () {
      FB.ui(share, function(response) {
        if (typeof response !== 'undefined') {
          $.get('https://graph.facebook.com/' + shareUrl, function (data) {
            $('.picsforpets-share-count').text(data.shares);
            var userShares = settings.fbappsAnimals.userShares;
            if (userShares == undefined) {
              userShares = 0;
            }
            userShares++;
            settings.fbappsAnimals.userShares = userShares;
            if (userShares == 3) {
              // TODO: open the thank you dialog.
              alert('three');
            }
          }, 'json');
          // Make POST request to this URL to update the share count on the
          // webform submission.
          $.post('https://' + window.location.host + '/pics-for-pets/share/js/' + sid);
        }
      });
    });
  }
};

}(jQuery));
