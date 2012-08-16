(function ($) {

Drupal.behaviors.link = {
  attach: function (context, settings) {
   var sid = settings.dosomething_picsforpets_general.most_shared;
    $('.picsforpets-gallery a').attr('href', 'webform-submission/' + sid);
  }
};

}(jQuery));
