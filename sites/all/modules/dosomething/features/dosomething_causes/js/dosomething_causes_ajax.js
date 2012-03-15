(function($) {
  Drupal.ajax.prototype.refreshViews = function (tid) {
    var ajax = this;

    if (ajax.ajaxing) return false;

    ajax.options.url = '/causes/ajax/'+tid;

    try {
      $.ajax(ajax.options);
    }
    catch (err) {
      return false;
    }

    return false;
  };

  var customSettings = {
    url: '/causes/ajax',
    event: 'click',
    keypress: false,
    prevent: false,
  };

  Drupal.ajax['dosomething_causes'] = new Drupal.ajax(null, $(document.body), customSettings);

  $(document).ready(function () {
    var selector = $('#cause-filter a');
    selector.click(function (event) {
      var clicked = $(event.target);
      history.pushState({}, 'Issue', clicked.attr('href'));
      selector.removeClass('active');
      clicked.addClass('active');
      return Drupal.ajax['dosomething_causes'].refreshViews(clicked.attr('data-tid'));
    });
  });
})(jQuery);
