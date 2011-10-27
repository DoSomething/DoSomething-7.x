(function ($) {
  Drupal.behaviors.dsMainMenu = {
    attach: function (context, settings) {
      var timeout = false;
      var causesTimeout = false;
      var levelOne = $("#causes-menu-dropdown li.causes-menu-dropdown-level-1");
      var levelTwo = $("#causes-menu-dropdown li.causes-menu-dropdown-level-2");
      var secondaryMenu = $(".secondary ul");
      var secondaryMenuActive = $(".secondary ul.active");
      var causes = $("#causes-menu-dropdown li");
      var timeLength = 5000;

      // Show and hide secondary menu.
      $("#main-menu li").hover(function() {
        // Clear the timeout in case user was hovering
        //  over another menu item.
        if (timeout) {
          clearTimeout(timeout);
        }

        var classes = $(this).attr('class').split(' ');
        var menuClass = classes[0];

        // Hide all but related secondary menu
        secondaryMenu.addClass('hidden');
        $("#secondary-menu-" + menuClass).removeClass('hidden');
        causes.hide();
      },
      function() {
        // Nothing to do on hover out.
      });

      // Show and hide level 1 in the all-causes dropdown.
      $(".causes-dropdown-trigger").hover(function() {
        levelOne.show();
      },
      function() {
        causesTimeout = setTimeout(function() {
          levelOne.hide();
        }, timeLength + 1000);
      }); 

      // Show and hide level 2 items in the all-causes dropdown.
      levelOne.hover(function() {
        levelOne.show();
        $(this).find("li.causes-menu-dropdown-level-2").show();
      },
      function() {
        $(this).find("li.causes-menu-dropdown-level-2").hide();
      });

      // Hide the causes menu on click.
      $("body").click(function() {
        causes.hide();
      });
    }
  }
})(jQuery);
