(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join Band Together',
      };

      // animation for a.jump_scroll
      var contentAnchors = 'a.jump_scroll';
      var navAnchors = '#block-dosomething-campaign-styles-campaign-nav a';
      var allAnchors = navAnchors + ', ' + contentAnchors;


      $(allAnchors).click(function(event){
        $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');  
        return false;
      });

    // #header section Facebook fun
    var fb_share_img = 'http://www.dosomething.org/files/campaigns/pregnancy/logo.png';
    var fb_title = 'Pregnancy Text';
    var fb_header_caption = '';

    Drupal.behaviors.fb.feed({
      'feed_picture': fb_share_img,
      'feed_title': fb_title,
      'feed_caption': fb_header_caption,
      'feed_description': 'Guys sort of play a big role in getting pregnant, so we think it’s time for them to learn a bit about it too. Put a baby in your friends\' phones for a day with @Do Something\'s Pregnancy Text and get them talking about how life would change if they were a parent: http://www.dosomething.org/baby',
      'feed_selector': '.header-facebook-share',
    }, function(response){
      window.location.href = '/band#header';
    });

         
    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
