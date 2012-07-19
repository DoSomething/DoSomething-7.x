/**
 * Carousel functionality for a single Pet display.
 */

(function ($) {

Drupal.behaviors.dosomethingPicsforpetsCarousel = {
  attach: function (context, settings) {

    settings.picsforpetsAnimals.index = 0;

    // Add the previous/next arrows.
    var $submission = $('#slideshow-center');
    $submission.after('<div class="slideshow-next">&gt;</div>');
    $submission.before('<div class="slideshow-prev">&lt;</div>');

    // TODO: Possibly get any query parameters from filtering the gallery over to carry over here and pass to picsforpetsCarouselimages for smarter ordering.

    // Load up initial submissions.
    $.get('/pics-for-pets/carousel/js/'+ settings.picsforpetsAnimals.sid, function(images) {
      settings.picsforpetsAnimals.images = images;
      picsforpetsAnimalsPlaceImages(settings);
    });

    // Respond to clicks on next.
    $('.slideshow-next').click(function() {
      settings.picsforpetsAnimals.index++;
      picsforpetsAnimalsNext(settings);
    });

    // Respond to clicks on prev.
    $('.slideshow-prev').click(function() {
      settings.picsforpetsAnimals.index--;
      picsforpetsAnimalsPrev(settings);
    });
  }
};

/**
 * Place neighbor images.
 */
function picsforpetsAnimalsPlaceImages(settings) {
  var images = settings.picsforpetsAnimals.images;
  var index = settings.picsforpetsAnimals.index;
  $('.slideshow-wing').remove();
  $('#slideshow-center').parent().before().before('<div class="slideshow-wing outside-left">' + images[index + -2].image_outer + '</div> <div class="slideshow-wing outside-shade"></div>');
  $('#slideshow-center').parent().after().after('<div class="slideshow-wing outside-right">' + images[index + 2].image_outer + '</div> <div class ="slideshow-wing outside-shade"></div>');
  $('#slideshow-center').parent().before().before('<div class="slideshow-wing inside-left">' + images[index + -1].image_inner + '</div> <div class =    "slideshow-wing inside-shade"></div');
  $('#slideshow-center').parent().after().after('<div class="slideshow-wing inside-right">' + images[index + 1].image_inner + '</div> <div class =    "slideshow-wing inside-shade"></div');

  // Respond to clicks of images.
  $('.slideshow-wing:eq(0)').click(function() {
    settings.picsforpetsAnimals.index = settings.picsforpetsAnimals.index - 2;
    picsforpetsAnimalsPrev(settings);
  });
  $('.slideshow-wing:eq(1)').click(function() {
    settings.picsforpetsAnimals.index--;
    picsforpetsAnimalsPrev(settings);
  });
  $('.slideshow-wing:eq(2)').click(function() {
    settings.picsforpetsAnimals.index++;
    picsforpetsAnimalsNext(settings);
  });
  $('.slideshow-wing:eq(3)').click(function() {
    settings.picsforpetsAnimals.index = settings.picsforpetsAnimals.index + 2;
    picsforpetsAnimalsNext(settings);
  });
}

function picsforpetsAnimalsNext(settings) {
  $('#slideshow-center').empty();
  $('#slideshow-center').load('/webform-submission/' + settings.picsforpetsAnimals.images[settings.picsforpetsAnimals.index].sid + ' #slideshow-center');
  picsforpetsAnimalsPlaceImages(settings);
  // The user may click next again, so ensure there are more images ready to go.
  if (settings.picsforpetsAnimals.images[settings.picsforpetsAnimals.index + 4] == undefined) {
    var length = 0;
    $.each(settings.picsforpetsAnimals.images, function(key, value) {
      length++;
    });
    if (settings.picsforpetsAnimals.total != length) {
      // Load up more images.
      $.get('/pics-for-pets/carousel/js/'+ settings.picsforpetsAnimals.sid + '/' + (length - 1), function(images) {
        $.extend(Drupal.settings.picsforpetsAnimals.images, images);
        // We may still need to grab images from the other side of the carousel.
        // Ensure this is run after the AJAX request completes.
        picsforpetsAnimalsReindex(settings.picsforpetsAnimals.index + 3, 'next');
        picsforpetsAnimalsReindex(settings.picsforpetsAnimals.index + 4, 'next');
      });
    }
    else {
      // Grab images from the other side of the carousel.
      picsforpetsAnimalsReindex(settings.picsforpetsAnimals.index + 3, 'next');
      picsforpetsAnimalsReindex(settings.picsforpetsAnimals.index + 4, 'next');
    }
  }
}

function picsforpetsAnimalsPrev(settings) {
  $('#slideshow-center').empty();
  $('#slideshow-center').load('/webform-submission/' + settings.picsforpetsAnimals.images[settings.picsforpetsAnimals.index].sid + ' #slideshow-center');
  picsforpetsAnimalsPlaceImages(settings);
  // The user may click next again, so ensure there are more images ready to go.
  if (settings.picsforpetsAnimals.images[settings.picsforpetsAnimals.index - 4] == undefined) {
    var length = 0;
    $.each(settings.picsforpetsAnimals.images, function(key, value) {
      length++;
    });
    if (settings.picsforpetsAnimals.total != length) {
      // Load up more images.
      $.get('/pics-for-pets/carousel/js/'+ settings.picsforpetsAnimals.sid + '/' + (length - 1), function(images) {
        $.extend(Drupal.settings.picsforpetsAnimals.images, images);
        // We may still need to grab images from the other side of the carousel.
        // Ensure this is run after the AJAX request completes.
        picsforpetsAnimalsReindex(settings.picsforpetsAnimals.index - 3, 'prev');
        picsforpetsAnimalsReindex(settings.picsforpetsAnimals.index - 4, 'prev');
      });
    }
    else {
      // Grab images from the other side of the carousel.
      picsforpetsAnimalsReindex(settings.picsforpetsAnimals.index - 3, 'prev');
      picsforpetsAnimalsReindex(settings.picsforpetsAnimals.index - 4, 'prev');
    }
  }
}

function picsforpetsAnimalsReindex(index, direction) {
  if (Drupal.settings.picsforpetsAnimals.images[index] == undefined) {
    // Take one off the other side of the carousel.
    // Find the highest or lowest key in the images.
    var limit = Drupal.settings.picsforpetsAnimals.index;
    $.each(Drupal.settings.picsforpetsAnimals.images, function(key, value) {
      if (direction == 'prev') {
        if (parseInt(key) > parseInt(limit)) {
          limit = key;
        }
      }
      if (direction == 'next') {
        if (parseInt(key) < parseInt(limit)) {
          limit = key;
        }
      }
    });
    Drupal.settings.picsforpetsAnimals.images[index] = Drupal.settings.picsforpetsAnimals.images[limit];
    delete Drupal.settings.picsforpetsAnimals.images[limit];
  }
}

}(jQuery));
