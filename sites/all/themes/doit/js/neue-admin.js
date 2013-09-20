(function ($) {

Drupal.behaviors.admin_toggle = {
  attach: function (context, settings) {

    // ------------------- //
    // HIDE ADMIN FEATURES //
    // ------------------- //

    var admin_toggle = function() {
      var $tabs = $('.tabs');

      // Add "admin toggle" link to "tabs" list
      admin_toggle = '<li class="admin-toggle-wrapper"><a href="#" id="admin-toggle">show admin</a></li>';
      $tabs.prepend(admin_toggle);

      // Toggle the visibility of the admin menu
      $('#admin-toggle').click(function() {
        var $this = $(this);
        $('#admin-menu').toggle();
        $this.html($this.html() === 'show admin' ? 'hide admin' : 'show admin');
        return false;
      });
    }
    admin_toggle();

  }
};
}(jQuery));
