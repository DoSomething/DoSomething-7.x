(function ($) {
  Drupal.behaviors.dosomethingPetitionsFacebook = {
    attach: function (context, settings) {
      var obj = {
        method: 'feed',
        link: document.location.href,
        picture: $('.pane-node-field-petition-picture img').attr('src').replace('/styles/490x200/public', ''),
        name: $('#page-title').text(),
        caption: 'I just signed a petition at DoSomething.org',
        description: $('.field-name-field-petition-about p').text()
      };

      $('#petition-fb').click(function () {
        FB.ui(obj);
        return false;
      });
    }
  }
})(jQuery);
