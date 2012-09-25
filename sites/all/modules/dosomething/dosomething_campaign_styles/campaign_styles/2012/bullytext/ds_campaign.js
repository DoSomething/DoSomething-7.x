(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      //do stuff. no need for document.ready

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

      // FAQ
		$('.faq h4').next('p').css('display','none');
		$('.faq h4.activeFAQ').next('p').css('display','block');
		$('.faq h4').click(function(){
		  if($(this).hasClass('activeFAQ')){
		    $(this).removeClass().next('p').slideUp();
		  }
		  else{
		    $(this).addClass('activeFAQ');
		    $(this).siblings('h4').removeClass('activeFAQ');
		    $(this).next('p').slideToggle();
		    $(this).siblings().next('p').slideUp(); 
		  }
		});

      // MENU SCROLL
      var $window = $(window);
      var $nav = $('#block-dosomething-campaign-styles-campaign-nav');
      var scrollLimitTop = 175;
      var scrollLimitBot = $(document).height() - $('#block-menu-menu-footer').height() - $nav.height() + 50;

      $window.scroll(function () {
        var st = $window.scrollTop();
        if (st > scrollLimitTop && st < scrollLimitBot) {
          $nav.css({
            'position' : 'fixed',
            'top'      : '0px',
            'margin'   : '15px 0 0 0',
            'padding'  : '0 0 0 0',
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

    }
  };
})(jQuery);
