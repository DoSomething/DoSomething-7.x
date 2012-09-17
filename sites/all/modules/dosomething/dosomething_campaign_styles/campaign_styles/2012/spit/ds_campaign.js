//
//    Chris,
//    
//    Advert thy eyes.
//    
//    Sincerely,
//    Maxwell
//
//

(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

  var contactForm = $('.pane-campaign-sign-up');
  $('#webform').append(contactForm);

  // drupal, eat your heart out

  var maxwell = "can have his cake and eat it too"

  if(maxwell == "can have his cake and eat it too"){
    $('#cmp #edit-actions').removeAttr('id');
  };

  // hacktastic form rebuilding
  var emailInput = $('#edit-submitted-field-webform-email');
  var cellInput = $('#edit-submitted-field-webform-mobile');
  var emailWrapper = $('#submitted-field-webform-email-add-more-wrapper div.form-item');
  var cellWrapper = $('#submitted-field-webform-mobile-add-more-wrapper div.form-item');

  $(cellInput).before(emailInput);
  $(emailWrapper).not('.ds-processed').addClass('.ds-processed').prepend('<label>email:</label>');
  $(cellWrapper).not('.ds-processed').addClass('.ds-processed').prepend('<label>cell:</label>');

  // on lines 9-10 terrible things happen
  $('#campaign-opt-in br').remove();
  $('.ctia_top').append('&nbsp;');

  // Pop, bang, lovely.
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

  var headerLinks = $('#action, #content-infographic, #content-leader, #faq, #header, #impact, #scholarship, #search, #webform');

  $(headerLinks).click(function (event) {
    $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');
    return false;
  });

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
