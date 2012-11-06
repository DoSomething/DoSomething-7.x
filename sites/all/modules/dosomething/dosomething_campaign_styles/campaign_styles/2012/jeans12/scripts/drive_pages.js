(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

    // remove #edit-submit from drive page buttons
    $('#drive .drive-participants-list .form-submit').val('x').removeAttr('id').addClass('remove_participant');

    // invite module re-ordering
    $('.invite-module-email').after($('#teams-notification-area'));

    // twitter popup button on drive pages
    $('a.drive-twitter').click(function(event) {
      var width  = 650,
      height = 450,
      left   = ($(window).width()  - width)  / 2,
      top    = ($(window).height() - height) / 2,
      url    = this.href,
      opts   = 'status=1' +
      ',width='  + width  +
      ',height=' + height +
      ',top='    + top    +
      ',left='   + left;

      window.open(url, 'twitter', opts);

      return false;
    });

    // drive page social media
    $('.tw-share-drive').attr('data-text', 'It\'s time to #GiveASpit about cancer. A simple cheek swab is all it takes to save a life. Seriously. http://dosomething.org/spit');
    $('.fb-share-drive').click(function (e) {
      e.preventDefault();
      var fbObj = {
        method: 'feed',
        link: window.location.href,
        picture: 'http://files.dosomething.org/files/styles/thumbnail/public/fb_thumbs_0.jpg',
        name: 'Give A Spit',
        description: 'Are you ready to save a life? It\'s easier than you think. Click here to get your cheek swabbed and you could end up saving a life.'
      };
      FB.ui(fbObj);
    });

    // redirect drive sign-up to drive team page
    if (window.location.pathname.substr(0, 5) == '/team') {
      $signIn = $('#dosomething-login-login-popup-form');
      $signUp = $('#dosomething-login-register-popup-form');
      
      // if a popup has been triggered, set its destination
      if ($signIn.is(':visible') || $signUp.is(':visible')) {
        var actionLink = $('.drive-action-link a').attr('href');
        if (actionLink.charAt(0) == '/') actionLink = actionLink.substr(1);
        $signIn.attr('action', destinationReplace($signIn.attr('action'), actionLink));
        $signUp.attr('action', destinationReplace($signUp.attr('action'), actionLink));
      }
    }

    function destinationReplace(url, destination) {
      url = url.split('?');
      query = url[1].split('&');
      for (var i in query) {
        var splitter = query[i].split('=');
        if (splitter[0] == 'destination') {
          splitter[1] = destination;
          query[i] = splitter.join('=');
        }
      }
      return url[0] + '?' + query;
    }

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
