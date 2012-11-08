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
        $('#webform-component-unweighted-gpa div.description').empty().append("(97-100) = 4.0 <br>(93-96) = 4.0 <br>(90-92) = 3.7 <br>(87-89) = 3.3 <br>(83-86) = 3.0");

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

        // Application Page Status Button
        if($('#webform-client-form-724592')) {
        $('#edit-actions').append('<p class="status-btn go-button"><a href="//www.dosomething.org/footlocker/apply/status/">Status Page</a></p>'); }

        // Application Page Draft Message
        if ($('.status').has("Submission saved")) {
        $('.status').html('<p>Your application has been saved. To return to your status page and complete your recommendation requests, select "Status Page" at the bottom of the page</p>'); }

    }
  };
})(jQuery);
