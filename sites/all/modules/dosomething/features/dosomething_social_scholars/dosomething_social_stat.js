jQuery(document).ready(function() {
  // Define our own jQuery plugin so we can call it from Drupal's AJAX callback
  jQuery('#ds-campaign-scholarship-submit-form input.form-text, #ds-campaign-submit-form input.form-text').each(function() {
    var va = jQuery(this).val();
    if (va != '')
    {
      jQuery(this).attr('placeholder', va);
      jQuery(this).attr('value', '');
    }
  })

  jQuery('.fb-share-image-link').click(function() {
    window.open(jQuery(this).attr('href'), 'FB_Share_Image', 'width=500,height=300');
    return false;
  });

  jQuery('#campaign-opt-in-help').dialog({
    autoOpen: false,
  }).css('padding-top', '10px').parent().css('background', 'white');
  jQuery('#opt-in-help, #opt-in-help-mobile').click(function () {
    jQuery('#campaign-opt-in-help').dialog('open');
    return false;
  });
});


