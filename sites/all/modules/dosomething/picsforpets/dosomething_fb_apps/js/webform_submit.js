(function ($) {

// jQuery plugin to prevent double submission of forms
$.fn.preventDoubleSubmission = function() {
  $(this).bind('click',function(e){
    var $form = $(this);

    if ($form.data('submitted') === true) {
      // Previously submitted - don't submit again
      e.preventDefault();
    }
    else {
      // Mark it so that the next submit can be ignored
      $form.data('submitted', true);
    }
  });

  // Keep chainability
  return this;
};

/**
 * Hides or shows other field on pet app form.
 */
Drupal.behaviors.picsforpetsFormSubmit = {
  attach: function (context) {
    $(context)
      .find(".node-fb-app-data-gathering-form form.webform-client-form #edit-submit")
      .once('dsPfpFormSubmit')
      .preventDoubleSubmission();
  }
};

})(jQuery);
