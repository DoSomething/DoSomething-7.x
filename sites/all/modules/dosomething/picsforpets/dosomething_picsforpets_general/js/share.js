(function($) {

Drupal.behaviors.dsPfpShare = {
  attach: function (context, settings) {
    if (settings.picsforpetsAnimals.images == undefined) {
      var sid = settings.picsforpetsAnimals.sid;
    }
    else {
      var sid = settings.picsforpetsAnimals.images[settings.picsforpetsAnimals.index].sid;
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
          var userShares = settings.picsforpetsAnimals.userShares;
          if (userShares == undefined) {
            userShares = 0;
          }
          userShares++;
          settings.picsforpetsAnimals.userShares = userShares;
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
