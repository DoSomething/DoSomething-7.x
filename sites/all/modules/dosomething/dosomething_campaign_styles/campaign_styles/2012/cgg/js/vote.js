(function($) {
  Drupal.behaviors.cgg = {
    attach: function(context, settings) {

      // CGG_SELECT.JS
      $('#webform-component-cgg-choose-a-celebrity input, #edit-actions').hide();
      $('#webform-component-cgg-choose-a-celebrity .form-item').wrapInner('<div class="celebrity"><div class="celebrity_inner"></div>');
      $('.celebrity_inner').prepend('<div class="celebrity_image"></div>');

      $('.celebrity_inner').click(function(){
        $(this).find('input').attr('checked','checked');  

        $('.celebrity_inner').css('background','rgba(0,0,0,0.4)');
        $(this).css('background','rgba(0,100,200,0.4)').after($('#edit-actions'));
        $('#edit-actions').hide().fadeIn(600);
      });

    }	
  };
})(jQuery);
