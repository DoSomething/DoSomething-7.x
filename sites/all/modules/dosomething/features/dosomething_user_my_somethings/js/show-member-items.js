/**
 * Hide or show Member dashboard items.
 */

(function ($) {
  Drupal.behaviors.doSomethingMemberItems = {
    attach: function(context, settings) {
      // initially hide my somethings and notifications
      $("#block-dosomething-login-become-member ul.my-somethings").hide();
      $("#block-dosomething-login-become-member ul.notifications").hide();
      // set cursors to hand
      $("#block-dosomething-login-become-member h2.my-somethings, #block-dosomething-login-become-member h2.notifications").css('cursor', 'pointer').css('cursor', 'hand');
      $("#block-dosomething-login-become-member h2.my-somethings").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $("#block-dosomething-login-become-member ul.my-somethings").slideUp('400');
        }
        else {
          $(this).addClass('active');
          $("#block-dosomething-login-become-member ul.my-somethings").slideDown('400');
        }
      });

      $("#block-dosomething-login-become-member h2.notifications").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $("#block-dosomething-login-become-member ul.notifications").slideUp('400');
        }
        else {
          $(this).addClass('active');
          $("#block-dosomething-login-become-member ul.notifications").slideDown('400');
        }
      });
    }
  }
}(jQuery));

