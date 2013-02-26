(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      
      Drupal.settings.login = {
        replaceText      : 'You are almost there',
        afterReplaceText : 'Just register with DoSomething.org to join the 20th Birthday Celebration',
      };

    } // end attach: function
  }; // end Drupal.behaviors
})(jQuery); // end function ($)
