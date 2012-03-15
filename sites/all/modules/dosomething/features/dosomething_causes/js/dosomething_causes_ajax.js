(function($) {
  Drupal.ajax.prototype.refreshViews = function (tid, t_parent) {
    var ajax = this;

    if (ajax.ajaxing) return false;

    ajax.options.url = '/causes/ajax/'+tid+'/'+t_parent;

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
    var t_parent = $('#cause-filter').attr('data-tid');
    selector.click(function (event) {
      var clicked = $(event.target);
      history.pushState({}, 'Issue', clicked.attr('href'));
      selector.removeClass('active');
      clicked.addClass('active');
      return Drupal.ajax['dosomething_causes'].refreshViews(clicked.attr('data-tid'), t_parent);
    });
  });
})(jQuery);
