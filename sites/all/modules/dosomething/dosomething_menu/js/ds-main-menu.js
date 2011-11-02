(function ($) {
  Drupal.behaviors.dsMainMenu = {
    attach: function (context, settings) {
      var causesTimeout = false;
      var levelOne = $("#causes-menu-dropdown li.causes-menu-dropdown-level-1");
      var levelTwo = $("#causes-menu-dropdown li.causes-menu-dropdown-level-2");
      var causesMenu = $("#causes-menu-dropdown");
      var causesMenuParent = $(".causes-dropdown");
      var secondaryMenu = $(".secondary ul");
      var secondaryMenuActive = $(".secondary ul.active");
      $(".causes-dropdown-trigger").append(causesMenuParent);

      // Show and hide secondary menu.
      $("#main-menu li").hoverIntent({
        interval: 300,
        over: function() {

          var classes = $(this).attr("class").split(" ");
          var menuClass = classes[0];

          // Hide all but related secondary menu
          secondaryMenu.addClass("hidden");
          $("#secondary-menu-" + menuClass).removeClass("hidden");
          causesMenu.hide();
        }
      });

      // Show and hide level 1 in the all-causes dropdown.
      $(".causes-dropdown-trigger").hover(function() {
        causesMenu.show();
        levelOne.show();
      },
      function() {
        causesTimeout = setTimeout(function() {
          causesMenu.hide();
        }, 5000);
      });

      // Show and hide all-causes dropdown.
      causesMenu.hoverIntent({
        timeout: 1000,
        over: function() {
          causesMenu.show();
          // Clear the timeout from the trigger,
          // because we are now hovering.
          if (causesTimeout) {
            clearTimeout(causesTimeout);
          }
          levelTwo.show();
        },
        out: function() {
          causesMenu.hide();
          levelTwo.hide();
        }
      });
    }
  }
})(jQuery);
