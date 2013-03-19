(function ($) {
  Drupal.behaviors.dsFlatIronTheme = {
    attach: function (context, settings) {

// CONTACT + REPORT BACK FORMS
// ---------------------------

    // remove the IDs from .form-submit <input> elements and parent <div>
    // TODO - EDIT THE CONTACT/REPORT BACK MODULES & REMOVE THESE IF POSSIBLE
    $('.contact-form .form-submit, .report-back-form .form-submit').removeAttr('id').parent().removeAttr('id');

// CONTACT FORM
// ------------

// REPORT BACK
// -----------

    // inject wrapper because putting the Picture filed inside a fieldset breaks webform entity
    $('#webform-component-step-two, #webform-component-step-two, #edit-submitted-field-webform-pictures, #webform-component-donation-location-zip, #webform-component-donation-item-count, #webform-component-item-upload-description, .report-back-form .form-actions')
      .not('.a')
      .addClass('a')
      .wrapAll('<div id="webform-photo-wrapper">')
    ;

    // take zipcode and pass it as anchor destination
    var $food_bank_finder = $('.food_bank_finder');
    var $finder_input = $('.food-bank-finder-input');

    $('.food-bank-finder .form-submit').click(function() {
    
      if (!$finder_input.val().match(/^\d+$/) || $finder_input.val().length !== 5) {
        $('.food-bank-finder-error').show();
        return false;
      }

      else if ($finder_input.val().match(/^\d+$/) && $finder_input.val().length == 5) {
        $('.food-bank-finder .form-submit').attr('href', 'http://feedingamerica.org/foodbank-results.aspx?zip=' + $finder_input.val());
      }

    });

// CAUSE SECTION
// -------------
    
    // triggered cause facts 
    $('.cause-link').click(function(d){
      d.preventDefault();
      $(this).parent().next().toggleClass('active-fact');
    })

    // MISC FUNCTIONALITY
    // ------------------

    // give users ability to hide system messages
    var btn_message = '<a href="#" class="go-button" id="btn_message">close</a>';
    $('.messages').append(btn_message);
    $('#btn_message').click(function() {
      $(this).parent().hide();   
    });

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
