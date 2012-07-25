(function($) {

Drupal.behaviors.dsPfpShare = {
  attach: function (context, settings) {
    var share = {
      method: 'stream.share',
      u: 'https://apps.facebook.com/zivtechdev' + window.location.pathname
    };
    $('#picsforpets-share').click(function () {
      FB.ui(share, function() {
        $.get('http://graph.facebook.com/https://apps.facebook.com/zivtechdev' + window.location.pathname, function (data) {
          var json = jQuery.parseJSON(data);
          $('.picsforpets-share-count').text(json.shares);
        });
        $.post('https://apps.facebook.com/zivtechdev/' + window.location.pathname + '/share', data);
      });
    });
  }
};

}(jQuery));
