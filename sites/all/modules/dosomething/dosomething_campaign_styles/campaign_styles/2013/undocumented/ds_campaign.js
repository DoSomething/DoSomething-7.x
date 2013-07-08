(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join Undocumented',
      };

      // LOGO, will inject
      //var logo = '//www.dosomething.org/files/campaigns/puppy/puppytext-logo.png';
      //$('.region-sidebar-first').not('.logo-processed').addClass('logo-processed').prepend('<a href="/puppy"><img width="215" class="logo" src="' + logo + '"/></a>');
     
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

      // scrolling navigation block
      $(window).bind('load', function() {
        var $nav = $('#block-dosomething-campaign-styles-campaign-nav');
        var $footer = $('#block-menu-menu-footer');
        var $document = $(document);
        var scrollLimitTop = $nav.offset().top;
        $document.scroll(function () {
          var st = $document.scrollTop();
          var scrollLimitBot = $document.height() - $nav.outerHeight() - $footer.outerHeight();
          if (st > scrollLimitTop && st < scrollLimitBot) { // once scrolling engages $nav
            $nav.css({
              'position'    : 'fixed',
              'top'         : '0px',
              'bottom'      : 'auto',
              'z-index'     : '3'
            });
          }
          else if (st >= scrollLimitTop) { // once $nav hits $footer
            scrollLimitTop = $nav.offset().top;
            $nav
              .css('position', 'absolute')
              .css('top', 'auto')
              .css('bottom', '25px')
          }
          else { // before scrolling engages $nav
            scrollLimitTop = $nav.offset().top;
            $nav
              .css('position', 'static')
          }
        });
      }); // end scrolling nav

      $(allAnchors).click(function(event){
        $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');  
        return false;
      });


    // Mobile Commons success message
    if (document.location.search.slice(1,8) === 'success') {
      var success_msg = '<div class="success_msg"><p>Thanks for sharing. If you shared the text experience with six friends, you\'re been entered for the scholarship!</p></div>';
      $('#game').prepend(success_msg);
      $("html, body").animate({ scrollTop: $('#game').offset().top }, 1000);
    }

    // #header section Facebook fun
    var fb_share_img = 'http://www.dosomething.org/files/campaigns/undocumented/header.jpg';
    var fb_title = 'DoSomething.org\'s Undocumented For A Day';
    var fb_header_caption = '';

    Drupal.behaviors.fb.feed({
      'feed_picture': fb_share_img,
      'feed_title': fb_title,
      'feed_caption': fb_header_caption,
      'feed_description': 'There are 11 million undocumented immigrants in the United States. Wondering what a day in their life is like? Click here to experience it.',
      'feed_selector': '.header-facebook-share',
    }, function(response){
      window.location.href = '/undocumented#header';
    });

         
    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
