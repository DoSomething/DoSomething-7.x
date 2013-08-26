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

      // Restyles #headline section depending on campaign model
      if( $('#sms').length ) {
        $('#headline .headline-callout').addClass('alt');
        $('#headline').css('margin','1.5em 0 0 0');
        $('#sms').css('margin-top','-3em');
        $('#call-to-action').remove();
      }
      else {
        $('#headline').css({
          'background' : 'none',
          'border' : 'none'
          });
      }

    // Facebook Share
    var fb_share_img = '//www.dosomething.org/files/campaigns/survivors/CellPhone_Assets_facebook_content.png';
    var fb_title = 'Birthday Mail';
    var fb_header_caption = '';

    Drupal.behaviors.fb.feed({
      'feed_picture': fb_share_img,
      'feed_title': fb_title,
      'feed_caption': fb_header_caption,
      'feed_description': '500 million unused “junk phones” sit in peoples’ homes across the US. Turn yours into life-saving funding for domestic violence survivors.',
      'feed_selector': '.header-facebook-share',
    }, function(response){
      window.location.href = '/survivors#header';
    });

    // ------------------
    // GET LABEL DROPDOWN
    // ------------------

    var get_label = function() {
      $('#getlabel').click(function() {
        $(this).css({
            'background':'#ccc',
            'cursor':'default'
          });
        $('#section-label').slideDown(500);
        return false;
      })
    }
    get_label();

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
