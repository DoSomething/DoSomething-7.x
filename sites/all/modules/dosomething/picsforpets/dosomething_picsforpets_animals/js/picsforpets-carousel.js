/**
 * Carousel functionality for a single Pet display.
 */

(function ($) {

Drupal.behaviors.dosomethingPicsforpetsCarousel = {
  attach: function (context, settings) {
    alert('hey');
    // Add the previous/next arrows.
    var $submission = $('.webform-submission');
    $submission.after('<div class="picsforpets-next">&gt;</div>');
    $submission.before('<div class="picsforpets-prev">&lt;</div>');

    // TODO: Possibly get any query parameters from filtering the gallery over to carry over here and pass to picsforpetsCarouselwings for smarter ordering.

    // Add four neighbor images.
    $.get('/pics-for-pets/carousel/js/'+ settings.picsforpetsAnimals.sid + '/4', function(wings) {
      console.log(wings);
      // TODO: store all wings with indices into a setting as we get them.
      settings.picsforpetsAnimals.wings = wings;
      settings.picsforpetsAnimals.wings['0'].sid = settings.picsforpetsAnimals.sid;
      picsforpetsAnimalsReloadImages();
    });


    // Respond to clicks on prev/next.
    $('.picsforpets-next').click(function() {
      $('.webform-submission').load('/webform-submission/' + settings.picsforpetsAnimals.wings[1].sid + ' .webform-submission');
      settings.picsforpetsAnimals.wings['-2'] = settings.picsforpetsAnimals.wings['-1'];
      settings.picsforpetsAnimals.wings['-1'] = settings.picsforpetsAnimals.wings['0'];
      settings.picsforpetsAnimals.wings['0'] = settings.picsforpetsAnimals.wings['1'];
      settings.picsforpetsAnimals.wings['1'] = settings.picsforpetsAnimals.wings['2'];

      $.get('/pics-for-pets/carousel/js/'+ settings.picsforpetsAnimals.wings['0'].sid + '/1/' + (settings.picsforpetsAnimals.wings.length - 1), function(wings) {
        console.log(wings);
        if (wings['0'] != undefined) {
          $submission.parent().after().after(wings['0'].image);
          settings.picsforpetsAnimals.wings['2'] = wings['0'];
        }
      });

      picsforpetsAnimalsReloadImages();
    });
  }
};

function picsforpetsAnimalsReloadImages() {
  var wings = Drupal.settings.picsforpetsAnimals.wings;
  if (wings['-1'] != undefined) {
    $('.webform-submission').parent().before().before(wings['-1'].image);
  }
  if (wings['1'] != undefined) {
    $('.webform-submission').parent().after().after(wings['1'].image);
  }
}

}(jQuery));
