/**
 * Hide or show Facebook and Twitter activity blocks.
 */ 

(function ($) {
  Drupal.behaviors.hideActivityblocks = {
    attach: function(context, settings) {
      
      $("#block-dosomething-blocks-dosomething-twitter-stream .content").hide(); 
      $("#block-dosomething-blocks-dosomething-facebook-activity .content").hide(); 

      $("#block-dosomething-blocks-dosomething-twitter-stream h2").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $("#block-dosomething-blocks-dosomething-twitter-stream .content").hide('400'); 
        }
        else {
          $(this).addClass('active');
          $("#block-dosomething-blocks-dosomething-twitter-stream .content").show('400'); 
        }
      });

      $("#block-dosomething-blocks-dosomething-facebook-activity h2").click(function() {
        if ($(this).hasClass('active')) {
          $(this).removeClass('active');
          $("#block-dosomething-blocks-dosomething-facebook-activity .content").hide('400'); 
        }
        else {
          $(this).addClass('active');
          $("#block-dosomething-blocks-dosomething-facebook-activity .content").show('400'); 
        }
      });
    }
  }
}(jQuery));

