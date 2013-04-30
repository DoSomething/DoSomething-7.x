(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join The 50 Cans Challenge!',
      };

      // LOGO - injection
      var logo = '//www.dosomething.org/files/campaigns/wyr/logo-campaign.png';
      $('.region-sidebar-first').not('.logo-processed').addClass('logo-processed').prepend('<a href="/wyr"><img class="logo-campaign" src="' + logo + '"/></a>');

      // FAQ - onClick visibility
      $('#faq h4').next('div').css('display','none');
      $('#faq h4.activeFAQ').next('div').css('display','block');
      $('#faq h4').click(function() {
        if($(this).hasClass('activeFAQ')) {
          $(this).removeClass().next('div').slideUp();
        }
        else {
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

      // variables for input highlighting
      var webformEmail = '#contact-form input[type="text"]';
      var webformCell = '#contact-form input[type="tel"]';
      var webformBoth = webformEmail + ', ' + webformCell;

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
      var success_msg = '<div class="success_msg"><h2>Have we told you how amazing you are lately? Just the best.</h2></div>';
      $('#scholarship').prepend(success_msg);
    }

    // #share section Facebook fun
    var fb_share_img = 'http://www.dosomething.org/files/campaigns/wyr/bg-share1.png';
    var fb_title = 'Would You Rather?';
    var fb_caption = 'What would you rather do to save money?';

    // #header section Facebook fun
    var fb_header_caption = 'What would you rather do to save money?';

    Drupal.behaviors.fb.feed({
      'feed_picture': fb_share_img,
      'feed_title': fb_title,
      'feed_caption': fb_header_caption,
      'feed_description': 'Would you rather get a hair cut from a 5 yr old, or not get it cut for a year? Play Would You Rather w/ @dosomething: www.dosomething.org/wyr',
      'feed_selector': '.header-facebook-share',
    }, function(response){
      window.location.href = '/wyr#header';
    });

    Drupal.behaviors.fb.feed({
      'feed_picture': fb_share_img,
      'feed_title': fb_title,
      'feed_caption': fb_caption,
      'feed_description': 'I would eat only ramen for a month!',
      'feed_selector': '.share-link-ramen',
    }, function(response){
      window.location.href = '/wyr#share';
    });

    Drupal.behaviors.fb.feed({
      'feed_picture': fb_share_img,
      'feed_title': fb_title,
      'feed_caption': fb_caption,
      'feed_description': 'I would eat only canned tuna for a month!',
      'feed_selector': '.share-link-tuna',
    }, function(response){
      window.location.href = '/wyr#share';
    });

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
