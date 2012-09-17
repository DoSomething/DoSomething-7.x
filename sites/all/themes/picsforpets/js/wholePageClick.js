(function ($) {
  Drupal.behaviors.picsforpetsHomeClick = {
    attach: function (context) {
      var where = $('#logo').attr('href');
      $('div[role="main"]')
        .css('cursor', 'pointer')
        .click(function () {
          document.location = where;
        });
    }
  };
})(jQuery);
