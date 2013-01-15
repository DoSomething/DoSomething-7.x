(function ($) {
  Drupal.behaviors.campaignName = {
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
    //  console.log("merde!");
      $('#edit-submit').css('background-color', '#FFCB15');
    });

    // injects wrapper
    $('#webform-component-step-two, #webform-component-header-one, #edit-submitted-field-webform-pictures')
      .not('.a')
      .addClass('a')
      .wrapAll('<div id="webform-photo-wrapper">');

    // AJAX form submission on page load
    $('#contact-form .webform-client-form').submit();

    // give users ability to hide system messages
    var msg_button = '<a href="#" class="go-button" id="msg_button">close</a>';
    $('.messages').append(msg_button);
    $('#msg_button').click(function() {
      console.log("boom");
      $(this).parent().hide();   
    });

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
