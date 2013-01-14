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
      .wrapAll('<div id="webform-component-wrapper-photo">');

    
    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
