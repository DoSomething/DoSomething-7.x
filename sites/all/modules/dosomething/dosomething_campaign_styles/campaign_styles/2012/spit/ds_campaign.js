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

  // has logo, will inject
  var logo = 'http://files.dosomething.org/files/campaigns/spit/logo.png';
  $('.region-sidebar-first').not('.logo-processed').addClass('logo-processed').prepend('<img src="' + logo + '"/>');

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

  // pop, bang, lovely
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

  // jQuery scrolling effect
  var contentAnchors = 'a.jump_scroll';
  var navAnchors = '#block-dosomething-campaign-styles-campaign-nav a';
  var allAnchors = navAnchors + ', ' + contentAnchors;
  
  $(allAnchors).click(function(event){
    $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');  
    return false;
  });

  // sad puppy
  $('#mangoDialog').dialog({autoOpen: false, dialogClass: "mangoDialog-ui", width: 500, resizable: false});
  $('a.mango').click(function(){
    $('#mangoDialog').dialog('open');
    return false;
  });

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
