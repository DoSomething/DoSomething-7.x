(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

    // removes #edit-actions id (?)
    $('#cmp #edit-actions').removeAttr('id');
    $('#cmp #edit-submit--2').removeAttr('id');

    // #checklist injection of footer
    $('#webform-component-footer').appendTo('#checklist');
    
    // AJAJ counter injection with /teensforjeans/counter webform
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

    // Add Gallery link hashtag to take user back to gallery area on reload
    $('.pager li a').attr("href", function(i, href) { return href + "#galleriffic"; });

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

    // #contact-form submit button value change
    $('#cmp #header .form-submit').attr('value','start');


  // Overlay Share Popup
  var url = "http://www.dosomething.org/teensforjeans?sid=53905";
  $(function(){
    if (location.href==url){
      $('#overlay-homelessness').dialog({width: 1050, height: 700, modal: true, resizable: false});
    }
  });

      // Overlay Skip Btn
  $('a#skip').click(function() {
      $('#overlay-homelessness').dialog('close')
  });

    // Overlay to Facebook Btn
    $('#overlay-share-btn').click(function() {
      $('#overlay-homelessness').dialog('close').queue(function() {
        Drupal.behaviors.fb.feed({
        feed_document: 'http://www.dosomething.org/teensforjeans',
        feed_title: 'Homelessness',
        feed_picture: 'http://files.dosomething.org/files/u/home/official-doer1.png',
        feed_caption: 'I help the homeless because I care. How about you?',
        feed_description: 'Donate your old or unwanted jeans to a teen in need.',
        feed_modal: true
         }, function(response) {
         }); 
      });
    });

    jQuery(window).bind('load', function() {
      var $form = jQuery('#contact-form');
      var $footer = jQuery('#block-menu-menu-footer');
      var $document = jQuery(document);
      var scrollLimitTop = $form.offset().top;
      $document.scroll(function () {
        var st = $document.scrollTop();
        var scrollLimitBot = $document.height() - $form.outerHeight() - $footer.outerHeight();
        if (st > scrollLimitTop && st < scrollLimitBot) { // once scrolling engages $form
          $form.css({
            'position'      : 'fixed',
            'top'           : '0px',
            'bottom'        : 'auto',
            'z-index'       : '3',
            'width'         : '800px',
            'height'        : '123px',
            'padding'       : '10px 10px 0 10px',
            'border-bottom' : '15px solid #fff'
          }); 
        }   
        else if (st >= scrollLimitTop) { // once $form hits $footer
          scrollLimitTop = $form.offset().top;
          $form
            .css('position', 'absolute')
            .css('top', 'auto')
            .css('bottom', '25px')
        }   
        else { // before scrolling engages $form
          scrollLimitTop = $form.offset().top;
          $form
            .css('position', 'static')
        }   
      }); 
    });

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
