(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

    	// Sign Up Confirmation
    	if(location.pathname.match(/footlocker/) && location.search.match(/\?signup=&sid=[0-9A-Za-z\-]*/)) {
    		$("#fl-scholar-confirmation-popup").dialog({ width: 500, height: 370, modal: true, resizeable: false});
    	}

    	    	//  Confirmation
    	if(location.pathname.match(/footlocker/) && location.search.match(/\?cid=&sid=[0-9A-Za-z\-]*/)) {
    		$("#fl-nominate-confirmation-popup").dialog({ width: 500, height: 420, modal: true, resizeable: false});

    	}

        // eat it, Drupal! Application form description
        $('#webform-component-unweighted-gpa div.description').empty().append("(97-100) = 4.0 <br>(93-96) = 4.0 <br>(90-92) = 3.7 <br>(87-89) = 3.3 <br>(83-86) = 3.0 <br>(80-82) = 2.7 <br>(77-79) = 2.3 <br>(73-76) = 2.0 <br>(70-72) = 1.7 <br>(67-69) = 1.3 <br>(65-66) = 1.0 <br>(below 65) = 0.0");

    	$('a#popup-close').click(function(){
    		$('.ui-dialog').css('display', 'none');
            $('.ui-widget-overlay').css('display', 'none');
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
