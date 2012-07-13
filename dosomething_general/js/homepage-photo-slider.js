/**
 * Photo slider on home page.
 */

(function ($) {
Drupal.behaviors.featuredNews = {
  attach: function(context) {
    Drupal.settings.dosomething = new Array();
    Drupal.settings.dosomething.photoSliderIndex = 0;

    // Add Classes so JS degrades when JS disabled.
    $(".view-home-slideshow").addClass('photo-slider');
    $(".view-home-slideshow .view-content .views-row").addClass('photo-slider-row');

    $(".view-home-slideshow .view-content .views-row:not(:first)").hide();

    // Keep track of hover state.
    $(".view-home-slideshow").hover(
      function(){$(this).addClass("photo-slider-hover")},
      function(){$(this).removeClass("photo-slider-hover")}
    );

    setTimeout(function() {
      feature_cycle();
    }, 5000);

    // Add the numbered tabs.
    $(".view-home-slideshow").append('<div class="slide-count"></div>');
    var slider_items;
    slider_items = $(".view-home-slideshow .view-content .views-row").length;
    for (i = 1; i <= slider_items; i++) {
      $(".slide-count").prepend('<span>' + i + '</span>');
    }
    $(".view-home-slideshow .slide-count span:last-child").addClass('active');

    // Switch on tab click.
    $(".slide-count span").click(function() {
      $(".view-home-slideshow .view-content .views-row").hide();
      $('.slide-count span').removeClass('active');
      var num;
      num = $(this).html() - 1;
      Drupal.settings.dosomething.photoSliderIndex = num;
      $(".view-home-slideshow .views-row:eq(" + num + ")").show();
      $(this).addClass('active');
    });
  }
}

/**
 * Do a timed cycle.
 */
function feature_cycle() {
  if (!$(".view-home-slideshow").is(".photo-slider-hover")) { // Don't cycle during hover.
    if (!$(".view-home-slideshow .views-row:eq(" + Drupal.settings.dosomething.photoSliderIndex + ")").next().length) {
      var next = 0;
    }
    else {
      var next = Drupal.settings.dosomething.photoSliderIndex + 1;
    }
    $(".view-home-slideshow .views-row:eq(" + Drupal.settings.dosomething.photoSliderIndex + ")").fadeOut(2000);
    $(".view-home-slideshow .views-row:eq(" + next + ")").fadeIn(2000);
    $('.slide-count span').removeClass('active');
    $(".slide-count span:eq(" + ($(".slide-count span").length - (next + 1)) + ")").addClass('active');
    Drupal.settings.dosomething.photoSliderIndex = next;
  }
  // And repeat.
  setTimeout(function() {
    feature_cycle();
  }, 5000);
}

}(jQuery));

