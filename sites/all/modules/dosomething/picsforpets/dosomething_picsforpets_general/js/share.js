(function($) {

Drupal.behaviors.dsPfpShare = {
  attach: function (context, settings) {
    if (settings.fbappsAnimals.images == undefined) {
      var sid = settings.fbappsAnimals.sid;
    }
    else {
      var sid = settings.fbappsAnimals.images[settings.fbappsAnimals.index].sid;
    }
    var share = {
      method: 'stream.share',
      u: 'https://apps.facebook.com/zivtechdev/webform-submission/' + sid
    };
    $('#picsforpets-share').click(function () {
      event.preventDefault();
      FB.ui(share, function(response) {
        console.log(response);
        // TODO: only update this stuff if the response shows there was a share not a cancel.
        $.get('http://graph.facebook.com/https://apps.facebook.com/zivtechdev/webform-submission/' + sid, function (data) {
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
      //  $.post('https://apps.facebook.com/zivtechdev/' + window.location.pathname + '/share', data);
      });
    });
  }
};

}(jQuery));
