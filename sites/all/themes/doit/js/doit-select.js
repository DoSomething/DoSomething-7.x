(function ($) {

Drupal.behaviors.selectbox = {
  attach: function (context, settings) {
    // fancy dropdowns weren't working in IE7
    if (!(($.browser.msie == true) && ($.browser.version < 7.0))) {
      $('#block-dosomething-blocks-dosomething-make-impact select').selectBox();
      $('#dosomething-blocks-make-an-impact-form select').selectBox();
      $('#dosomething-blocks-make-an-impact-form-front select').selectBox();
      $('.views-exposed-form select').selectBox();
      $('#edit-jump').selectBox();
    }
  }
};

}(jQuery));
