var a2a_config = a2a_config || {};
a2a_config.templates = {
    twitter: "Reading: ${title} ${link} by @micropat"
};

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

  if (jQuery('.twitter-share-button').length > 0)
  {
    var tweet_text = "It's time to @dosomething about animal cruelty! Share stats with your friends and you could win $5k in scholarships: http://tinyurl.com/cuaf8ou";
    var to = jQuery('.twitter-share-button').attr('href');
    var changed = to.replace(/&text=[^&]+/, '&text=' + encodeURI(tweet_text));
    var another = changed.replace(/&via=[^&]+/, '');
    jQuery('.twitter-share-button').attr('href', another);
  }
});