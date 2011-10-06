(function($) {

Drupal.dosomethingSlider = Drupal.dosomethingSlider || {};
// This is to make sure $.mousemove() doesn't try to restart the animation over and over.
Drupal.dosomethingSlider.toggle = true;
// Which percentage of the slider will trigger animation.
Drupal.dosomethingSlider.percentage = 0.2;
// Speed of the animation.
Drupal.dosomethingSlider.speed = 800;

Drupal.behaviors.dosomethingSlider = {
  attach: function(context, settings) {
    $('.dosomething-slider').each(function (index, slider) {
      $('.dosomething-slider-nav', $(slider))
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
            if (!Drupal.dosomethingSlider.toggle) {
              return;
            }

            y_pos = e.pageY - nav_offsetY;
            if (y_pos >= 0 && y_pos <= (slider_nav_height * Drupal.dosomethingSlider.percentage)) {
              Drupal.dosomethingSlider.animateThis($slider_nav_items, 0);
            }
            else if (y_pos >= (slider_nav_height * (1 - Drupal.dosomethingSlider.percentage)) && y_pos <= slider_nav_height) {
              scroll_to = height_diff + $slider_nav_items.eq(0).position().top;
              Drupal.dosomethingSlider.animateThis($slider_nav_items, "-="+scroll_to);
            }
            else {
              $slider_nav_items.stop(true, false);
              Drupal.dosomethingSlider.toggle = true;
            }
          });
        }, function() {
          $slider_nav_items.stop(true, false);
          Drupal.dosomethingSlider.toggle = true;
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

Drupal.dosomethingSlider.animateThis = function($elements, final_pos, speed) {
  speed = speed || Drupal.dosomethingSlider.speed;
  Drupal.dosomethingSlider.toggle = false; // sets "global" toggle

  $elements.animate({
    top:final_pos
  }, speed, function() {
    Drupal.dosomethingSlider.toggle = true; // resets "global" toggle
  });

  return false;
}

}(jQuery));
