/**
 * Utility dialog popup.
 */

(function ($) {
  Drupal.behaviors.letsTalk = {
    attach: function(context, settings) {
      $('#lets-talk-dialog').hide();
      $("#block-dosomething-blocks-dosomething-utility-bar .utility-items.icons a").click(function() {
        $('#lets-talk-dialog').dialog({modal:true, width:617, height:392});
        // Do not go to actual clicked link.
        return false;
      });
    }
  }
}(jQuery));

