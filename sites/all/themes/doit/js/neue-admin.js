(function ($) {

Drupal.behaviors.admin_toggle = {
  attach: function (context, settings) {

    // ------------------- //
    // HIDE ADMIN FEATURES //
    // ------------------- //

    var admin_toggle = function() {
      var $tabs = $('.tabs');
      $tabs.children('li').wrapAll('<li><ul></ul></li>');
      $tabs.show();

      // Add "hide" buttons to DOM
      tabs_toggle = '<a href="#" id="tabs-toggle">show options</a>';
      $tabs.children('li').prepend(tabs_toggle);

      // Add "admin toggle" link to "tabs" list
      admin_toggle = '<li id="admin-toggle">show admin</li>';
      $tabs.children('ul').prepend(admin_toggle);

      // Toggle the visibility of the admin menu
      $('#admin-toggle').click(function() {
        var $this = $(this);
        $('#admin-menu').toggle();
        $this.html($this.html() === 'show admin' ? 'hide admin' : 'show admin');
        return false;
      });

      // Toggle the visibility of the admin tabs
      $('#tabs-toggle').hover(function() {
        $tabs.toggle();
      });
    }
    admin_toggle();

  }
};
}(jQuery));
