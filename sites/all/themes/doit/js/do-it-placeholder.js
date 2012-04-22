(function ($) {

Drupal.behaviors.doit_placeholder = {
  attach: function (context, settings) {
    $(':input[placeholder]').each(function() {
      if (this.type === 'password') {
        $(this).before('<label>Password</label>');
      }
    });
    $("#dosomething-login-register-popup-form #edit-cell").before('<label>Cell</label>');
    $("#dosomething-login-register-popup-form #edit-email").before('<label>Email</label>');
  }
};

}(jQuery));