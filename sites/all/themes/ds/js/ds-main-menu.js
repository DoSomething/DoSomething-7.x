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
        }, 8000);
      });
    }
  }
  Drupal.behaviors.dsDropdownMenu = {
    attach: function (context, settings) {
      var levelOne = $("#causes-menu-dropdown li.causes-menu-dropdown-level-1");
      var levelTwo = $("#causes-menu-dropdown li.causes-menu-dropdown-level-2");
      
      // TODO: Define this element differently
      $("#secondary-menu-menu-78489 .menu-77381").hover(function() {
        $(this).addClass('causes-hovering');
        levelOne.show();
      },
      function() {
        t = setTimeout(function() {
          $(this).removeClass('causes-hovering');
          levelOne.hide();
        }, 8000);
      }); 

      levelOne.hover(function() {
        levelOne.show();
        $(this).find("li.causes-menu-dropdown-level-2").show();
      },
      function() {
        $(this).find("li.causes-menu-dropdown-level-2").hide();
      });
    }
  }
})(jQuery);
