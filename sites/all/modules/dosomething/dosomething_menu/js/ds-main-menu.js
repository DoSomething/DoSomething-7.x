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
      $('.issues-dropdown > .item-list > h3 > a')
        .addClass('issues-dropdown-trigger').prepend('<span class="arrows"> &raquo; </span>')
        .wrap('<li class="issues-dropover"></li>')
        .after($('#issues-menu-dropdown')).end()
        .find('#issues-menu-dropdown').addClass('issues-dropdown-menu').end();
      $(".causes-dropdown-trigger").parent().removeClass("last").after($('.issues-dropover'));
      $(".issues-dropdown").remove();

      // Show and hide basic dropdowns on secondary menu.
      $(".secondary a.secondary-menu-item").hover(
        function() {
          $(this).next('ul').show().removeClass('hidden').hover(
            function() {
              $(this).show();
            },
            function() {
              $(this).hide();
            }
          );
        },
        function() {
          $(this).next('ul').hide();
        }
      );


      // Show and hide secondary menu.
      $("nav[role=navigation]").hoverIntent({
        interval: 100,
        timeout: 1000,
        over: function() {
          $causesMenu.hide();

          $("#main-menu li").hoverIntent({
            interval: 50,
            over: function() {
              var classes = $(this).attr("class").split(" ");
              var menuClass = classes[0];

              $("#main-menu li").removeClass('active-hover');
              $(this).addClass('active-hover');

              // Hide all but related secondary menu
              $secondaryMenu.addClass("hidden");
              $("#secondary-menu-" + menuClass).removeClass("hidden");
              $causesMenu.hide();
            },
            out: function() {}
          });
        },
        out: function() {
          $("#main-menu li").removeClass('active-hover');
          $secondaryMenu.addClass("hidden");
          $("nav .secondary .active").removeClass("hidden");
          }
        });

      // Show and hide causes and issues dropdowns
      $(".causes-dropdown-trigger").mouseover(function() {
        $causesMenu.show().mouseleave(function() {$(this).hide();});
      });

      $(".issues-dropdown-trigger").mouseover(function() {
        $('.issues-dropdown-menu').show().mouseleave(function() {$(this).hide();});
      });
    }
  }
})(jQuery);
