(function ($) {
  document.iframes = [];

  $(document).bind('DOMNodeInserted', function (event) {
    if (event.target.tagName == 'IFRAME') {
      var $frame = $(event.target);
      replaceIframe($frame);
    }
  });

  $(document).ready(function () {
    var $window = $(window);
    var windowBottom;

    $('iframe').not('.cke_contents iframe').each(function (index, element) {
      var $element = $(element);
      replaceIframe($element);
    });

    $window.scroll(function () {
      windowBottom = $window.scrollTop() + $window.height();
      $('.defer-iframe-load').each(function (index, element) {
        var $element = $(element);
        if (windowBottom >= $element.offset().top) {
          var $iframe = document.iframes[$element.attr('data-iframe-offset')];
          $(element).replaceWith($iframe);
        }
      });
    });

  });

  function replaceIframe($element) {
    var $window = $(window);
    var currentScroll = $window.scrollTop() + $window.height();
    var elementTop = $element.offset().top;

    if (currentScroll < elementTop) {
      var $newElement = $('<div>').addClass('defer-iframe-load');
      $element.replaceWith($newElement);
      $newElement.attr('data-iframe-offset', document.iframes.push($element)-1);
    }
  }

}(jQuery));
