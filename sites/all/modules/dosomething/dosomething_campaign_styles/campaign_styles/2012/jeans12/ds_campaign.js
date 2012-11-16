(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

    // removes #edit-actions id (?)
    $('#cmp #edit-actions').removeAttr('id');
    $('#cmp #edit-submit--2').removeAttr('id');

    // #checklist injection of footer
    $('#webform-component-footer').appendTo('#checklist');
    
    // AJAJ counter injection with /jeans12/counter webform
    $.post('/webform-counter-field/726458/1', function (data) {
      $('#schools_participating').html(data);
    });

    // #sms-referral confirmation message injection
    var sms_message = '<div id="sms-referral"><h3>Thanks for getting your friends involved!</h3></div>'
    if(document.location.hash == '#sms-referral'){
      $('#cmp').before(sms_message);
      $('#sms-referral h3').delay(1000).fadeIn();
    }

    // campaign logo injection
    var logo = '//files.dosomething.org/files/campaigns/jeans12/logo.png';
    $('.region-sidebar-first').not('.logo-processed').addClass('logo-processed').prepend('<a href="/teensforjeans"><img src="' + logo + '"/></a>');
    
    // campaign social media injection
    $('#header').prepend($('.socialWrapper'));

    // inject sponsor logo below footer
    cmpFooter = $('#footer');
    $('#cmp').after(cmpFooter);

    // contact form rebuilding
    var $emailInput = $('#edit-submitted-field-webform-email');
    var $cellInput = $('#edit-submitted-field-webform-mobile');

    $cellInput.before($emailInput); // re-arranges input field order
    $('#submitted-field-webform-email-add-more-wrapper').not('.ds-processed').addClass('ds-processed').prepend($('#contact-form-email-label'));
    $('#submitted-field-webform-mobile-add-more-wrapper').not('.ds-processed').addClass('ds-processed').prepend($('#contact-form-cell-label'));

    // contact form injection hack
    var contactForm = $('.pane-campaign-sign-up');
    $('#header #contact-form').not('oneLove').addClass('oneLove').append(contactForm);

    // format CTIA copy (remove line break and insert space)
    $('#campaign-opt-in br').remove();
    $('.ctia_top').not('.classy').addClass('classy').append('&nbsp;');

    // FAQ drop down animation
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

    // search module hack
    $('.form-item-field-geofield-distance-unit').hide();
    $('.geofield-proximity-origin-from').text('Zip code:');

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
