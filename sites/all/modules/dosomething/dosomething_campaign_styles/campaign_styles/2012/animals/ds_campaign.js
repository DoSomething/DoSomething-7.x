(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

   var contactForm = $('.pane-campaign-sign-up');
   $('.s0 #webform').append(contactForm);

  // on lines 9-10 terrible things happen
  $('#campaign-opt-in br').remove();
  $('.ctia_top').append('&nbsp;');
	
  $('#appHook a').click(function(){
    $('#appHook').fadeOut(1000);
    setTimeout("jQuery('#appIcons').show()", 900);
    return false;
  });

  var local = "localhost:8080";
  var prod = "www.dosomething.org";
  var url = prod;

  if(document.URL == "http://" + url + "/picsforpets/mobile"){
    $('.region-sidebar-first').hide();
  }

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
