(function($) {

Drupal.rotoslider = Drupal.rotoslider || {};
// This is to make sure $.mousemove() doesn't try to restart the animation over and over.
Drupal.rotoslider.toggle = true;
// Which percentage of the slider will trigger animation.
Drupal.rotoslider.percentage = 0.2;
// Speed of the animation.
Drupal.rotoslider.speed = 800;

Drupal.behaviors.rotoslider = {
  attach: function(context, settings) {
    $('.rotoslider').each(function (index, slider) {
      $('.rotoslider-nav', $(slider))
        .hover(function() {
          nav_offsetY = $(this).offset().top;

          nav_item_height = 0;
          $slider_nav_items = $('li', $(this)).each(function() {
            nav_item_height += $(this).outerHeight(true);
          });

          slider_nav_height = $(this).height();

          height_diff = nav_item_height - slider_nav_height;
          if (height_diff <= 0) {
            return;
          }

          $(this).mousemove(function(e) {
            if (!Drupal.rotoslider.toggle) {
              return;
            }

            y_pos = e.pageY - nav_offsetY;
            if (y_pos >= 0 && y_pos <= (slider_nav_height * Drupal.rotoslider.percentage)) {
              Drupal.rotoslider.animateThis($slider_nav_items, 0);
            }
            else if (y_pos >= (slider_nav_height * (1 - Drupal.rotoslider.percentage)) && y_pos <= slider_nav_height) {
              scroll_to = height_diff + $slider_nav_items.eq(0).position().top;
              Drupal.rotoslider.animateThis($slider_nav_items, "-="+scroll_to);
            }
            else {
              $slider_nav_items.stop(true, false);
              Drupal.rotoslider.toggle = true;
            }
          });
        }, function() {
          $slider_nav_items.stop(true, false);
          Drupal.rotoslider.toggle = true;
        })
        .find('li a')
          .click(function() {
            $(this)
              .toggleClass('active')
              .parent().siblings().children().removeClass('active');
            $(document.querySelectorAll('[data-key=' + $(this).data('key') + ']')).not($(this)).each(function() {
              $(this)
                .toggleClass('active')
                .siblings().removeClass('active');
            });
            return false;
          })
        .end();
    });
  }
}

Drupal.rotoslider.animateThis = function($elements, final_pos, speed) {
  speed = speed || Drupal.rotoslider.speed;
  Drupal.rotoslider.toggle = false; // sets "global" toggle

  $elements.animate({
    top:final_pos
  }, speed, function() {
    Drupal.rotoslider.toggle = true; // resets "global" toggle
  });

  return false;
}

}(jQuery));
