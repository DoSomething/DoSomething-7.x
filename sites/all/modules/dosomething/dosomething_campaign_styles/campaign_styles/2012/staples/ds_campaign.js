(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {
      
    // Raise Your Hand confirmation dialog
  if(location.pathname.match(/staples\/raise-your-hand\/share/) && location.search.match(/\?s=[0-9A-Za-z\-]*/)) {
      $("#sweeps_confirmation_popup").dialog({ width: 708, height: 390, resizable: false });
    }

    }
  };
})(jQuery);
