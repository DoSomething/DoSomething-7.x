(function($) {
  $(document).ready(function () {
        $(".tooltip_trigger").hover(function() {
          $(this).next(".tooltip").show();
          $(this).next(".tooltip").position(
            {
              at: 'bottom center',
              of: $(this),
              offset: '0 16px',
              my: 'top'
            });
        });
      
        $(".tooltip_trigger").mouseleave(function() {
          $(".tooltip").hide();
        }); 
    });
  });
})(jQuery);
