/**
 * Utility dialog popup.
 */

(function ($) {
  Drupal.behaviors.letsTalk = {
    attach: function(context, settings) {
      var dialogBox = $('#lets-talk-dialog');
      dialogBox.hide();
      $("#block-dosomething-blocks-dosomething-utility-bar .utility-items.icons a, #block-menu-menu-footer ul li.expanded ul.menu li.talk-to-us a").click(function(event) {
        dialogBox.dialog({modal:true, width:617, height:392});
        // Do not go to actual clicked link.
        event.preventDefault();
      });
    }
  }
}(jQuery));
