(function ($) {
  Drupal.behaviors.dsFlatIronTheme = {
    attach: function (context, settings) {

    // triggered report back
    $('#show-report-back').click(function(a){
      $(this).hide();
      a.preventDefault();
      $('#report-back').slideDown();
    })

    // triggered cause facts 
    $('.cause-link').click(function(d){
      d.preventDefault();
      $(this).parent().next().show();   
    })

    // button coloration on report back form
    $('#edit-submitted-wrapper-photo-field-webform-pictures-und-1-upload-button').live("click", function(){
      $('#edit-submit').css('background-color', '#FFCB15');
    });

    // injects wrapper
    $('#webform-component-step-two, #webform-component-header-one, #edit-submitted-field-webform-pictures')
      .not('.a')
      .addClass('a')
      .wrapAll('<div id="webform-photo-wrapper">')
    ;

    // AJAX form submission on page load
    $('#contact-form .webform-client-form').submit();

    // give users ability to hide system messages
    var btn-message = '<a href="#" class="go-button" id="btn-message">close</a>';
    $('.messages').append(btn-message);
    $('#btn-message').click(function() {
      $(this).parent().hide();   
    });

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
