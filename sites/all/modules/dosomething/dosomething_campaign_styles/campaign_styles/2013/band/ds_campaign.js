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
    var fb_share_img = 'http://www.dosomething.org/files/campaigns/bands13/bandcampain.png';
    var fb_title = 'Band Together';
    var fb_header_caption = '';

    Drupal.behaviors.fb.feed({
      'feed_picture': fb_share_img,
      'feed_title': fb_title,
      'feed_caption': fb_header_caption,
      'feed_description': 'I used my voice to help save music education with DoSomething.org and the VH1 Save The Music Foundation. Join me at www.dosomething.org/band',
      'feed_selector': '.header-facebook-share',
    }, function(response){
      window.location.href = '/band#header';
    });

         
    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)


