/**
 * Hide or show Member dashboard items.
 */

(function ($) {
  Drupal.behaviors.doSomethingMemberItems = {
    attach: function(context, settings) {

      $("#block-dosomething-login-become-member ul.my-somethings").hide();
      $("#block-dosomething-login-become-member ul.notifications").hide();

      $("#block-dosomething-login-become-member h2.my-somethings").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $("#block-dosomething-login-become-member ul.my-somethings").hide('400');
        }
        else {
          $(this).addClass('active');
          $("#block-dosomething-login-become-member ul.my-somethings").show('400');
        }
      });

      $("#block-dosomething-login-become-member h2.notifications").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $("#block-dosomething-login-become-member ul.notifications").hide('400');
        }
        else {
          $(this).addClass('active');
          $("#block-dosomething-login-become-member ul.notifications").show('400');
        }
      });
    }
  }
}(jQuery));

