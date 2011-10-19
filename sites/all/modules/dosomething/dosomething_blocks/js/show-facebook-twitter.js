/**
 * Hide or show Facebook and Twitter activity blocks.
 */

(function ($) {
  Drupal.behaviors.hideActivityblocks = {
    attach: function(context, settings) {
      $("#block-dosomething-blocks-dosomething-twitter-stream .content, .pane-dosomething-blocks-dosomething-twitter-stream .pane-content").hide();
      $("#block-dosomething-blocks-dosomething-facebook-activity h2, .pane-dosomething-blocks-dosomething-facebook-activity h2").addClass('active')
      $("#block-dosomething-blocks-dosomething-twitter-stream h2, .pane-dosomething-blocks-dosomething-twitter-stream h2").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $("#block-dosomething-blocks-dosomething-twitter-stream .content, .pane-dosomething-blocks-dosomething-twitter-stream .pane-content").slideUp('400');
        }
        else {
          $(this).addClass('active');
          $("#block-dosomething-blocks-dosomething-twitter-stream .content, .pane-dosomething-blocks-dosomething-twitter-stream .pane-content").slideDown('400');
        }
      });
      $("#block-dosomething-blocks-dosomething-facebook-activity h2, .pane-dosomething-blocks-dosomething-facebook-activity h2").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $("#block-dosomething-blocks-dosomething-facebook-activity .content, .pane-dosomething-blocks-dosomething-facebook-activity .pane-content").slideUp('400');
        }
        else {
          $(this).addClass('active');
          $("#block-dosomething-blocks-dosomething-facebook-activity .content, .pane-dosomething-blocks-dosomething-facebook-activity .pane-content").slideDown('400');
        }
      });
    }
  }
}(jQuery));

