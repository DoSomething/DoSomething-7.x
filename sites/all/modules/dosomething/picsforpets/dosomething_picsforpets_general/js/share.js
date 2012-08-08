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

    // Grab some text and a picture to share on the user's wall.
    // XXX: Because Facebook only increases the share count when using the
    // stream.share method, we can't use the feed method. And because we can't
    // use the feed method, we don't need these things. But if they happen to
    // change this in future, we can use these items to make a nicer, more
    // engaging share.
    /*
    var pictureUrl = $('.field-name-field-fb-app-image img').attr('src');
    var petName = $('.hi-pet-name p').text();
    var threeWords = [];
    jQuery.each($('.field-name-field-fb-app-three-words .field-items').children(), function() {
      threeWords.push($(this).text());
    });
    */

    // stream.share only allows us to post a link to the user's wall. We have to
    // use this method becuase other methods like 'feed' or 'stream.publish'
    // don't increase the share count of the url we're sharing.
    var shareUrl = 'https://apps.facebook.com/zivtechdev/webform-submission/' + sid;
    var share = {
      method: 'stream.share',
      u: shareUrl
    };

    $('#picsforpets-share').click(function () {
      FB.ui(share, function(response) {
        // If the share was unsuccessful or the user clicked cancel, response
        // will be undefined. Otherwise it will be an object that contains the
        // post_id of the share.
        if (typeof response !== 'undefined') {
          // Retrieve the number of shares on this URL.
          $.get('https://graph.facebook.com/' + shareUrl, function (data) {
            $('.picsforpets-share-count').text(data.shares);
          }, 'json');
          // Use FB's JS SDK to retrieve and store the user's facebook id.
          var fbuid = FB.getUserID();
          // Make POST request to this URL to update the share count on the
          // webform submission, passing in the webform submission id and the
          // user's facebook id as URL arguments.
          $.post('http://' + window.location.host + '/pics-for-pets/share/js/' + sid + '/' + fbuid, function (userShares) {
            // Display a modal dialog depending on the total number of shares
            // the user has made.
            if (userShares == 3) {
              $('<div></div>')
                .load('/pics-for-pets/thanks-for-sharing')
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
