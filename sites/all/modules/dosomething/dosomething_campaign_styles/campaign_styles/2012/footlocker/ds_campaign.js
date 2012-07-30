(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

    	// Sign Up Confirmation
    	if(location.pathname.match(/footlocker/) && location.search.match(/\?sid=[0-9A-Za-z\-]*/)) {
    		$("#fl-scholar-confirmation-popup").dialog({ width: 500, height: 370, modal: true, resizeable: false});
    	}

    	    	//  Confirmation
    	if(location.pathname.match(/footlocker/) && location.search.match(/\?cid=&sid=[0-9A-Za-z\-]*/)) {
    		$("#fl-nominate-confirmation-popup").dialog({ width: 500, height: 420, modal: true, resizeable: false});

    	}

    	$('a#popup-close').click(function(){
    		$('.ui-dialog').css('display', 'none');
            $('.ui-widget-overlay').css('display', 'none');
    	});

    }
  };
})(jQuery);
