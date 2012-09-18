(function ($) {
  Drupal.behaviors.picsforpetsHomeClick = {
    attach: function (context) {
      var where = $('#gallery-link .picsforpets-gallery a').attr('href');
      $('#logo, #ds-logo').attr('href', where);
      $('div[role="main"]')
        .css('cursor', 'pointer')
        .click(function () {
          document.location = where;
        });
    }
  };
})(jQuery);
