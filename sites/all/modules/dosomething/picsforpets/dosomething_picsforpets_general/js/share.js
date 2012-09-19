(function($) {

Drupal.behaviors.dsPfpShare = {
  adjectives: $('meta[property=cpj]').attr('content'),
  pname: $('meta[property=cpn]').attr('content'),
  pimg: $('.field-name-field-fb-app-image img').attr('src'),

  attach: function (context, settings) {

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
    var shareUrl = settings.picsforpetsFBAuth.app_secure_url + '/submit-pet-picture/submission/' + sid;
    var share = {
      method: 'feed',
      name: 'DoSomething.org\'s Pics For Pets',
      link: shareUrl,
      picture: pictureUrl,
      caption: petName + ". I'm " + threeWords[0] + ", " + threeWords[1] + ", and " + threeWords[2],
      description: "Do Something about homeless animals, share photos of shelter pets and help them find homes. The more shares a pet gets the better chance it'll be adopted, their shelter will also be rewarded for every share!"
    };

    $('#picsforpets-share').click(function () {
      var pname = Drupal.behaviors.dsPfpShare.pname;
      var adjectives = Drupal.behaviors.dsPfpShare.adjectives;
      var pimg = Drupal.behaviors.dsPfpShare.pimg;

      FB.api(
        '/me/dosomethingapp:share',
        'post',
        {
            pet_who_needs_a_home: document.location.href,
            message: 'Do Something about homeless animals, share photos of shelter pets and hel them find homes.  The more shares a pet gets the better chance it\'ll be adopted.  Their shelter will also be rewarded for every share!',
            pet_name: pname,
            pet_adjectives: adjectives,
            image: pimg
        },
      function(response) {
        // If the share was unsuccessful or the user clicked cancel, response
        // will be undefined. Otherwise it will be an object that contains the
        // post_id of the share.
        if ((typeof response !== 'undefined') && (response !== null)) {
          // Use FB's JS SDK to retrieve and store the user's facebook id.
          var fbuid = FB.getUserID();
          // Make POST request to this URL to update the share count on the
          // webform submission, passing in the webform submission id and the
          // user's facebook id as URL arguments.
          $.post('/fb/pics-for-pets/share/js/' + sid + '/' + fbuid, function (userShares) {
            // Increment the displayed share count.
            var count = $('.picsforpets-share-count').text();
            count++;
            $('.picsforpets-share-count').text(count);
            // Display a modal dialog depending on the total number of shares
            // the user has made.
            if (userShares == 3 && !settings.picsforpetsGeneral.furtographer) {
              $('<div></div>')
                .load('/fb/pics-for-pets/ajax/thanks-for-sharing?sid=' + sid + ' #dosomething-picsforpets-general-thanks-form')
                .dialog({
                  title: Drupal.t('Thanks for sharing!'),
                  resizable: false,
                  draggable: false,
                  modal: true,
                  top: 180,
                  width: 550
                });
            }
            else if (userShares == 5) {
              $('<div></div>')
                .load('/fb/pics-for-pets/ajax/invite-friends #dosomething-picsforpets-invite-form', function() {
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
                })
                .dialog({
                  title: Drupal.t('Hey, you\'ve shared 5 animals!'),
                  resizable: false,
                  draggable: false,
                  modal: true,
                  top: 180,
                  width: 550
                });
            }
          });
        }
      });
    });
  },

  blah: function(image, name, adjectives) {
    this.pname = name;
    this.pimg = image;
    this.adjectives = adjectives;
  }
};

}(jQuery));
