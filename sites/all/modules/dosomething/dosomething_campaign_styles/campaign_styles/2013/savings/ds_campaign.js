(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join Mind On My Money!',
      };

      if (window.location.pathname.substr(0, 5) == '/team') {
        $signIn = $('#dosomething-login-login-popup-form');
        $signUp = $('#dosomething-login-register-popup-form');
        
        // if a popup has been triggered, set its destination
        if ($signIn.is(':visible') || $signUp.is(':visible')) {
          $signIn.attr('action', destinationReplace($signIn.attr('action'), actionLink));
          $signUp.attr('action', destinationReplace($signUp.attr('action'), actionLink));
        }
      }

      // has logo, will inject
      var logo = '//files.dosomething.org/files/campaigns/savings/logo3.png';
      $('.region-sidebar-first').not('.logo-processed').addClass('logo-processed').prepend('<a href="/savings"><img width="215" class="logo" src="' + logo + '"/></a>');

      $('#cmp #edit-actions').removeAttr('id');
     
      // hacktastic form rebuilding
      var $emailInput = $('#edit-submitted-field-webform-email');
      var $cellInput = $('#edit-submitted-field-webform-mobile');

      $cellInput.before($emailInput); // re-arranges input field order
      $('#submitted-field-webform-email-add-more-wrapper').not('.ds-processed').addClass('.ds-processed').prepend($('#contact-form-email-label'));
      $('#submitted-field-webform-mobile-add-more-wrapper').not('.ds-processed').addClass('.ds-processed').prepend($('#contact-form-cell-label'));


      // contact form login
      $('.pane-campaign-sign-up .form-actions').append('<p>Already signed up? <a href="/user?destination=node/728323" class="sign-in-popup">log in</a></p>');

      // Hol' a medz in da paddie, man
      var contactForm = $('.pane-campaign-sign-up');
      $('#header #contact-form').not('oneLove').addClass('oneLove').append(contactForm);

      // change over contact form
      var changeForm = $('.pane-campaign-signed');
      $('#header #contact-form').not('oneLove').addClass('oneLove').append(changeForm);

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

      // animation for a.jump_scroll
      var contentAnchors = 'a.jump_scroll';
      var navAnchors = '#block-dosomething-campaign-styles-campaign-nav a';
      var allAnchors = navAnchors + ', ' + contentAnchors;

      // variables for input highlighting
      var webformEmail = '#contact-form input[type="text"]';
      var webformCell = '#contact-form input[type="tel"]';
      var webformBoth = webformEmail + ', ' + webformCell;

      // scrolling navigation block
      $(window).bind('load', function() {
        var $nav = $('#block-dosomething-campaign-styles-campaign-nav');
        var $footer = $('#block-menu-menu-footer');
        var $document = $(document);
        var scrollLimitTop = $nav.offset().top;
        $document.scroll(function () {
          var st = $document.scrollTop();
          var scrollLimitBot = $document.height() - $nav.outerHeight() - $footer.outerHeight();
          if (st > scrollLimitTop && st < scrollLimitBot) { // once scrolling engages $nav
            $nav.css({
              'position'    : 'fixed',
              'top'         : '0px',
              'bottom'      : 'auto',
              'z-index'     : '3'
            });
          }
          else if (st >= scrollLimitTop) { // once $nav hits $footer
            scrollLimitTop = $nav.offset().top;
            $nav
              .css('position', 'absolute')
              .css('top', 'auto')
              .css('bottom', '25px')
          }
          else { // before scrolling engages $nav
            scrollLimitTop = $nav.offset().top;
            $nav
              .css('position', 'static')
          }
        });
      }); // end scrolling nav

      $(document).ready(function(){
        $(webformEmail).focus().addClass('focusOutline');
      });
      $(webformBoth).focus(function(){
        $(this).addClass('focusOutline');
      });
      $(webformBoth).blur(function() {
        $(this).removeClass('focusOutline');
      });

      $(allAnchors).click(function(event){
        $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');  
        if($(this).attr('href') == '#header'){
          $(webformEmail).focus().addClass('focusOutline');
        }
        return false;
      });


      // nav highlighting 
      var plainNav = '#block-dosomething-campaign-styles-campaign-nav li';
      var firstNav = plainNav + ' a' + '.first';

      $(firstNav).css('background','#FFCB15');
      $(plainNav + ' a').click(function(){
          $(this).css('background','#FFCB15').parent().find('a').css('background','#fff');
      });

      //report-back radio option select questions to show
      //$('#edit-submitted-which-session-did-you-lead-1').val('webform-component-budgeting');
      //$('#edit-submitted-which-session-did-you-lead-2').val('webform-component-credit-cards');
      //$('#edit-submitted-which-session-did-you-lead-3').val('webform-component-student-loans');

      $("input[type=radio]").click(function() {
        var test = $(this).val();
        $(".webform-component-fieldset").hide();
        $("#"+test).show();
        $("#" +test + "> div.fieldset-wrapper > div.webform-component-textarea > div.form-textarea-wrapper > textarea").validate();
      }); 

         
    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
