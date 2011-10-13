(function ($) {
  Drupal.behaviors.selectbox = {
    attach: function (context, settings) {
      // $("select").selectBox();
      $("#block-dosomething-blocks-dosomething-make-impact select").selectBox();
      $("#dosomething-blocks-make-an-impact-form select").selectBox();
      $("#dosomething-blocks-make-an-impact-form-front select").selectBox();
    }
  }
})(jQuery);
