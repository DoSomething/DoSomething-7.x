/**
 * Photo slider on project pages.
 */
 
(function ($) {
Drupal.behaviors.featuredNews = {
  attach: function(context) {
    Drupal.settings.dosomething = new Array();
    Drupal.settings.dosomething.photoSliderIndex = 0;

    $(".view-project-photo-slider .view-content .views-row:not(:first-child)").hide(); 
  
    // Keep track of hover state.
    $(".view-project-photo-slider").hover(
      function(){$(this).addClass("photo-slider-hover")},
      function(){$(this).removeClass("photo-slider-hover")}
    );
    // Cycle.
    setTimeout(function() {
      feature_cycle();
    }, 10000);

    // Add the numbered tabs.
    $(".view-project-photo-slider").append('<div class="slide-count"></div>');
    var slider_items;
    slider_items = $(".view-project-photo-slider .view-content .views-row").length;
    for (i = 1; i <= slider_items; i++) {
      $(".slide-count").prepend('<span>' + i + '</span>');
    }  
    $(".view-project-photo-slider .slide-count span:last-child").addClass('active');
  
    // Switch on tab click.
    $(".slide-count span").click(function() {
      $(".view-project-photo-slider .view-content .views-row").hide();      
      $('.slide-count span').removeClass('active');
      var num;
      num = $(this).html() - 1;
      Drupal.settings.dosomething.photoSliderIndex = num;
      $(".view-project-photo-slider .views-row:eq(" + num + ")").show(); 
      $(this).addClass('active');
    });
  }
}

/**
 * Do a timed cycle.
 */
function feature_cycle() {
  if (!$(".view-project-photo-slider").is(".photo-slider-hover")) { // Don't cycle during hover.
    if (!$(".view-project-photo-slider .views-row:eq(" + Drupal.settings.dosomething.photoSliderIndex + ")").next().length) {
      var next = 0;
    }
    else {
      var next = Drupal.settings.dosomething.photoSliderIndex + 1;
    }
    $(".view-project-photo-slider .views-row:eq(" + Drupal.settings.dosomething.photoSliderIndex + ")").hide();
    $(".view-project-photo-slider .views-row:eq(" + next + ")").show();
    $('.slide-count span').removeClass('active');
    $(".slide-count span:eq(" + ($(".slide-count span").length - (next + 1)) + ")").addClass('active');
    Drupal.settings.dosomething.photoSliderIndex = next;
  }
  // And repeat.
  setTimeout(function() {
    feature_cycle();
  }, 10000);
}

}(jQuery));

