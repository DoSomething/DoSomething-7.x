(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join Pantry Prep',
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

      if(window.location.hash == "#sms-referral"){
        $('#sms-referral').fadeIn(2000);
      }

      // drupal, eat your heart out
      var maxwell = "can have his cake and eat it too"

      if(maxwell == "can have his cake and eat it too"){
        $('#cmp #edit-actions').removeAttr('id');
      };


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

    // kill old asterisks from required fields
    $('#dosomething-login-register-popup-form .popup-content .field-suffix').remove();

    // Reload page on click 
      $('.ui-icon-closethick').click(function() {
        location.reload();
      });

    // Report Back Weight Fuction
    var $output = $("#edit-submitted-ew");
    $("#edit-submitted-number-of-items").keyup(function() {
      var value = parseFloat($(this).val());
      if (isNaN(value)) value = 0;
      $output.val(Math.round(value*1));
    });  

    $.post('/webform-counter-field/725876/3', function (data) {
      $('#tackle-pounds').html(data);
    });
    
    // AJAX SMS fun via CJCodes
    // set some variables for quick reference so we don't re-parse every scroll
    var $window = $(window);
    var $showElement = $('#sms-map .sms-map-wrapper'); // SET this to whichever div will trigger the load.
    var showAt;

    var loaded = false; // whether or note we've loaded the content in

    // make sure the selector isn't broken
    if ($showElement.length > 0) {
      showAt = $showElement.offset().top; // store the offset at which we want to scroll in so we don't re-parse it every time
    }
    else {
      loaded = true; // there's no point in appending something to nothing, so let's not do anything
    }

    // SET iFrame content or whatever you want to load in later.
    var iFrameContent = $('<iframe width="800" height="500" scrolling="no" frameborder="no" src="https://www.google.com/fusiontables/embedviz?viz=MAP&q=select+col2+from+13NNXvmfca-saBJRfsTVmMZ7O9UmkfC7YoFCiNCs&h=false&lat=39.50404070558418&lng=-95.80078125&z=4&t=1&l=col2&y=1&tmplt=3"></iframe>');

    var windowBottom; // let's not re-initialize a variable every scroll. save some memory & cpu.

    $window.scroll(function () {
      // quick escape if we already loaded it in
      if (loaded) return;

      // find the current window bottom
      windowBottom = $window.scrollTop() + $window.height();

      // if we scrolled the bottom of the window past the element's start,
      // let's make it show up.
      if (windowBottom >= showAt) {
        loaded = true; // store this so we don't append an infinite amount of elements

        // SET this to your liking, maybe using insertBefore() or something and a fade?
        $showElement.append(iFrameContent);
      }
    });

    // Overlay Share Popup
    var url = "http://localhost:8080/pantryprep?sid=53905";
    $(function(){
      if (location.href==url){
        $('#overlay-disasters').dialog({width: 1050, height: 700, modal: true, resizable: false});
      }
    });

    // Overlay Skip Btn
    $('a#skip').click(function() {
        $('#overlay-disasters').dialog('close')
    });

    // Overlay to Facebook Btn
    $('#overlay-share-btn').click(function() {
    $('#overlay-disasters').dialog('close').queue(function() {
      Drupal.behaviors.fb.feed({
      feed_document: 'http://www.dosomething.org/pantryprep',
      feed_title: 'Disasters',
      feed_picture: 'http://files.dosomething.org/files/u/home/official-doer1.png',
      feed_caption: 'I take action on disasters… what do you do?',
      feed_description: 'Check out the disasters cause',
      feed_modal: true
       }, function(response) {
         }); 
            });
                });


    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
