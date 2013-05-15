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
          console.log('merde');
          $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');
          return false;
        });

      }
      jump_scroll('a.jump-scroll');


      // Dynamically set width of the .section-headers
      set_width = function(parent, child) {

        $(parent).each(function() {
          var $this = $(this);
          var child_width = $this.find(child).width() * 1.01;
          $this.css('width', child_width);
        });

      };
      set_width('h2.section-header', 'span');

      // #faq drop down animations
      faq_toggle = function(question, response) {

        $faq_header = $(question);
        faq_response = response;
        $faq_header.next(response).hide();
        $faq_header.next('div.active').show();

        if( !$faq_header.hasClass('active') ) {
          $faq_header.click(function() {
            $this = $(this);
            if( $this.hasClass('active') ) {
              $this.removeClass().next(response).slideUp();
            }
            else {
              $this.addClass('active')
              $this.siblings('h3').removeClass('active')
              $this.next(response).slideToggle()
              $this.siblings().next(response).slideUp();
            }
          });
        }

      }
      faq_toggle('#faq h3', 'div');

      // Restyles #headline section depending on campaign model
      if( $('#sms') ) {
        $('#headline .headline-callout').addClass('alt');
      }
      else {
        $('#headline').css('background','none');
      }

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
