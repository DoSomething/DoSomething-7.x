(function ($) {
  Drupal.behaviors.jeans12_nav = {
    attach: function (context, settings) {

    // animation for a.jump_scroll
    var contentAnchors = 'a.jump_scroll';
    var navAnchors = '#block-dosomething-campaign-styles-campaign-nav a';
    var allAnchors = navAnchors + ', ' + contentAnchors;
    
    // input highlighting
    var webformEmail = '#contact-form input[type="text"]';
    var webformCell = '#contact-form input[type="tel"]';
    var webformBoth = webformEmail + ', ' + webformCell;

    $(allAnchors).click(function(event){
      $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');  

      if($(this).attr('href') == '/spit#header'){
        $(webformEmail).focus().addClass('focusOutline');
      }
      $(webformBoth).focus(function(){
        $(this).addClass('focusOutline');
      });
      $(webformBoth).blur(function() {
        $(this).removeClass('focusOutline');
      });
      return false;
    });

    // scrolling navigation block
    $(window).bind('load', function() {
      var $document = $(document);
      var $nav = $('#block-dosomething-campaign-styles-campaign-nav');
      var $footer = $('#block-menu-menu-footer');
      var scrollLimitTop = $nav.offset().top;
      var scrollLimitBot = $document.height() - $nav.outerHeight() - $footer.outerHeight();
      $document.scroll(function () {
        var st = $document.scrollTop();
        if (st > scrollLimitTop && st < scrollLimitBot) { // once scrolling engages $nav
          $nav.css({
            'position'    : 'fixed',
            'top'         : '0px',
            'bottom'      : 'auto',
            'z-index'     : '3'
          });
        }
        else if (st >= scrollLimitTop + $nav.outerHeight()) { // once $nav hits $footer
          $nav
            .css('position', 'absolute')
            .css('top', 'auto')
            .css('bottom', '25px')
        }
        else { // before scrolling engages $nav
          $nav
            .css('position', 'static')
        }
      });
    });
    
    // remove nav on all webform and instructional pages
    var teensforjeans = 14;
    var jeans12 = 8;
    var urlCount = jeans12;
    var nakedPages = ['/sign-up', '/report-back', 'next']
    for (var i=0; i < nakedPages.length; i++){
      if (window.location.pathname.substring(urlCount,30) == nakedPages[i]){
        $('div.region-sidebar-first').hide();
      }
    }

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
