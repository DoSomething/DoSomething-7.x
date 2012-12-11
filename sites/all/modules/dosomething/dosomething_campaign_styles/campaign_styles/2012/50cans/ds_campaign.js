(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join The 50 Cans Challenge!',
      };

      if (window.location.pathname.substr(0, 5) == '/team') {
        $signIn = $('#dosomething-login-login-popup-form');
        $signUp = $('#dosomething-login-register-popup-form');
        
        // if a popup has been triggered, set its destination
        if ($signIn.is(':visible') || $signUp.is(':visible')) {
          //var actionLink = $('.drive-action-link a').attr('href');
          //if (actionLink.charAt(0) == '/') actionLink = actionLink.substr(1);
          $signIn.attr('action', destinationReplace($signIn.attr('action'), actionLink));
          $signUp.attr('action', destinationReplace($signUp.attr('action'), actionLink));
        }
      }

     // function destinationReplace(url, destination) {
       // url = url.split('?');
        //query = url[1].split('&');
        //for (var i in query) {
          //var splitter = query[i].split('=');
          //if (splitter[0] == 'destination') {
            //splitter[1] = destination;
            //query[i] = splitter.join('=');
          //}
        //}
        //return url[0] + '?' + query;
      //}

      //$('.tw-share-drive').attr('data-text', 'It\'s time to #GiveASpit about cancer. A simple cheek swab is all it takes to save a life. Seriously. http://dosomething.org/spit');
      //$('.fb-share-drive').click(function (e) {
        //e.preventDefault();
        //var fbObj = {
          //method: 'feed',
          //link: window.location.href,
          //picture: 'http://files.dosomething.org/files/styles/thumbnail/public/fb_thumbs_0.jpg',
          //name: 'Give A Spit',
          //description: 'Are you ready to save a life? It\'s easier than you think. Click here to get your cheek swabbed and you could end up saving a life.'
        //};
        //FB.ui(fbObj);
      //});

      // edit drive info location change
      // $('#webform-client-form-724772 .form-item-submitted-field-drive-location-und-0-name-line label').empty().text('Name of Location');

      // drupal, eat your heart out
      var maxwell = "can have his cake and eat it too"

      if(maxwell == "can have his cake and eat it too"){
        $('#cmp #edit-actions').removeAttr('id');
      };

      // has logo, will inject
      var logo = '//files.dosomething.org/files/campaigns/alcoa/logo50cans.png';
      $('.region-sidebar-first').not('.logo-processed').addClass('logo-processed').prepend('<a href="/50cans"><img width="215" class="logo" src="' + logo + '"/></a>');

      // inject sponsor logo and text below the nav      
      //$('.region-sidebar-first .content').append('<img src="//files.dosomething.org/files/campaigns/spit/btm-logo.png"/>');

      // hacktastic form rebuilding
      var $emailInput = $('#edit-submitted-field-webform-email');
      var $cellInput = $('#edit-submitted-field-webform-mobile');

      $cellInput.before($emailInput); // re-arranges input field order
      $('#submitted-field-webform-email-add-more-wrapper').not('.ds-processed').addClass('.ds-processed').prepend($('#contact-form-email-label'));
      $('#submitted-field-webform-mobile-add-more-wrapper').not('.ds-processed').addClass('.ds-processed').prepend($('#contact-form-cell-label'));

      // removes search from nav on drive page
      if(document.location.pathname.slice(1,5) == "team") {
        $('li.campaign_nav_2').hide();
      }

      // Hol' a medz in da paddie, man
      var contactForm = $('.pane-campaign-sign-up');
      $('#header #contact-form').not('oneLove').addClass('oneLove').append(contactForm);

      // change over contact form
      var changeForm = $('.pane-campaign-signed');
      $('#header #contact-form').not('oneLove').addClass('oneLove').append(changeForm);      

      // on lines 9-10 terrible things happen
      $('#campaign-opt-in br').remove();
      $('.ctia_top').not('.classy').addClass('classy').append('&nbsp;');

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

      // twitter popup button on drive pages
      //$('a.drive-twitter').click(function(event) {
        //var width  = 650,
        //height = 450,
        //left   = ($(window).width()  - width)  / 2,
        //top    = ($(window).height() - height) / 2,
        //url    = this.href,
        //opts   = 'status=1' +
        //',width='  + width  +
        //',height=' + height +
        //',top='    + top    +
        //',left='   + left;

        //window.open(url, 'twitter', opts);

        //return false;
      //});

      // remove #edit-submit from drive page buttons
      //$('#drive .drive-participants-list .form-submit').val('x').removeAttr('id').addClass('remove_participant');

      // nav highlighting 
      var plainNav = '#block-dosomething-campaign-styles-campaign-nav li';
      var firstNav = plainNav + ' a' + '.first';

      $(firstNav).css('background','#FFCB15');
      $(plainNav + ' a').click(function(){
          $(this).css('background','#FFCB15').parent().find('a').css('background','#fff');
      });

      // sad puppy
      //$('#mangoDialog').dialog({autoOpen: false, dialogClass: "mangoDialog-ui", width: 500, resizable: false});
      //$('a.mango').click(function(){
        //$('#mangoDialog').dialog('open');
        //return false;
      //});

      // sad Chris
      //$('#chrisDialog').dialog({autoOpen: false, dialogClass: "mangoDialog-ui", width: 500, resizable: false});
      //$('a.mangoChris').click(function(){
        //$('#chrisDialog').dialog('open');
        //return false;
      //});

      // kill old asterisks from required fields
      $('#dosomething-login-register-popup-form .popup-content .field-suffix').remove();

      // search pane tweak
      $('.form-item-field-geofield-distance-unit').hide();
      $('.geofield-proximity-origin-from').text('Zip code:');

      // hide/show fieldset on drive form for checkbox
      /*$("#webform-component-check-show-hide").css('display','none');

      $("#edit-submitted-give-a-spit-action-kit-1").click(function() {
        if($("#edit-submitted-give-a-spit-action-kit-1").is(":checked")) {
          $("#webform-component-check-show-hide").show("fast");
        }
        else {
          $("#webform-component-check-show-hide").hide("fast");
        }
      });*/


    // Reload page on click 
      $('.ui-icon-closethick').click(function() {
        location.reload();
      });

      // Overlay Share Popup
      var url = "http://localhost:8080/50cans?sid=53905";
      $(function(){
        if (location.href==url){
          $('#overlay-environment').dialog({width: 1050, height: 700, modal: true, resizable: false});
        }
      });    

      // Overlay Skip Btn
      $('a#skip').click(function() {
          $('#overlay-environment').dialog('close')
      });

    // Overlay to Facebook Btn
    $('#overlay-share-btn').click(function() {
    $('#overlay-environment').dialog('close').queue(function() {
      Drupal.behaviors.fb.feed({
      feed_document: 'http://www.dosomething.org/50cans',
      feed_title: 'Stand up for the Environment',
      feed_picture: 'http://files.dosomething.org/files/u/home/official-doer1.png',
      feed_caption: 'I take action on environment… what do you do?',
      feed_description: 'Check out the environment cause',
      feed_modal: true
       }, function(response) {
         }); 
            });
                });

         
    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
