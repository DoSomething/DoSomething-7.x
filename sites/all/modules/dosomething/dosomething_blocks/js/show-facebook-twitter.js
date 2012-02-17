/**
 * Hide or show Facebook and Twitter activity blocks.
 */

(function ($) {
  Drupal.behaviors.hideActivityblocks = {
    attach: function(context, settings) {
      $("#block-dosomething-blocks-dosomething-social-skyscraper .content .social-activity-content").hide();
      // set cursors to hand
      $("#block-dosomething-blocks-dosomething-social-skyscraper .content h3").css('cursor', 'pointer').css('cursor', 'hand');
      $("#block-dosomething-blocks-dosomething-social-skyscraper .content h3").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $(this).next(".social-activity-content").slideUp('400');

        }
        else {
          $(this).addClass('active');
          $(this).next(".social-activity-content").slideDown('400');
          // Hide other active content.
          if ($(this).siblings().hasClass('active')) {
            $(this).siblings(".active").next(".social-activity-content").slideUp('400');
            $(this).siblings(".active").removeClass('active');
          };
        }
      });
    }
  }
}(jQuery));

