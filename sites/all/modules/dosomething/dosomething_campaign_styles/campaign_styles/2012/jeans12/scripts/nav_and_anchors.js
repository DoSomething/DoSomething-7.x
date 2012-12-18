(function ($) {
  Drupal.behaviors.jeans12_nav = {
    attach: function (context, settings) {

    // animation for a.jump_scroll
    var contentAnchors = 'a.jump_scroll';
    var navAnchors = '#block-dosomething-campaign-styles-campaign-nav a';
    var allAnchors = navAnchors + ', ' + contentAnchors;
    
    // variables for input highlighting
    var webformEmail = '#contact-form input[type="text"]';
    var webformCell = '#contact-form input[type="tel"]';
    var webformBoth = webformEmail + ', ' + webformCell;
    
    $(document).ready(function(){
      $(webformEmail).focus().addClass('focusOutline');
    });
    $(webformBoth).focus(function(){
      $(this).addClass('focusOutline');
    });
    $(webformBoth).blur(function() {
      $(this).removeClass('focusOutline');
    });

    $(allAnchors).click(function(event){
      $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');  
      if($(this).attr('href') == '#header'){
        $(webformEmail).focus().addClass('focusOutline');
      }
      return false;
    });

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
    });
    
    // remove nav on all webform and instructional pages
    var urlCount = 14;
    var nakedPages = ['/sign-up', '/report-back', 'next', '/roadmap']
    for (var i=0; i < nakedPages.length; i++){
      if (window.location.pathname.substring(urlCount,30) == nakedPages[i]){
        $('div.region-sidebar-first').hide();
      }
    }

    // this is lazy
    var rsvp = '/rsvp';
    if (window.location.pathname.substring(urlCount,30) == rsvp){
      $('#block-dosomething-campaign-styles-campaign-nav').hide();
    }

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
