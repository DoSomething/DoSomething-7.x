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
      $("nav[role=navigation]").hoverIntent({
        interval: 100,
        timeout: 1000,
        over: function() {
                var classes = $("#main-menu li:hover").attr("class").split(" ");
                var menuClass = classes[0];
                secondaryMenu.addClass("hidden");
                $("#secondary-menu-" + menuClass).removeClass("hidden");
                causesMenu.hide();

                $("#main-menu li").hoverIntent({
                  interval: 50,
                  over: function() {
                    var classes = $(this).attr("class").split(" ");
                    var menuClass = classes[0];

                    // Hide all but related secondary menu
                    secondaryMenu.addClass("hidden");
                    $("#secondary-menu-" + menuClass).removeClass("hidden");
                    causesMenu.hide();
                  }
                });
              },
        out:  function() {
                console.log('out');
                secondaryMenu.addClass("hidden");
                $("nav .secondary .active").removeClass("hidden");
              },
        });

      // Show and hide level 1 in the all-causes dropdown.
      $(".causes-dropdown-trigger").mouseover(function() {
        causesMenu.show();
        // levelOne.show();
        causesMenu.mouseout(
          function() {
            $(this).hide();
          }
        );
      });

      // causesMenu.hover(
      //   function() {
      //     console.log($(this));
      //   },
      //   function() {
      //     $(this).hide();
      //   }
      // );

      // $(".causes-dropdown-trigger").hover(function() {
      //   causesMenu.show();
      //   levelOne.show();
      // },
      // function() {
      //   causesTimeout = setTimeout(function() {
      //     causesMenu.hide();
      //   }, 5000);
      // });

      // // Show and hide all-causes dropdown.
      // causesMenu.hoverIntent({
      //   timeout: 1000,
      //   over: function() {
      //     causesMenu.show();
      //     // Clear the timeout from the trigger,
      //     // because we are now hovering.
      //     if (causesTimeout) {
      //       clearTimeout(causesTimeout);
      //     }
      //     levelTwo.show();
      //   },
      //   out: function() {
      //     causesMenu.hide();
      //     levelTwo.hide();
      //   }
      // });

    }
  }
})(jQuery);
