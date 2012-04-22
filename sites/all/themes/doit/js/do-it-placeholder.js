(function ($) {

Drupal.behaviors.doit_placeholder = {
  attach: function (context, settings) {
    $(':input[placeholder]').each(function() {
      if (this.type === 'password') {
        $(this).before('<label>Password</label>');
      }
    });
  }
};

}(jQuery));