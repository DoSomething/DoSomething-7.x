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

  var img_loader = $('<img />', {
    'src': '/sites/all/modules/dosomething/features/dosomething_causes/images/loader.gif',
    'height': '18px',
  }).css('margin', '0 auto');
  img_loader = $('<div />').css({'text-align': 'center', 'height': '18px'}).append(img_loader);

  var selector, t_parent;

  function moveStuff(element) {
    $('#cause-filter li').removeClass('active');

    var move = element.parent().prevAll('li').get().reverse();
    moveCounter(move.length, false);
    var left = 0;
    if (move.length > 0)
      left = (move.length+1)*86;

    element.parent().addClass('active');  
    $(move).clone(true, true).appendTo($('#cause-filter'));
    $(move).animate({'margin-left': -left}, 700, function () {
      $(move).remove();
    });
  }

  function moveStuffBackwards(element) {
    $('#cause-filter li').removeClass('active');

    element = $(element).parent().addClass('active');
    $(element)
      .clone(true, true)
      .prependTo($('#cause-filter')).css('margin-left', -220)
      .animate({'margin-left': 0}, 700, function () {
        $(element).remove();
      });
  }

  function doClick(clicked, reverse) {
    $('html,body').animate({scrollTop: $('h1.title').offset().top}, 'fast');
    if (!ajaxing()) {
      $('.pane-current-campaigns-panel-pane-1 .pane-content, .pane-project-related-displays-panel-pane-3 .pane-content, .pane-polls-panel-pane-1 .pane-content')
        .empty();
      $('.pane-term-description .pane-content').html(img_loader);

      if (!reverse) moveStuff(clicked);
      else moveStuffBackwards(clicked);

      return Drupal.ajax['dosomething_causes'].refreshViews(clicked.attr('data-tid'), t_parent)
    }
  }

  function moveCounter(numToMove, reverse) {
    if (!reverse) counterState = (counterState + numToMove) % numItems;
    else counterState--;

    $('#cause-counter').html((counterState+1) + ' of ' + numItems);
  }

  function counterInit() {
    $('#cause-scroller-wrapper').parent().append('<div id="cause-counter">1 of 6</div>');
  }

  function clickInit(clicked) {
    if (!ajaxing()) {
      var pattern = /taxonomy-term-[0-9]+/ig;
      var result = pattern.exec(clicked.parent().attr('class'));
      history.pushState({term: result}, 'Issue', clicked.attr('href'));
    }
  }

  function ajaxing() {
    return Drupal.ajax['dosomething_causes'].ajaxing;
  }

  var counterState = 0;
  var numItems = 0;
  $(document).ready(function () {
    selector = $('#cause-filter a');
    t_parent = $('#cause-filter').attr('data-tid');
    numItems = $('#cause-filter li').length;

    counterInit();
    
    $('#browse-left').click(function () {
      var e = $('#cause-filter li:last-child a');
      clickInit(e);
      doClick(e, true);
    });

    $('#browse-right').click(function () {
      var e = $('#cause-filter li:nth-child(2) a');
      clickInit(e);
      doClick(e, false);
    });

    selector.click(function (event) {
      var e = $(event.currentTarget);
      clickInit(e);
      doClick(e, false);
      return false;
    });
    moveStuff($('#cause-filter .active'));
  });

  $(window).bind('popstate', function (e) {
    if (e.originalEvent.state !== null) {
      doClick($('.' + e.originalEvent.state.term + ' a'), false);
    }
    else {
      var pattern = /taxonomy-term-[0-9]+/ig;
      var result = pattern.exec($('#cause-filter .active').attr('class'));
      history.replaceState({term: result}, 'Issue', document.location);
    }
  });
})(jQuery);
