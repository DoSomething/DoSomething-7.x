(function($) {

Drupal.behaviors.dsPfpShare = {
  attach: function (context, settings) {
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
    // The 'feed' method is newer and allows us to make a more engaging share
    // with a picture and descriptive text. If the share is successful, this
    // method will return an object with the post_id of the share. Otherwise
    // it will return null.
    var share = {
      method: 'feed',
      name: 'DoSomething.org\'s Pics for Pets project.',
      link: settings.dosomething_picsforpets_general.app_url + '/' + sid,
      picture: pictureUrl,
      caption: petName,
      description: "I'm " + threeWords[0] + ", " + threeWords[1] + ", and " + threeWords[2] + "."
    };
    $('#picsforpets-share').click(function () {
      // This was causing problems for me. - Dave
      //event.preventDefault();
      FB.ui(share, function(response) {
        // response will be an object (success) or null (cancel or fail).
        if (response) {
          $.get('https://graph.facebook.com/' + settings.dosomething_picsforpets_general.app_url + '/webform-submission/' + sid, function (data) {
            var json = jQuery.parseJSON(data);
            $('.picsforpets-share-count').text(json.shares);
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
          });
        }
      });
    });
  }
};

}(jQuery));
