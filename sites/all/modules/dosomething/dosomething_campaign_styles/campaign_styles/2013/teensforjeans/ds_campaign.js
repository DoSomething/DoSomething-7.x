(function ($) {


  window.suppressEnter = function(e) {
    console.log("MMMM");

    if (e.which === 13) { // if is enter
        console.log("OH NO YOU DUNT");
        e.preventDefault(); // don't submit form
        return false;
    }
  };

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
    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
