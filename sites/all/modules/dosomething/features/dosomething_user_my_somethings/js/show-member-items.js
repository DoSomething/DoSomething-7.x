/**
 * Hide or show Member dashboard items.
 */

(function ($) {
  Drupal.behaviors.doSomethingMemberItems = {
    attach: function(context, settings) {
      // initially hide my somethings and notifications
      $("#block-dosomething-login-become-member ul.doing-it").hide();
      $("#block-dosomething-login-become-member ul.done-it").hide();
      $("#block-dosomething-login-become-member ul.my-clubs").hide();
      // set cursors to hand
      $("#block-dosomething-login-become-member h3.doing-it, #block-dosomething-login-become-member h3.done-it, #block-dosomething-login-become-member h3.my-clubs").css('cursor', 'pointer').css('cursor', 'hand');
      $("#block-dosomething-login-become-member h3.doing-it").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $("#block-dosomething-login-become-member ul.doing-it").slideUp('400');
        }
        else {
          $(this).addClass('active');
          $("#block-dosomething-login-become-member ul.doing-it").slideDown('400');
        }
      });

      $("#block-dosomething-login-become-member h3.done-it").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $("#block-dosomething-login-become-member ul.done-it").slideUp('400');
        }
        else {
          $(this).addClass('active');
          $("#block-dosomething-login-become-member ul.done-it").slideDown('400');
        }
      });

      $("#block-dosomething-login-become-member h3.my-clubs").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $("#block-dosomething-login-become-member ul.my-clubs").slideUp('400');
        }
        else {
          $(this).addClass('active');
          $("#block-dosomething-login-become-member ul.my-clubs").slideDown('400');
        }
      });
    }
  }
}(jQuery));
