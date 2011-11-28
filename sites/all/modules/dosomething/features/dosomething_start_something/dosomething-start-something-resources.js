/**
 * Customize the behavior of the exposed filters on the resources page.
 */
(function ($) {
  Drupal.behaviors.DoSomethingResources = {
    attach: function(context, settings) {
      $("select#edit-cause").change(function() {
        if ($(this).val() != 'All') {
          $("select#edit-howtos").val('All');
          $("select#edit-howtos").selectBox('value', 'All');
        }
      });
      $("select#edit-howtos").change(function() {
        if ($(this).val() != 'All') {
          $("select#edit-cause").val('All');
          $("select#edit-cause").selectBox('value', 'All');
          $("select#edit-type").val('All');
          $("select#edit-type").selectBox('value', 'All');
        }
      });
      $("select#edit-type").change(function() {
        if ($(this).val() != 'All') {
          $("select#edit-howtos").val('All');
          $("select#edit-howtos").selectBox('value', 'All');
        }
      });
    }
  }
}(jQuery));

