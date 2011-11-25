(function($) {

Drupal.behaviors.ds_rotoslider = {
  attach: function(context, settings) {
    $('.rotoslider').each(function (index, slider) {
      $('.rotoslider-nav', $(slider))
        .find('li a')
          .click(function() {
            var href = $(document.querySelectorAll('.rotoslider-text[data-key=' + $(this).data('key') + ']')).find('.heading a').attr('href');
            $('.do-this-link', $(slider)).attr('href', href);
          })
        .end();
    });
  }
};

}(jQuery));
