jQuery(document).ready(function() {
  id = window.setInterval(
    function () {
      if (typeof FB != 'undefined') {
        // Scroll the containing window.
        FB.Canvas.scrollTo(0,0);
        // Stop running this code.
        window.clearInterval(id);
      }
    },
    5
  );
});

