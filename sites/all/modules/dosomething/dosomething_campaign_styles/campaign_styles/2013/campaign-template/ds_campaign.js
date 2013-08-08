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

      // ------------------------ //
      // CAMPAIGN MODEL SWITCHING //
      // ------------------------ //

      // Add "switch" buttons to DOM
      switch_buttons = '<div id="model-switch"><a id="sms-button" href="#">SMS</a><a id="web-button" href="#" class="active">web</a>';
      $('.region.region-utility').prepend(switch_buttons);

      // Display different sections based on type selection
      $('#model-switch a').click(function() {
        var $this = $(this);

        // Only flip styles if the requested model is not currently being shown
        if (!$this.hasClass('active')) {

          if ($this.is('#sms-button')) {
            $('#headline').removeClass('alt');
            $('#sms').show();
            $('#sms-game-example').show();
            $('#gallery').hide();
            $('#call-to-action').hide();
          }
          else if ($this.is('#web-button')) {
            $('#headline').removeClass('alt');
            $('#headline').addClass('alt');
            $('#sms').hide();
            $('#sms-game-example').hide();
            $('#gallery').show();
            $('#call-to-action').show();
          }

        }
        return false;
      });

      // Allow for the passing of "active" class on click
      activeSwitch('#web-button', 'a');
      activeSwitch('#sms-button', 'a');

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
