(function ($) {
  Drupal.behaviors.jeans12_registration = {
    attach: function (context, settings) {

    // kill old asterisks from required fields
    $('#dosomething-login-register-popup-form .popup-content .field-suffix').remove();

    if ($('body').hasClass('not-logged-in')) {
      $('#super-secret-bindable-id').click(function (e) {
        e.preventDefault();
        $('#dosomething-login-register-popup-form').attr('action', '/user/registration?destination=teensforjeans/sign-up');
        $('#dosomething-login-login-popup-form').attr('action', '/user?destination=teensforjeans/sign-up');
        $('#dosomething-login-register-popup-form').dialog({
          resizable: false,
          draggable: false,
          modal: true,
          width: 550
        });
      });
    }
  
    // le sigh
    $('#dosomething-login-register-popup-form').prepend($('#dosomething-login-register-popup-form .already-member'));

    // copy change
    $('#dosomething-login-register-popup-form #edit-title-text label').not('.drupal_hack').addClass('drupal_hack').text('Step 1').after('<h2>Connect or Sign Up</h2><h3>To be eligible for prizes from A&Eacute;ropostale and cash money for your school</h3>');

    // submit button copy change
    $('#dosomething-login-register-popup-form #edit-final-submit').not('.Manhattan').addClass('Manhattan').val('continue');

    // legal copy change to match new submit button value
    $('#dosomething-login-register-popup-form #edit-signup .description').not('Brooklyn').addClass('Brooklyn').html('<div class="description">Clicking "continue" won\'t sell your soul, but it means you agree to our<br> <a href="/about/terms-of-service">terms of service</a> &amp; <a href="/about/privacy">privacy policy</a> &amp; to receive our weekly update.</div>');

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
