(function ($) {

Drupal.behaviors.admin_toggle = {
  attach: function (context, settings) {

    // ------------------- //
    // HIDE ADMIN FEATURES //
    // ------------------- //

    var admin_toggle = function() {
      var $tabs = $('.tabs');

      // Add "admin toggle" link to "tabs" list
      admin_toggle = '<li id="toggle-button-wrapper"><a href="#" id="toggle-button"><span id="hide" class="active state">show</span><span id="show" class="state">hide</span></a></li>';
      $tabs.prepend(admin_toggle);

      // Toggle the visibility of the admin menu
      $('#toggle-button').click(function() {
        var $this = $(this);
        $('#admin-menu').toggle();
        $('.state', '#toggle-button-wrapper').toggleClass('active');
        //$this.html($this.html() === 'show admin' ? 'hide admin' : 'show admin');
        return false;
      });
    }
    admin_toggle();

  }
};
}(jQuery));
