/**
 * Carousel functionality for a single Pet display.
 */

(function ($) {

Drupal.behaviors.dosomethingPicsforpetsCarousel = {
  attach: function (context, settings) {
    if (settings.fbappsAnimals.index == undefined) {
      settings.fbappsAnimals.index = 0;
      // Add the previous/next arrows.
      var $submission = $('#slideshow-center');
      $submission.after('<div class="slideshow-next">&gt;</div>');
      $submission.before('<div class="slideshow-prev">&lt;</div>');

      // TODO: Possibly get any query parameters from filtering the gallery over to carry over here and pass to picsforpetsCarouselimages for smarter ordering.

      // Load up initial submissions.
      $.get('/fb/pics-for-pets/carousel/js/'+ settings.fbappsAnimals.sid, function(images) {
        settings.fbappsAnimals.images = images;
        fbappsAnimalsPlaceImages(settings);
      });

      // Respond to clicks on next.
      $('.slideshow-next').click(function() {
        settings.fbappsAnimals.index++;
        fbappsAnimalsNext(settings);
      });

      // Respond to clicks on prev.
      $('.slideshow-prev').click(function() {
        settings.fbappsAnimals.index--;
        fbappsAnimalsPrev(settings);
      });
    }


  }
};

/**
 * Place neighbor images.
 */
function fbappsAnimalsPlaceImages(settings) {
  var images = settings.fbappsAnimals.images;
  var index = settings.fbappsAnimals.index;
  $('.slideshow-wing').remove();
  if (images[index + -2]) {
    $('#slideshow-center').parent().before().before('<div class="slideshow-wing outside-left">' + images[index + -2].image_outer + '<div class="slideshow-wing outside-shade"></div></div>');
  }
  if (images[index + 2]) {
    $('#slideshow-center').parent().after().after('<div class="slideshow-wing outside-right">' + images[index + 2].image_outer + '<div class="slideshow-wing outside-shade"></div></div>');
  }
  if (images[index + -1]) {
    $('#slideshow-center').parent().before().before('<div class="slideshow-wing inside-left">' + images[index + -1].image_inner + '<div class="slideshow-wing inside-shade"></div></div>');
  }
  if (images[index + 1]) {
    $('#slideshow-center').parent().after().after('<div class="slideshow-wing inside-right">' + images[index + 1].image_inner + '<div class="slideshow-wing inside-shade"></div></div>');
  }

  // Respond to clicks of images.
  $('.outside-left').next().click(function() {
    settings.fbappsAnimals.index = settings.fbappsAnimals.index - 2;
    fbappsAnimalsPrev(settings);
  });
  $('.inside-left').next().click(function() {
    settings.fbappsAnimals.index--;
    fbappsAnimalsPrev(settings);
  });
  $('.inside-right').next().click(function() {
    settings.fbappsAnimals.index++;
    fbappsAnimalsNext(settings);
  });
  $('.outside-right').next().click(function() {
    settings.fbappsAnimals.index = settings.fbappsAnimals.index + 2;
    fbappsAnimalsNext(settings);
  });
}

function fbappsAnimalsNext(settings) {
  $('#slideshow-center').empty();
  $('#slideshow-center').load('/webform-submission/' + settings.fbappsAnimals.images[settings.fbappsAnimals.index].sid + ' #slideshow-center', function() {
    fbappsAnimalsLoadFacebook();
    fbappsAnimalsPlaceImages(settings);
  });
  // The user may click next again, so ensure there are more images ready to go.
  if (settings.fbappsAnimals.images[settings.fbappsAnimals.index + 4] == undefined) {
    var length = 0;
    $.each(settings.fbappsAnimals.images, function(key, value) {
      length++;
    });
    if (settings.fbappsAnimals.total != length) {
      // Load up more images.
      $.get('/fb/pics-for-pets/carousel/js/'+ settings.fbappsAnimals.sid + '/' + (length - 1), function(images) {
        $.extend(Drupal.settings.fbappsAnimals.images, images);
        // We may still need to grab images from the other side of the carousel.
        // Ensure this is run after the AJAX request completes.
        fbappsAnimalsReindex(settings.fbappsAnimals.index + 3, 'next');
        fbappsAnimalsReindex(settings.fbappsAnimals.index + 4, 'next');
      });
    }
    else {
      // Grab images from the other side of the carousel.
      fbappsAnimalsReindex(settings.fbappsAnimals.index + 3, 'next');
      fbappsAnimalsReindex(settings.fbappsAnimals.index + 4, 'next');
    }
  }
}

function fbappsAnimalsPrev(settings) {
  $('#slideshow-center').empty();
  $('#slideshow-center').load('/webform-submission/' + settings.fbappsAnimals.images[settings.fbappsAnimals.index].sid + ' #slideshow-center', function() {
    fbappsAnimalsLoadFacebook();
    fbappsAnimalsPlaceImages(settings);
  });
  // The user may click next again, so ensure there are more images ready to go.
  if (settings.fbappsAnimals.images[settings.fbappsAnimals.index - 4] == undefined) {
    var length = 0;
    $.each(settings.fbappsAnimals.images, function(key, value) {
      length++;
    });
    if (settings.fbappsAnimals.total != length) {
      // Load up more images.
      $.get('/fb/pics-for-pets/carousel/js/'+ settings.fbappsAnimals.sid + '/' + (length - 1), function(images) {
        $.extend(Drupal.settings.fbappsAnimals.images, images);
        // We may still need to grab images from the other side of the carousel.
        // Ensure this is run after the AJAX request completes.
        fbappsAnimalsReindex(settings.fbappsAnimals.index - 3, 'prev');
        fbappsAnimalsReindex(settings.fbappsAnimals.index - 4, 'prev');
      });
    }
    else {
      // Grab images from the other side of the carousel.
      fbappsAnimalsReindex(settings.fbappsAnimals.index - 3, 'prev');
      fbappsAnimalsReindex(settings.fbappsAnimals.index - 4, 'prev');
    }
  }
}

function fbappsAnimalsReindex(index, direction) {
  if (Drupal.settings.fbappsAnimals.images[index] == undefined) {
    // Take one off the other side of the carousel.
    // Find the highest or lowest key in the images.
    var limit = Drupal.settings.fbappsAnimals.index;
    $.each(Drupal.settings.fbappsAnimals.images, function(key, value) {
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
    Drupal.settings.fbappsAnimals.images[index] = Drupal.settings.fbappsAnimals.images[limit];
    delete Drupal.settings.fbappsAnimals.images[limit];
  }
}

function fbappsAnimalsLoadFacebook() {
  Drupal.attachBehaviors('#picsforpets-share');
}

}(jQuery));
