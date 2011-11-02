(function ($) {
  Drupal.behaviors.dsMainMenu = {
    attach: function (context, settings) {
      var causesTimeout = false;
      var $causesMenu = $("#causes-menu-dropdown");
      var $causesMenuParent = $(".causes-dropdown");
      var $secondaryMenu = $(".secondary ul");
      var $secondaryMenuActive = $(".secondary ul.active");
      $(".causes-dropdown-trigger").append($causesMenuParent);

      // Shape the issues menu into something that fits into the secondary menu
      $issuesMenu = $("#issues-menu-dropdown > li").removeClass('first').addClass('issues-dropover');
      $issuesMenu.find('div.item-list').addClass('issues-dropdown-menu');
      $issuesMenu.find('> a').addClass('issues-dropdown-trigger').prepend('<span class="arrows"> &raquo; </span>')
      $(".causes-dropdown-trigger").parent().removeClass("last").after($issuesMenu);
      $(".issues-dropdown").remove();

      // Show and hide secondary menu.
      $("nav[role=navigation]").hoverIntent({
        interval: 100,
        timeout: 1000,
        over: function() {
<<<<<<< HEAD
          var classes = $("#main-menu li:hover").attr("class").split(" ");
          var menuClass = classes[0];
          $secondaryMenu.addClass("hidden");
          $("#secondary-menu-" + menuClass).removeClass("hidden");
          $causesMenu.hide();

          $("#main-menu li").hoverIntent({
            interval: 50,
            over: function() {
              var classes = $(this).attr("class").split(" ");
              var menuClass = classes[0];

              // Hide all but related secondary menu
              $secondaryMenu.addClass("hidden");
              $("#secondary-menu-" + menuClass).removeClass("hidden");
              $causesMenu.hide();
            }
          });
        },
        out: function() {
          console.log('out');
          $secondaryMenu.addClass("hidden");
          $("nav .secondary .active").removeClass("hidden");
          },
=======
                var classes = $("#main-menu li:hover").attr("class").split(" ");
                var menuClass = classes[0];
                $secondaryMenu.addClass("hidden");
                $("#secondary-menu-" + menuClass).removeClass("hidden");
                $causesMenu.hide();

                $("#main-menu li").hoverIntent({
                  interval: 50,
                  over: function() {
                    var classes = $(this).attr("class").split(" ");
                    var menuClass = classes[0];

                    // Hide all but related secondary menu
                    $secondaryMenu.addClass("hidden");
                    $("#secondary-menu-" + menuClass).removeClass("hidden");
                    $causesMenu.hide();
                  }
                });
              },
        out:  function() {
                console.log('out');
                $secondaryMenu.addClass("hidden");
                $("nav .secondary .active").removeClass("hidden");
              },
>>>>>>> clean up variables #172
        });

      // Show and hide causes and issues dropdowns
      $(".causes-dropdown-trigger").mouseover(function() {
<<<<<<< HEAD
        $causesMenu.show().mouseleave(function() {$(this).hide();});
      });

      $(".issues-dropdown-trigger").mouseover(function() {
        $('.issues-dropdown-menu').show().mouseleave(function() {$(this).hide();});
=======
        $causesMenu.show();
        $causesMenu.mouseleave(
          function() {
            $(this).hide();
          }
        );
      });

      $(".issues-dropdown-trigger").mouseover(function() {
        $issuesDropMenu.show();
        $issuesDropMenu.mouseleave(
          function() {
            $(this).hide();
          }
        );
>>>>>>> clean up variables #172
      });

    }
  }
})(jQuery);
