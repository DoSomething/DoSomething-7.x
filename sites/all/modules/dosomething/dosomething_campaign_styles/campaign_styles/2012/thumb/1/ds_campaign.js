(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      var contactForm = $('#contact_form');
      $('#accent_ribbon').append(contactForm);
      
  var $window = jQuery(window);
  var $nav = jQuery('.webform');
  var $hole = jQuery('#cask');
  var $olive = jQuery('.webform .divider');
  var $pit = jQuery('.webform .divider span');
  var scrollLimitTop = 710;
  var scrollLimitBot = 3346;

//  $window.scroll(function () {
//    var st = $window.scrollTop();
//    if (st > scrollLimitTop && st < scrollLimitBot) {
//      $nav
//        .css('position','fixed')
//        .css('top','0px')
//        .css('margin','0 0 0 0')
//        .css('background','#231F20')
//        .css('width','727px')
//        .css('z-index','3')
//        .css('padding-top','15px');
//      $olive
//        .css('border-top','2px solid white');
//      $hole
//        .css('padding-top','202px');
//    }
//    else if (st >= scrollLimitBot) {
//      $nav
//        .css('position', 'absolute')
//        .css('top', 'auto')
//        .css('bottom', '5px')
//        .css('padding-top','0px');
//      $pit
//        .css('top','-15px');
//      $hole
//        .css('padding-top','0');
//    }
//    else {
//      $nav
//        .css('position', 'static')
//        .css('padding-top','0px');
//      $hole
//        .css('padding-top','0');
//    }
//  });

 
    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
