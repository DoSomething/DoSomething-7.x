var $window = jQuery(window);
var $nav = jQuery('.region-sidebar-first');
var scrollLimit = 180;

$window.scroll(function () {
  if ($window.scrollTop() > 180) {
    $nav
      .css('position', 'fixed')
      .css('top', '10px')
      .css('margin-top', 0);
  }
  else {
    $nav
      .css('position', 'relative')
      .css('top', '0')
      .css('margin-top', '104px');
  }
});
