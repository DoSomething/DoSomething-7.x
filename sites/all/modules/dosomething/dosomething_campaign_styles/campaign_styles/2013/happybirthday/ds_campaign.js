(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join the 20th Birthday Celebration',
      };

	    // Background change on refresh
		$('#container').css({backgroundColor: "#fff"}); 
		var totalCount = 4; 
		var num = Math.ceil( Math.random() * totalCount );
		function setBGImage() { 
		    var bgimage = 'http://files.dosomething.org/files/campaigns/happybirthday/'+num+'.png';
		    $('body').css(
		    {
		    backgroundImage:"url("+bgimage+")",
		    backgroundRepeat: "repeat-x"
		    }); 
		} 
		setBGImage(); 


    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
