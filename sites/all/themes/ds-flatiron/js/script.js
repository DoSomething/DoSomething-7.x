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
    $('#webform-component-step-two, #webform-component-step-two, #edit-submitted-field-webform-pictures, #webform-component-donation-location-zip, #webform-component-donation-item-count, #webform-component-item-upload-description, #webform-component-people-involved, .report-back-form .form-actions')
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

// SOCIAL SECTION
// --------------

    // create local variables
    var fb_share_img = 'http://www.dosomething.org/files/styles/campaigns_image/public/pbj-campaign.jpg';
    var fb_title = 'Which Team Are You?';
    var fb_caption = 'Are you Team Crunchy or Team Smooth?';

    Drupal.behaviors.fb.feed({
      'feed_picture': 'http://www.dosomething.org/files/campaigns/pbjs13/bg-social1.png',
      'feed_title': fb_title,
      'feed_caption': fb_caption,
      'feed_description': 'I\'m #TeamCrunchy when it comes to my peanut butter! What are you? Pick sides in @dosomething\'s #PBJSlam now: http://www.dosomething.org/pbj',
      'feed_selector': '.share-link-social1',
    }, function(response){
      window.location.href = '/wyr#social';
    });

    Drupal.behaviors.fb.feed({
      'feed_picture': 'http://www.dosomething.org/files/campaigns/pbjs13/bg-social2.png',
      'feed_title': fb_title,
      'feed_caption': fb_caption,
      'feed_description': 'I\'m #TeamSmooth when it comes to my peanut butter! What are you? Pick sides in @dosomething\'s #PBJSlam now: http://www.dosomething.org/pbj',
      'feed_selector': '.share-link-social2',
    }, function(response){
      window.location.href = '/wyr#social';
    });

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
