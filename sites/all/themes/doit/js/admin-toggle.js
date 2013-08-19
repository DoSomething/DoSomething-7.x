(function ($) {

Drupal.behaviors.admin_toggle = {
  attach: function (context, settings) {

    // ------------------- //
    // HIDE ADMIN FEATURES //
    // ------------------- //

    var admin_toggle = function() {
      // Add "hide" buttons to DOM
      hide_button = '<a id="hide-button" href="#">hide admin</a>';
      $('#page').before(hide_button);

      // Display different sections based on selection
      $('#hide-button').click(function() {
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
