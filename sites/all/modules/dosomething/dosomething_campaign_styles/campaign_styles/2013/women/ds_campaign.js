(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join the campaign!',
      };

      $('.jump-scroll').click( function(e){
        var hash = $(this).attr('href').split('#')[1];
        $('html,body').animate({scrollTop: $('#' + hash).offset().top}, 'slow');
        e.preventDefault();
      });

      // dynamically set width css property on elements
      set_width = function(parent, child, width) {

        $(parent).each(function() {
          var $this = $(this);
          var child_width = $this.find(child).width() * width;
          $this.css('width', child_width);
        });
      };

      // Dynamically set width of the call to action buttons
      //set_width('a.btn', 'span', 1.3);

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

      // Restyles #headline section depending on campaign model
      // if( $('#sms').length ) {
      //   $('#headline .headline-callout').addClass('alt');
      //   $('#headline').css('margin','1.5em 0 0 0');
      //   $('#sms').css('margin-top','-3em');
      //   $('#call-to-action').remove();
      // }
      // else {
      //   $('#headline').css({
      //     'background' : 'none',
      //     'border' : 'none'
      //     });
      // }

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
