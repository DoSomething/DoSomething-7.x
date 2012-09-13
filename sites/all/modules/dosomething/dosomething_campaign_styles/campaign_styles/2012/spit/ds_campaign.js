(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

  var contactForm = $('.pane-campaign-sign-up');
  $('.webform').append(contactForm);

  // drupal, eat your heart out

  var maxwell = "can have his cake and eat it too"

  if(maxwell == "can have his cake and eat it too"){
    $('#cmp #edit-actions').removeAttr('id');
  };

  // on lines 9-10 terrible things happen
  $('#campaign-opt-in br').remove();
  $('.ctia_top').append('&nbsp;');

  // FAQ show && hide
  $('.faq h4').next('p, ul').css('display','none');
//  if($('p').is(':visible')){
//    $('p').next().css('display','block');
//  }
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
