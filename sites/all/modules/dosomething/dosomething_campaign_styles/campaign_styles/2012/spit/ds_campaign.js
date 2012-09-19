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

  // remove #edit-submit from drive page buttons
  $('#drive .drive-participants-list .form-submit').val('x').removeAttr('id').addClass('remove_participant');

  // nav highlighting 
  var plainNav = '#block-dosomething-campaign-styles-campaign-nav li';
  var firstNav = plainNav + ' a' + '.first';

//  $(firstNav).addClass('highlight');
//  $(plainNav + ' a').click(function(){
//    $(this).parent().addClass('highlight').siblings().removeClass('highlight');
//  });
  $(firstNav).css('background','#FFCB15');
  $(plainNav + ' a').click(function(){
      $(this).css('background','#FFCB15').parent().find('a').css('background','#fff');
  });

  // sad puppy
  $('#mangoDialog').dialog({autoOpen: false, dialogClass: "mangoDialog-ui", width: 500, resizable: false});
  $('a.mango').click(function(){
    $('#mangoDialog').dialog('open');
    return false;
  });

  // sad Chris
  $('#chrisDialog').dialog({autoOpen: false, dialogClass: "mangoDialog-ui", width: 500, resizable: false});
  $('a.mangoChris').click(function(){
    $('#chrisDialog').dialog('open');
    return false;
  });

  // scroll function
  var $window = $(window);
  var $nav = $('#block-dosomething-campaign-styles-campaign-nav');
  var scrollLimitTop = 500;
  var scrollLimitBot = $(document).height() - $('#block-menu-menu-footer').height() - $nav.height() + 50;

  $window.scroll(function () {
    var st = $window.scrollTop();
    if (st > scrollLimitTop && st < scrollLimitBot) {
      $nav
        .css('position','fixed')
        .css('top','0px')
        .css('margin','15px 0 0 0')
        .css('padding','1.5em 2em 1.5em 0')
        .css('z-index','3')
    }
    else if (st >= scrollLimitTop) {
      $nav
        .css('position', 'static')
    }
    else {
      $nav
        .css('position', 'static')
    }
  });

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
