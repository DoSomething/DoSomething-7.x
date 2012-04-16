/**
 * Utility dialog popup.
 */

(function ($) {

Drupal.behaviors.letsTalk = {
  attach: function (context, settings) {
    var dialogBox = $('#lets-talk-dialog');
    dialogBox.hide();
    $('#block-dosomething-blocks-dosomething-utility-bar #help-center a, #block-menu-menu-footer ul li.first.expanded ul.menu li.first a').click(function (event) {
      dialogBox.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 436
      });
      // Do not go to actual clicked link.
      event.preventDefault();
    });
  }
};

}(jQuery));
