(function ($) {
  Drupal.behaviors.jeans12_drive_pages = {
    attach: function (context, settings) {

    Drupal.friendFinder.fbObj = {
      feed_title: Drupal.t('Join your school\'s Teens for Jeans drive'),
      feed_description: Drupal.t('Join your school\'s Teens for Jeans drive to help fight teen homelessness. Sign up to spread the word about your school\'s awesome drive.'),
      feed_picture: '//files.dosomething.org/files/campaigns/jeans12/logo_clean.png',
      description: 'Join me and DoSomething.org to help fight teen homelessness!',
    }; 

    // inject banner copy on invite_friends form
    $('#invite_header').after('<img class="banner" src="//files.dosomething.org/files/campaigns/jeans12/invitepopup_cta.png"/>');

    // remove #edit-submit from drive page buttons
    $('#drive .drive-participants-list .form-submit').val('x').removeAttr('id').addClass('remove_participant');

    // invite module re-ordering
    $('.invite-module-email').after($('#teams-notification-area'));

    // hack-tastic #checklist build, ahoy!
    var checklist_labels = {
      "1": "<a href=\"/my-team/teensforjeans#invite-popup\">Invite friends</a> to participate in your school's drive",
      "2": "<a href=\"#social\" class\"jump_scroll\">Share stats</a> with your friends about homelessness on your social networks",
      "3": "Start to market your drive and make sure people in your school know about it",
      "4": "Talk to your school administrators to set up a collection point in your school for the jeans",
      "5": "<a href=\"/teensforjeans/report-back\">Tell us about your drive</a> and upload pics of your drive",
      "6": "Drop your collection off at your <a href=\"#search\" class=\"jump_scroll\">local Aeropostale store</a>. If you collect over 500 pairs, call the store to coordinate drop off.",
      "7": "Thank everyone for participating in your drive"
    };

    for (var label in checklist_labels) {
      if (checklist_labels.hasOwnProperty(label)) { 
        $('#edit-submitted-check' + label + ' label.option').html('<p>' + checklist_labels[label] + '</p>');
      }
    }

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
    $('.tw-share-drive').attr('data-text', 'Join a jeans collection drive in your school and get a 25% off coupon for a new pair at Aeropstale.');
    $('.fb-share-drive').click(function (e) {
      e.preventDefault();
      var fbObj = {
        method: 'feed',
        link: window.location.href,
        picture: 'http://files.dosomething.org/files/styles/thumbnail/public/fb_thumbs_0.jpg',
        name: 'Teens for Jeans',
        description: 'Join a jeans collection drive in your school and get a 25% off coupon for a new pair at Aeropstale. www.teensforjeans.org/'
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
