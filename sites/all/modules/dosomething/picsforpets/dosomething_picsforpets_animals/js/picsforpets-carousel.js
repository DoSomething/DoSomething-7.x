/**
 * Carousel functionality for a single Pet display.
 */

(function ($) {

Drupal.behaviors.dosomethingPicsforpetsCarousel = {
  attach: function (context, settings) {

    settings.picsforpetsAnimals.index = 0;

    // Add the previous/next arrows.
    var $submission = $('.webform-submission');
    $submission.after('<div class="picsforpets-next">&gt;</div>');
    $submission.before('<div class="picsforpets-prev">&lt;</div>');

    // TODO: Possibly get any query parameters from filtering the gallery over to carry over here and pass to picsforpetsCarouselimages for smarter ordering.

    // Load up initial submissions.
    $.get('/pics-for-pets/carousel/js/'+ settings.picsforpetsAnimals.sid, function(images) {
      Drupal.settings.picsforpetsAnimals.images = images;
      picsforpetsAnimalsPlaceImages();
    });


    // Respond to clicks on prev/next.
    $('.picsforpets-next').click(function() {
      settings.picsforpetsAnimals.index++;
      $('.webform-submission').empty();
      $('.webform-submission').load('/webform-submission/' + settings.picsforpetsAnimals.images[settings.picsforpetsAnimals.index].sid + ' .webform-submission');
      picsforpetsAnimalsPlaceImages();
      // The user may click next again, so ensure there are more images ready to go.
      if (settings.picsforpetsAnimals.images[settings.picsforpetsAnimals.index + 3] == undefined) {
        var length = 0;
        $.each(settings.picsforpetsAnimals.images, function(key, value) {
          length++;
        });
        if (settings.picsforpetsAnimals.total == length) {
          // There are no more images to load.
          // TODO: switch the index to one less than the lowest key?
          // settings.picsforpetsAnimals.index =
        }
        else {
          // Load up more images.
          $.get('/pics-for-pets/carousel/js/'+ settings.picsforpetsAnimals.sid + '/' + (length - 1), function(images) {
            $.extend(Drupal.settings.picsforpetsAnimals.images, images);
          });
        }
      }
    });
    $('.picsforpets-prev').click(function() {
      settings.picsforpetsAnimals.index--;
      $('.webform-submission').empty();
      $('.webform-submission').load('/webform-submission/' + settings.picsforpetsAnimals.images[settings.picsforpetsAnimals.index].sid + ' .webform-submission');
      picsforpetsAnimalsPlaceImages();
    });

    // TODO: respond to clicks of images.

  }
};

/**
 * Place neighbor images.
 */
function picsforpetsAnimalsPlaceImages() {
  var images = Drupal.settings.picsforpetsAnimals.images;
  var index = Drupal.settings.picsforpetsAnimals.index;
  $('.picsforpets-wing').remove();
  if (images[index + -2] != undefined) {
    $('.webform-submission').parent().before().before('<div class="picsforpets-wing">' + images[index + -2].image + '</div>');
  }
  if (images[index + 2] != undefined) {
    $('.webform-submission').parent().after().after('<div class="picsforpets-wing">' + images[index + 2].image + '</div>');
  }
  if (images[index + -1] != undefined) {
    $('.webform-submission').parent().before().before('<div class="picsforpets-wing">' + images[index + -1].image + '</div>');
  }
  if (images[index + 1] != undefined) {
    $('.webform-submission').parent().after().after('<div class="picsforpets-wing">' + images[index + 1].image + '</div>');
  }
}

}(jQuery));
