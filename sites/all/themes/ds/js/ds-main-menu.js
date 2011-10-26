(function ($) {
  Drupal.behaviors.dsMainMenu = {
    attach: function (context, settings) {
      var timeout = false;
      $("#main-menu li").hover(function() {
        // Clear the timeout in case user was hovering
        //  over another menu item.
        if (timeout) {
          clearTimeout(timeout);
        }
        var classes = $(this).attr('class').split(' ');
        var tclass = classes[0];

        // Hide all but related secondary menu
        $(".secondary ul").addClass('hidden');
        $("#secondary-menu-" + tclass).removeClass('hidden');
      },
      function() {
        timeout = setTimeout(function() {
          // Hide everything except active secondary menu.
          $(".secondary ul").addClass('hidden');
          $(".secondary ul.active").removeClass('hidden');
        }, 5000);
      });
    }
  }
})(jQuery);
