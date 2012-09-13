(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

   var contactForm = $('.pane-campaign-sign-up');
   $('.webform').append(contactForm);

  // on lines 9-10 terrible things happen
  $('#campaign-opt-in br').remove();
  $('.ctia_top').append('&nbsp;');

  // FAQ show && hide
  $('.faq h4').next('p, ul').css('display','none');
  $('.faq h4.activeFAQ').next('p, ul').css('display','block');
  $('.faq h4').click(function(){
    if($(this).hasClass('activeFAQ')){
      $(this).removeClass().next('p, ul').slideUp();
    }
    else{
      $(this).addClass('activeFAQ');
      $(this).siblings('h4').removeClass('activeFAQ');
      $(this).next('p, ul').slideToggle();
      $(this).siblings().next('p, ul').slideUp();      
    }
  }); 
    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
