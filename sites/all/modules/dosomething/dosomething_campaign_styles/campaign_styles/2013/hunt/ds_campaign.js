(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join The Hunt',
      };

      $('#cmp #edit-actions').removeAttr('id');

      // FAQ - onClick
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

      // Toggle the daily challenges
      challenges_toggle = function(question, response) {

        var $question = $('#info ' + question);
        var $question_active = $('#info ' + question + '.active');

        $question.next(response).hide();
        $question_active.next(response).show();

        $question.click(function() {
          $this = $(this);
          if( !$this.hasClass('active') ) {
            $this.addClass('active');
            $this.siblings(question).removeClass('active');
            $this.next(response).slideToggle();
            $this.siblings().next(response).slideUp();
          }
          else {
            // do nothing!
          }
        });

      }
      challenges_toggle('h4.available', 'div.content');

      $('#challenges h4.available:last').next('div.content').show();

      // animation for a.jump_scroll
      var contentAnchors = 'a.jump_scroll';
      var navAnchors = '#block-dosomething-campaign-styles-campaign-nav a';
      var allAnchors = navAnchors + ', ' + contentAnchors;

      $(allAnchors).click(function(event){
        $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');
        return false;
      });

      //
      // The next 50 lines of this file hurt my feelings..
      //

      // A quick and dirty (AKA - way too long and redundant script) for report-back select to textarea connection
      jQuery('.webform-component-textarea').css('display','none');

      jQuery('#edit-submitted-choose-a-day-to-tell-us-about-and-upload-your-picture-below').change(function(){

        var select = jQuery(this).val();
        var textarea1 = jQuery('#webform-component-day-1-text');
        var textarea2 = jQuery('#webform-component-day-2-text');
        var textarea3 = jQuery('#webform-component-day-3-text');
        var textarea4 = jQuery('#webform-component-day-4-text');
        var textarea5 = jQuery('#webform-component-day-5-text');
        var textarea6 = jQuery('#webform-component-day-6-text');
        var textarea7 = jQuery('#webform-component-day-7-text');
        var textarea8 = jQuery('#webform-component-day-8-text');
        var textarea9 = jQuery('#webform-component-day-9-text');
        var textarea10 = jQuery('#webform-component-day-10-text');
        var textarea11 = jQuery('#webform-component-day-11-text');

        if(select == 'day_1'){
          textarea1.show();
        }
        else {
          textarea1.hide();
          }

        if(select == 'day_2'){
          textarea2.show();
        }
        else {
          textarea2.hide();
          }

        if(select == 'day_3'){
          textarea3.show();
        }
        else {
          textarea3.hide();
          }

        if(select == 'day_4'){
          textarea4.show();
        }
        else {
          textarea4.hide();
          }

        if(select == 'day_5'){
          textarea5.show();
        }
        else {
          textarea5.hide();
          }

        if(select == 'day_6'){
          textarea6.show();
        }
        else {
          textarea6.hide();
          }

        if(select == 'day_7'){
          textarea7.show();
        }
        else {
          textarea7.hide();
          }

        if(select == 'day_8'){
          textarea8.show();
        }
        else {
          textarea8.hide();
          }

        if(select == 'day_9'){
          textarea9.show();
        }
        else {
          textarea9.hide();
          }

        if(select == 'day_10'){
          textarea10.show();
        }
        else {
          textarea10.hide();
          }

        if(select == 'day_11'){
          textarea11.show();
        }
        else {
          textarea11.hide();
          }

      });

      // #header section Facebook fun
      var fb_share_img = 'http://www.dosomething.org/files/campaigns/hunt13/Campaigns_Landing-15.png';
      var fb_title = 'The Hunt';
      var fb_header_caption = '';

      Drupal.behaviors.fb.feed({
        'feed_picture': fb_share_img,
        'feed_title': fb_title,
        'feed_caption': fb_header_caption,
        'feed_description': 'Adults think that teens are lazy and apathetic. Join The Hunt and show them and the world all of the amazing stuff you do in your community every day.',
        'feed_selector': '.header-facebook-share',
      }, function(response){
        window.location.href = '/hunt';
      });

      // REPORT BACK FUN
      $('fieldset.completed legend').each(function(){
        $(this).append('<b>✓</b>')
      });

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
