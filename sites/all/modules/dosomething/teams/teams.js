(function ($) {

Drupal.behaviors.teams = {
  attach: function (context, settings) {
    $('.team-member form').hide();
    
    var submitButtons = [];
    $('.team-member form .form-submit').each(function (index, element) {
      submitButtons.push(element.id);
    });

    $.each(submitButtons, function(index, idVal) {
      Drupal.ajax[idVal].options.beforeSubmit = function () {
        var name = $('#'+idVal).closest('.team-member').find('.member-name').text();
        return confirm('Really remove ' + name + ' from this team?');
      };
    });

    $('#teams-remove-members').click(function () {
      $('.team-member form').toggle();
      return false;
    });
  }
};
})(jQuery);
