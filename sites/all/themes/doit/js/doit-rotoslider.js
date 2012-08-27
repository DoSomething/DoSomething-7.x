(function ($) {

Drupal.behaviors.doit_rotoslider = {
  attach: function (context, settings) {
    $('.rotoslider').each(function (index, slider) {
      $('.rotoslider-nav', $(slider))
        .find('li a')
          .click(function () {
            var href = $('[data-key=' + $(this).data('key') + ']').find('.heading a').attr('href');
            $('.do-this-link', $(slider)).attr('href', href);
          })
        .end();
    });
  }
};

}(jQuery));
