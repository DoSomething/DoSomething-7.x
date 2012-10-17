(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

      // pop, bang, lovely FAQ
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

      //NAV SLOW SCROLL
      $('#block-dosomething-campaign-styles-campaign-nav a').click(function (event) {
        $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');
        return false;
      });  

     //JUMP LINKS SLOW SCROLL
      $('.jump').click(function (event) {
        $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');
        return false;
      });  

      
      // MENU SCROLL
      var $window = $(window);
      var $nav = $('#block-dosomething-campaign-styles-campaign-nav');
      var scrollLimitTop = 180;
      var scrollLimitBot = 5757;

      $window.scroll(function () {
        var st = $window.scrollTop();
        if (st > scrollLimitTop && st < scrollLimitBot) {
          $nav.css({
            'position' : 'fixed',
            'top'      : '0px',
            'margin'   : '15px 0 0 0',
            'padding'  : '1.5em 2em 1.5em 0',
            'z-index'  : '3'
          });
        }
        else if (st >= scrollLimitTop) {
          $nav
            .css('position', 'static')
        }
        else {
          $nav
            .css('position', 'static')
        }
      });


    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
