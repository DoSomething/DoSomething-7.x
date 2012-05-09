/**
 * Hide or show Facebook and Twitter activity blocks.
 */

(function ($) {

Drupal.behaviors.hideActivityblocks = {
  attach: function (context, settings) {
    var $skyscraper = $('#block-dosomething-blocks-dosomething-social-skyscraper .content');
    $skyscraper.find('.social-activity-content').hide();
    // set cursors to hand
    $skyscraper.find('h3')
      .css('cursor', 'pointer')
      .css('cursor', 'hand')
      .click(function () {
        var $this = $(this);
        if ($this.hasClass('active')) {
          $this
            .removeClass('active')
            .next('.social-activity-content')
              .slideUp('400');
        }
        else {
          $this
            .addClass('active')
            .next('.social-activity-content')
              .slideDown('400');
          if ($this.hasClass('facebook') && !$this.hasClass('facebook-loaded')) {
            $this
              .addClass('facebook-loaded')
              .next('.social-activity-content')
                .children('.skyscraper-fb-activity')
                  .addClass('fb-activity');
            FB.XFBML.parse();
          }
          // Hide other active content.
          if ($this.siblings().hasClass('active')) {
            $this.siblings('.active')
              .removeClass('active')
              .next('.social-activity-content')
                .slideUp('400');
          };
        }
      });
  }
};

}(jQuery));
