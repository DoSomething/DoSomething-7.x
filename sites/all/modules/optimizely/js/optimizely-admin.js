/*
 * @file
 * A collection of Javascript functionality for the admin interface of the Optimizely module.
 *
 * Supports click events for the project listing checkbox that enable and disable project
 * entries. The .ajax framework will be an outline of how further functionality will be added
 * to support the Optimizely API.
 */
(function($) {
  Drupal.behaviors.optimizely = {
    attach: function (context, settings) {

      // respond to checkbox being selected
      $('.form-checkbox').once().change(function() {
        
        // Get the details of the clicked item
        var target_oid = $(this).attr('name').substring(8);
        var target_enable = $(this).is(':checked');
        
        // Translate returned response to int value
        (target_enable == true) ? target_enable = 1 : target_enable = 0;
  
        // Build string to pass values via 'POST'd
        var post = "target_oid=" + target_oid + "&target_enable=" + target_enable;
        
        $.ajax({
          'url': '/ajax/optimizely',
          'type': 'POST',
          'dataType': 'json',
          'data': post,
          'success': function(data) {
            
            // Main selector for checkbox event
            var target_this = '#project-enable-' + data.oid;
            
            if (data.status == "updated") {
                      
              // Toggle enable / disabled class
              if ($(target_this).attr('checked')) {
                $(target_this).parents('tr').find('td').addClass('enabled').removeClass('disabled');
                $(target_this).parents('tr').find('div.status-' + data.oid).attr("innerHTML","Project enabled successfully.");
                $(target_this).parents('tr').find('div.status-' + data.oid).fadeOut(6000, function() { $(this).attr("innerHTML","").css('display', '') });
                
              }
              else {
                $(target_this).parents('tr').find('td').addClass('disabled').removeClass('enabled');
                $(target_this).parents('tr').find('div.status-' + data.oid).attr("innerHTML","Project disabled successfully.");
                $(target_this).parents('tr').find('div.status-' + data.oid).fadeOut(6000, function() { $(this).attr("innerHTML","").css('display', ''); });
              }
              
            }
            else {
              
              // Reset checkbox
              if($(target_this).parents('tr').find('td').hasClass('disabled')) {
                $('input[name=project-' + data.oid + ']').removeAttr('checked');
              } else {
                $('input[name=project-' + data.oid + ']').attr('checked');
              }

              // Display status message
              $(target_this).parents('tr').find('div.status-' + data.oid).attr("innerHTML","Project was not enabled due to path setting resulting in a duplicate path.");
              $(target_this).parents('tr').find('div.status-' + data.oid).fadeOut(6000, function() { $(this).attr("innerHTML","").css('display', ''); });
            }
            
          },
          'beforeSend': function() {
            
            $(document).ready(function (data) {
              
              var target_this = '#project-enable-' + data.oid;
              $(target_this).parents('tr').find('div.status-' + data.oid).attr("innerHTML","Loading....");
              $(target_this).parents('tr').find('div.status-' + data.oid).fadeOut(6000, function() { $(this).attr("innerHTML","").css('display', ''); });
              
            });
            
          },
          'error': function(data) {
                     
            $(document).ready(function () {

              var target_this = '#project-enable-' + data.oid;
              $(target_this).parents('tr').find('div.status-' + data.oid).attr("innerHTML","ERROR OCCURRED!");
              $(target_this).parents('tr').find('div.status-' + data.oid).fadeOut(6000, function() { $(this).attr("innerHTML","").css('display', ''); });
              
            });
            
          }

        });

      });

    }
  }; 

})(jQuery);