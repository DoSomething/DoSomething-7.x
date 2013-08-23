(function ($) {

Drupal.behaviors.admin_toggle = {
  attach: function (context, settings) {

    // ------------------- //
    // HIDE ADMIN FEATURES //
    // ------------------- //

    var admin_toggle = function() {
      // Add "hide" buttons to DOM
      toggle_button = '<a id="toggle-button" href="#">show admin</a>';
      $('#page').before(toggle_button);

      // Display different sections based on selection
      $('#toggle-button').click(function() {
        var $this = $(this);
        $this.toggleClass('active');
        $('body').toggleClass('active');
        $('#admin-menu').toggle();
        $('div.tabs').toggle();
        $this.html($this.html() === 'show admin' ? 'hide admin' : 'show admin');
        return false;
      });
    }
    admin_toggle();

  }
};
}(jQuery));
