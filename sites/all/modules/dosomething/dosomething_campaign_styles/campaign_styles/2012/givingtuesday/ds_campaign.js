(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      
      // quiz submission
      var $quizForm = $('#webform-client-form-726580');
      if ($quizForm.length > 0 && $quizForm.find('input[type="radio"]').length > 0) {
        $quizForm.submit(function () {
          var right = 0;
          $quizForm.find('input[type="radio"]:checked').each(function () {
            if ($(this).val() == 'right') {
              right++;
            }
          });
          $quizForm.attr('action', $quizForm.attr('action')+'?destination=momandpopquiz/results/'+right);
          return true;
        });
      }

      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org!',
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

      // Giving Tuesday Refer Form Style
      $('#refer > .pane-content > form').append('<div style="clear:both;" />');
      $('#refer > .pane-content').wrap('<div class="refer6-inner" />');
      $('.refer6-inner').wrap('<div class="refer6" />');
      $('#refer').css('background', 'white');

      // campaign social media injection
      $('#header').prepend($('.socialWrapper'));


      // drupal, eat your heart out
      $('#cmp #edit-actions').removeAttr('id');



      // hacktastic form rebuilding
      var $emailInput = $('#edit-submitted-field-webform-email');
      var $cellInput = $('#edit-submitted-field-webform-mobile');

      $cellInput.before($emailInput); // re-arranges input field order
      $('#submitted-field-webform-email-add-more-wrapper').not('.ds-processed').addClass('.ds-processed').prepend($('#contact-form-email-label'));
      $('#submitted-field-webform-mobile-add-more-wrapper').not('.ds-processed').addClass('.ds-processed').prepend($('#contact-form-cell-label'));


      // contact form login
      $('.pane-campaign-sign-up .form-actions').append('<p>Already signed up? <a href="/user?destination=node/725867" class="sign-in-popup">log in</a></p>');

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

      // jQuery scrolling effect with focus!
      var contentAnchors = 'a.jump_scroll';
      var navAnchors = '#block-dosomething-campaign-styles-campaign-nav a';
      var allAnchors = navAnchors + ', ' + contentAnchors;
      
      // input highlighting
      var webformEmail = '#contact-form input[type="text"]';
      var webformCell = '#contact-form input[type="tel"]';
      var webformBoth = webformEmail + ', ' + webformCell;

      $(allAnchors).click(function(event){
        $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');  

        if($(this).attr('href') == '#header'){
          $(webformEmail).focus().addClass('focusOutline');
        }
        $(webformBoth).focus(function(){
          $(this).addClass('focusOutline');
        });
        $(webformBoth).blur(function() {
          $(this).removeClass('focusOutline');
        });
        return false;
      });
      
      // scroll function
      var $window = $(window);
      var $nav = $('#block-dosomething-campaign-styles-campaign-nav');
      var scrollLimitTop = 195;
      var scrollLimitBot = 5757;

      $window.scroll(function () {
        var st = $window.scrollTop();
        if (st > scrollLimitTop && st < scrollLimitBot) {
          $nav.css({
            'position'    : 'fixed',
            'top'         : '25px',
            'margin'      : '25px 0 0 0px',
            'z-index'     : '3'
          });
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

      // kill old asterisks from required fields
      $('#dosomething-login-register-popup-form .popup-content .field-suffix').remove();

    // Reload page on click 
      $('.ui-icon-closethick').click(function() {
        location.reload();
      });

    // Report Back Counter Function
    $.post('/webform-counter-field/726580', function (data) {
      $('#sb-counter').html(data);
    });


    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
