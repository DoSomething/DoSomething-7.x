(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join the campaign!',
      };

      // Animate scrolling to fragment identifiers
      jump_scroll = function(target) {

        $(target).click(function(event){
          $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');
          return false;
        });

      }
      jump_scroll('a.jump-scroll');

      // dynamically set width css property on elements
      set_width = function(parent, child, width) {

        $(parent).each(function() {
          var $this = $(this);
          var child_width = $this.find(child).width() * width;
          $this.css('width', child_width);
        });
      };

      // Dynamically set width of the call to action buttons
      set_width('a.btn', 'span', 1.3);

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

    // END

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
