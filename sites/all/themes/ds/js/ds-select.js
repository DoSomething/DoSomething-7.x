(function ($) {
  Drupal.behaviors.selectbox = {
    attach: function (context, settings) {
      // $("select").selectBox();
      $("#block-dosomething-blocks-dosomething-make-impact select").selectBox();
      $("#dosomething-blocks-make-an-impact-form select").selectBox();
      $("#dosomething-blocks-make-an-impact-form-front select").selectBox();
      $("#views-exposed-form-action-finder-ctools-context-1 select").selectBox();
      $("#views-exposed-form-resources-panel-pane-1 select").selectBox();
      $("#views-exposed-form-action-updates-panel-pane-1 select").selectBox();
    }
  }
})(jQuery);
