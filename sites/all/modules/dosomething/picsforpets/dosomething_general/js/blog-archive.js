(function ($) {
  Drupal.behaviors.blogArchiveblock = { 
    attach: function(context, settings) {
      // Collapse all groups on page load.
      $(".block-dosomething-blog-archive ul").each(function(i) {
        $(this).hide();
      }); 
  
      // Toggle visibility of group when clicked.
      $(".block-dosomething-blog-archive h3").click(function() {
        var icon = $(this).children(".collapse-icon");
        $(this).siblings("ul").slideToggle(function() {
          (icon.text()=="▼") ? icon.text("►") : icon.text("▼");
        }); 
      }); 
    }   
  }
}(jQuery));

