(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      //do stuff. no need for document.ready

      //NAV SLOW SCROLL
      $('#block-dosomething-campaign-styles-campaign-nav a').click(function (event) {
        $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');
        return false;
      });  

      //GAME LINKS SLOW SCROLL
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

    }
  };
})(jQuery);
