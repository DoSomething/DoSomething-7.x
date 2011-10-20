/**
 * Hide or show Facebook and Twitter activity blocks.
 */

(function ($) {
  Drupal.behaviors.hideActivityblocks = {
    attach: function(context, settings) {
      // initially hide twitter
      $("#block-dosomething-blocks-dosomething-twitter-stream .content, .pane-dosomething-blocks-dosomething-twitter-stream .pane-content").hide();
      // set cursors to hand
      $("#block-dosomething-blocks-dosomething-twitter-stream h2, .pane-dosomething-blocks-dosomething-twitter-stream h2, #block-dosomething-blocks-dosomething-facebook-activity h2, .pane-dosomething-blocks-dosomething-facebook-activity h2").css('cursor', 'pointer').css('cursor', 'hand');
      // set facebook to 'active'
      $("#block-dosomething-blocks-dosomething-facebook-activity h2, .pane-dosomething-blocks-dosomething-facebook-activity h2").addClass('active');
      // click twitter
      $("#block-dosomething-blocks-dosomething-twitter-stream h2, .pane-dosomething-blocks-dosomething-twitter-stream h2").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          // hide twitter
          $("#block-dosomething-blocks-dosomething-twitter-stream .content, .pane-dosomething-blocks-dosomething-twitter-stream .pane-content").slideUp('400');
        }
        else {
          $(this).addClass('active');
          // show twitter
          $("#block-dosomething-blocks-dosomething-twitter-stream .content, .pane-dosomething-blocks-dosomething-twitter-stream .pane-content").slideDown('400');
          // hide facebook
          $("#block-dosomething-blocks-dosomething-facebook-activity .content, .pane-dosomething-blocks-dosomething-facebook-activity .pane-content").slideUp('400');
        }
      });

      $("#block-dosomething-blocks-dosomething-facebook-activity h2, .pane-dosomething-blocks-dosomething-facebook-activity h2").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          // hide facebook
          $("#block-dosomething-blocks-dosomething-facebook-activity .content, .pane-dosomething-blocks-dosomething-facebook-activity .pane-content").slideUp('400');
        }
        else {
          $(this).addClass('active');
          // show facebook
          $("#block-dosomething-blocks-dosomething-facebook-activity .content, .pane-dosomething-blocks-dosomething-facebook-activity .pane-content").slideDown('400');
          // hide twitter
          $("#block-dosomething-blocks-dosomething-twitter-stream .content, .pane-dosomething-blocks-dosomething-twitter-stream .pane-content").slideUp('400');
        }
      });

    }
  }
}(jQuery));

