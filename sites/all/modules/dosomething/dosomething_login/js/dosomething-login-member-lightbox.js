/**
 * Why become a member dialog popup.
 */

(function ($) {
  Drupal.behaviors.dosomethingLoginMemberLightbox = {
    attach: function(context, settings) {
      $('#member-dialog').hide();
      $("#block-dosomething-login-become-member .why-member a").click(function() {
        event.preventDefault();
        $('#member-dialog').dialog({modal:true, width:617, height:392});
      });
    }
  }
}(jQuery));