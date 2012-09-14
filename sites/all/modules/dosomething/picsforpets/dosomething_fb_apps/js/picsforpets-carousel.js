/**
 * Carousel functionality for a single Pet display.
 */

(function ($) {

Drupal.behaviors.dosomethingPicsforpetsCarousel = {
  attach: function (context, settings) {
    if (settings.fbappsAnimals.index !== undefined) {
      return;
    }

    settings.fbappsAnimals.index = 0;
    // Add the previous/next arrows.
    $('#slideshow-center')
      .after('<div class="slideshow-next">&gt;</div>')
      .before('<div class="slideshow-prev">&lt;</div>');

    // TODO: Possibly get any query parameters from filtering the gallery over to carry over here and pass to picsforpetsCarouselimages for smarter ordering.

    // Load up initial submissions.
    $.get('/fb/pics-for-pets/carousel/js/'+ settings.fbappsAnimals.sid, function (images) {
      settings.fbappsAnimals.images = images;
      $('#slideshow-center')
        .before('<div class="slideshow-wing outside-left"></div>')
        .before('<div class="slideshow-wing inside-left"></div>')
        .after('<div class="slideshow-wing outside-right"></div>')
        .after('<div class="slideshow-wing inside-right"></div>');
      fbappsAnimalsPlaceImages();
    });

    // Respond to clicks on next.
    $('.slideshow-next').click(function () {
      settings.fbappsAnimals.index++;
      fbappsAnimalsNext();
    });

    // Respond to clicks on prev.
    $('.slideshow-prev').click(function () {
      settings.fbappsAnimals.index--;
      fbappsAnimalsPrev();
    });
  }
};

/**
 * Place neighbor images.
 */
function fbappsAnimalsPlaceImages() {
  var images = Drupal.settings.fbappsAnimals.images;
  var index = Drupal.settings.fbappsAnimals.index;

  // Respond to clicks of images.
  var outside = '<div class="slideshow-wing outside-shade"></div>';
  var inside = '<div class="slideshow-wing inside-shade"></div>';
  $('.outside-left')
    .html(images[index - 2].image_outer + outside)
    .once('slideshow-wing')
    .click(function () {
      Drupal.settings.fbappsAnimals.index -= 2;
      fbappsAnimalsPrev();
    });
  $('.inside-left')
    .html(images[index - 1].image_inner + inside)
    .once('slideshow-wing')
    .click(function () {
      Drupal.settings.fbappsAnimals.index -= 1;
      fbappsAnimalsPrev();
    });
  $('.inside-right')
    .html(images[index + 1].image_inner + inside)
    .once('slideshow-wing')
    .click(function () {
      Drupal.settings.fbappsAnimals.index += 1;
      fbappsAnimalsNext();
    });
  $('.outside-right')
    .html(images[index + 2].image_outer + outside)
    .once('slideshow-wing')
    .click(function () {
      Drupal.settings.fbappsAnimals.index += 2;
      fbappsAnimalsNext();
    });
}

function fbappsAnimalsButton(direction) {
  var modifier = (direction == 'prev') ? -1 : 1;
  var offset4 = 4 * modifier;
  var offset3 = 3 * modifier;
  var images = Drupal.settings.fbappsAnimals.images;
  var index = Drupal.settings.fbappsAnimals.index;
  $('#slideshow-center')
    .empty()
    .load('/webform-submission/' + images[index].sid + ' #slideshow-center', function () {
      fbappsAnimalsLoadFacebook();
      fbappsAnimalsPlaceImages();
    });

  // The user may click next again, so ensure there are more images ready to go.
  if (images[index + offset4] == undefined) {
    var length = 0;
    for (var i in images) {
      if (images.hasOwnProperty(i)) {
        length++;
      }
    }

    if (Drupal.settings.fbappsAnimals.total != length) {
      // Load up more images.
      $.get('/fb/pics-for-pets/carousel/js/'+ Drupal.settings.fbappsAnimals.sid + '/' + (length - 1), function (images) {
        $.extend(Drupal.settings.fbappsAnimals.images, images);
        // We may still need to grab images from the other side of the carousel.
        // Ensure this is run after the AJAX request completes.
        fbappsAnimalsReindex(index + offset3, direction);
        fbappsAnimalsReindex(index + offset4, direction);
      });
    }
    else {
      // Grab images from the other side of the carousel.
      fbappsAnimalsReindex(index + offset3, direction);
      fbappsAnimalsReindex(index + offset4, direction);
    }
  }
}

function fbappsAnimalsNext() {
  fbappsAnimalsButton('next');
}

function fbappsAnimalsPrev() {
  fbappsAnimalsButton('prev');
}

function fbappsAnimalsReindex(index, direction) {
  var images = Drupal.settings.fbappsAnimals.images;
  if (images[index] == undefined) {
    // Take one off the other side of the carousel.
    // Find the highest or lowest key in the images.
    var limit = Drupal.settings.fbappsAnimals.index;
    for (var key in images) {
      if (images.hasOwnProperty(key)) {
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
      }
    }
    Drupal.settings.fbappsAnimals.images[index] = images[limit];
    delete images[limit];
  }
}

function fbappsAnimalsLoadFacebook() {
  Drupal.attachBehaviors('#picsforpets-share');
}

}(jQuery));
