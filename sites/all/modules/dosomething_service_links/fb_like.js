(function ($) {
  $(document).ready(function () {
    $('a.service-links-ds-facebook').each(function () {
      var like_button = $('<div>');
      like_button
        .addClass('fb-like')
        .attr('data-href', $(this).attr('href'))
        .attr('data-send', 'false')
        .attr('data-layout', 'button_count')
        .attr('data-width', '100')
        .attr('data-show-faces', 'false')
        .attr('data-action', 'recommend')
        .attr('data-font', 'trebuchet ms');

      if (like_button.attr('data-href').charAt(0) == '/') {
        like_button.attr('data-href') = window.location.origin + like_button.attr('data-href');
      }

      $(this).replaceWith(like_button);
    });
  });
})(jQuery);
