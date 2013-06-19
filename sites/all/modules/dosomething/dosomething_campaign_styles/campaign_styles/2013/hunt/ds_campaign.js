(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join The Hunt',
      };

      $('#cmp #edit-actions').removeAttr('id');

      // FAQ - onClick
      $('#faq h4').next('div').css('display','none');
      $('#faq h4.activeFAQ').next('div').css('display','block');
      $('#faq h4').click(function(){
        if($(this).hasClass('activeFAQ')){
          $(this).removeClass().next('div').slideUp();
        }
        else{
          $(this).addClass('activeFAQ');
          $(this).siblings('h4').removeClass('activeFAQ');
          $(this).next('div').slideToggle();
          $(this).siblings().next('div').slideUp();      
        }
      });

      // animation for a.jump_scroll
      var contentAnchors = 'a.jump_scroll';
      var navAnchors = '#block-dosomething-campaign-styles-campaign-nav a';
      var allAnchors = navAnchors + ', ' + contentAnchors;

      $(allAnchors).click(function(event){
        $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');  
        return false;
      });

      // #header section Facebook fun
      var fb_share_img = 'http://www.dosomething.org/files/campaigns/hunt13/Campaigns_Landing-15.png';
      var fb_title = 'The Hunt';
      var fb_header_caption = '';

      Drupal.behaviors.fb.feed({
        'feed_picture': fb_share_img,
        'feed_title': fb_title,
        'feed_caption': fb_header_caption,
        'feed_description': 'Adults think that teens are lazy and apathetic. Join The Hunt and show them and the world all of the amazing stuff you do in your community every day.',
        'feed_selector': '.header-facebook-share',
      }, function(response){
        window.location.href = '/hunt';
      });

         
    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
