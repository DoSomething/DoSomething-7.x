(function ($) {
  Drupal.behaviors.campaignPopups = {
    attach: function (context, settings) {
      // keep track of the popups that we initialize
      var popups = new Array();

      // initialize the popup boxes
      $('.panel-popups .panel-pane').not('#panelizer-edit-content-form .panel-pane').dialog({
          autoOpen: false
        , modal: true
        , resizable: false
        , open: $('.ui-widget-overlay').bind('click', function () { $(this).siblings('.ui-dialog').find('.ui-dialog-content').dialog('close'); })
      });

      // make the popups happen
      $('.ds-popup').click(function (clickEvent) {
        var selector = $(this).attr('data-popup');
        var dataWidth = $(this).attr('data-width');
        var dataHeight = $(this).attr('data-height');
        
        if (isNaN(dataWidth)) dataWidth = 300;
        if (isNaN(dataHeight)) dataHeight = 'auto';

        $('.ui-dialog ' + selector)
          .dialog('option', {
              height: dataHeight
            , width: dataWidth
          }).dialog('open');
        return false;
      });


      $('.pane-campaign-gallery-panel-pane-1 ul.pager li a').each(function() {
        $(this).attr('href', $(this).attr('href') + '#galleriffic');
      });
    }
  };
})(jQuery);
