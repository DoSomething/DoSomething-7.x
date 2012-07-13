var url_base = 'http://www.dosomething.org/sites/all/modules/dosomething/dosomething_campaign_styles/campaign_styles/2012/thumb/new/';
//Main content
jQuery.post(url_base + 'content.php', function (data) {
  jQuery('div[role="main"]').html(data);
});

// sidebar
jQuery.post(url_base + 'sidebar.php', function (data) {
  jQuery('.region-sidebar-first').html(data);
});


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
