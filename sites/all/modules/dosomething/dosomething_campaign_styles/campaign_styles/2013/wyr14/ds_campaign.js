(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join the campaign!',
      };

      // Animate scrolling to fragment identifiers
      $('.jump-scroll').click( function(e){
        var hash = $(this).attr('href').split('#')[1];
        $('html,body').animate({scrollTop: $('#' + hash).offset().top}, 'slow');
        e.preventDefault();
      });

      // #faq drop down animations
      faq_toggle = function(question, response) {

        var $question = $('#faq ' + question);
        var $question_active = $('#faq ' + question + '.active');

        $question.next(response).hide();
        $question_active.next(response).show();

        $question.click(function() {
          $this = $(this);
          if( !$this.hasClass('active') ) {
            $this.addClass('active');
            $this.siblings('h3').removeClass('active');
            $this.next(response).slideToggle();
            $this.siblings().next(response).slideUp();
          }
          else {
            // do nothing!
          }
        });

      }
      faq_toggle('h3', 'div');

      // Switch "active" class on sibling elements
      var activeSwitch = function(target, element) {

        $(target).click(function() {
          var $this = $(this);
          if ($this.not('.active')) {
            $this.addClass('active');
            $this.siblings(element).removeClass('active');
          }
        });

      }

      // ----------------
      // FACEBOOK SHARING
      // ----------------

      var fb_share_img = 'www.dosomething.org/files/campaigns/bullytext/bullytext_header.jpg';
      var fb_title = 'Bully Text';
      var fb_header_caption = 'Will you and your friends stand up?';

      Drupal.behaviors.fb.feed({
        'feed_picture': fb_share_img,
        'feed_title': fb_title,
        'feed_caption': fb_header_caption,
        'feed_description': 'Everyone has the power to stop bullying. Join @do something for The Bully Text and find out how you and your friends can stand up to bullying',
        'feed_selector': '.header-facebook-share',
      }, function(response){
        window.location.href = '/bullytext#header';
      });

      // ------------------------
      // SMS CONFIRMATION MESSAGE
      // ------------------------

      if (document.location.search.slice(1,8) === 'success') {
        var success_msg = '<div class="success_msg"><h2>Great! We sent The Bully Text to you and your friends.</h2></div>';
        $('#sms').prepend(success_msg);
      }

      // END

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
