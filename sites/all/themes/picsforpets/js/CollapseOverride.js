(function ($) {
  Drupal.toggleFieldsetOriginal = Drupal.toggleFieldset;

  Drupal.toggleFieldset = function (fieldset) {
    Drupal.toggleFieldsetOriginal(fieldset);

    $others = $('fieldset.collapsible').not(fieldset);

    $others.trigger({ type: 'collapsed', value: true }); 
    $others.find('> .fieldset-wrapper').slideUp('fast', function () {
      $(this).parent()
        .addClass('collapsed')
        .find('> legend span.fieldset-legend-prefix').html(Drupal.t('Show'));
    }); 
  };
})(jQuery);
