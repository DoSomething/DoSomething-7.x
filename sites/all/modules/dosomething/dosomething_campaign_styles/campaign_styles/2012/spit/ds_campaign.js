(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      Drupal.settings.login = {
        replaceText      : 'Nanu nanu',
        afterReplaceText : 'Wacka wacka',
      };

      if (window.location.pathname.substr(0, 5) == '/team') {
        $signIn = $('#dosomething-login-login-popup-form');
        $signUp = $('#dosomething-login-register-popup-form');
        
        // if a popup has been triggered, set its destination
        if ($signIn.is(':visible') || $signUp.is(':visible')) {
          var actionLink = $('.drive-action-link a').attr('href');
          if (actionLink.charAt(0) == '/') actionLink = actionLink.substr(1);
          $signIn.attr('action', destinationReplace($signIn.attr('action'), actionLink));
          $signUp.attr('action', destinationReplace($signUp.attr('action'), actionLink));
        }
      }

      function destinationReplace(url, destination) {
        url = url.split('?');
        query = url[1].split('&');
        for (var i in query) {
          var splitter = query[i].split('=');
          if (splitter[0] == 'destination') {
            splitter[1] = destination;
            query[i] = splitter.join('=');
          }
        }
        return url[0] + '?' + query;
      }

      $('.tw-share-drive').attr('data-text', 'Twitter language needs to be done!');
      $('.fb-share-drive').click(function (e) {
        e.preventDefault();
        var fbObj = {
          method: 'feed',
          link: window.location.href,
          picture: '//files.dosomething.org/files/styles/thumbnail/public/fb_thumbs_0.jpg',
          name: 'Name text here!',
          description: 'Description text here!'
        };
        FB.ui(fbObj);
      });

      // Sorry, this indentation was driving me nuts.
      // swoop!

      // drupal, eat your heart out
      var maxwell = "can have his cake and eat it too"

      if(maxwell == "can have his cake and eat it too"){
        $('#cmp #edit-actions').removeAttr('id');
      };

      // has logo, will inject
      var logo = '//files.dosomething.org/files/campaigns/spit/logo.png';
      $('.region-sidebar-first').not('.logo-processed').addClass('logo-processed').prepend('<a href="/spit12"><img src="' + logo + '"/></a>');

      // hacktastic form rebuilding
      var emailInput = $('#edit-submitted-field-webform-email');
      var cellInput = $('#edit-submitted-field-webform-mobile');
      var emailWrapper = $('#contact-form #submitted-field-webform-email-add-more-wrapper div.form-item');
      var cellWrapper = $('#contact-form #submitted-field-webform-mobile-add-more-wrapper div.form-item');

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

        if($('a').attr('href','/spit12#header')){
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

      // remove #edit-submit from drive page buttons
      $('#drive .drive-participants-list .form-submit').val('x').removeAttr('id').addClass('remove_participant');

      // nav highlighting 
      var plainNav = '#block-dosomething-campaign-styles-campaign-nav li';
      var firstNav = plainNav + ' a' + '.first';

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
      
      // Hol' a medz in da paddie, man
      var contactForm = $('.pane-campaign-sign-up');
      $('#header #contact-form').not('oneLove').addClass('oneLove').append(contactForm);

      // scroll function
      var $window = $(window);
      var $nav = $('#block-dosomething-campaign-styles-campaign-nav');
      var scrollLimitTop = 500;
      var scrollLimitBot = $(document).height() - $('#block-menu-menu-footer').height() - $nav.height() + 50;

      $window.scroll(function () {
        var st = $window.scrollTop();
        if (st > scrollLimitTop && st < scrollLimitBot) {
          $nav.css({
            'position' : 'fixed',
            'top'      : '0px',
            'margin'   : '15px 0 0 0',
            'padding'  : '1.5em 2em 1.5em 0',
            'z-index'  : '3'
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

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
