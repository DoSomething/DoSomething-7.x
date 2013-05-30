(function($) {
  Drupal.behaviors.picsforpetsCampaign = {
    authed: false,
    probably_unauthed: false,
    notify_yourself: false,
    started_page: false,

    attach: function(context, settings) { 
      // URL selection by filter
      $('#filter-submit').click(function(e) {
        var type = $('#type-selection').data('id');
        var state = $('#state-selection').data('id');

        // The destination parameter is unbiased.  We need to tell it where to go here.
        var dest = (type != 'all') ? type + ((state != '') ? '-' + state : '') : ((state != '') ? state : 'root');

        document.location.href = '/cas/' + Drupal.settings.campaign.campaign_root + '/mark-clickthrough/' + dest;
        return false;
      });
      
      // Show sub nav on click for mobile
      $('#type-selection, #state-selection').click(function(){
        $(this).siblings('li').find('.filter-options').slideToggle(500)
      });
      
      $('#filter-type .filter-option').click(function() {
        $('#type-selection').text($(this).text()).data('id', $(this).data('id'));
        $('#filter-type .filter-options').slideUp('fast');
      });

      // Set selection value
      $('#filter-state .filter-option').click(function() {
        $('#state-selection').text($(this).text()).data('id', $(this).data('id'));
        $('#filter-state .filter-options').slideUp(500);
      });

      // Pre-set visible filter to page URL on load
      var s = document.location.pathname.slice(18).split('-');
      s = document.location.pathname.replace('/picsforpets-2013/', '');
      var $type_selection = $('#type-selection');
      var $state_selection = $('#state-selection');
      var $both_selection = $('#type-selection, #state-selection');

      var state = type = both = ''

      if (state = s.match(/^([A-Z]{2})\/?$/)) {
        console.log(state[1]);
      }
      else if (type = s.match(/^(cat|dog|other)s?\/?$/)) {
        console.log(type[1])
      }
      else if (both = s.match(/(cat|dog|other)s?\-([A-Z]{2})/)) {
        console.log(both[1] + " " + both[2]);
      }
      $type_selection.attr('data-id', 'all');
      $state_selection.attr('data-id', s[0]);

      $both_selection.attr('data-id', s[0]);

      $type_selection.attr('data-id', s[0]);
      $state_selection.attr('data-id', s[1]);

      // Handles Facebook sharing.
      var share_array = [];
      $('.facebook-share').each(function() {
        var picture = $(this).parent().parent().find('img').attr('src');
        var selector = $(this).attr('class').replace('facebook-share ', '');

        // Add this facebook button to the array of possible buttons on the page (used later*).
        share_array.push(selector);

        // Handles click event.
        $(this).click(function() {
          // Pop Facebook feed.
          var sid = $(this).attr('data-sid');
          Drupal.behaviors.fb.feed({
            'feed_document': document.location.origin + '/' + settings.campaign.campaign_root + '/' + sid,
            'feed_title' : settings.campaign.facebook.share.title,
            'feed_picture': picture,
            'feed_caption': settings.campaign.facebook.share.caption,
            'feed_description': settings.campaign.facebook.share.description,
            'feed_selector': selector,
            'feed_allow_multiple': false,
            'feed_noclick': true
          }, function(response) {
            // Submit the share to the database.
            $.post('/cas/' + Drupal.settings.campaign.campaign_root + '/share/' + sid, { 'origin': document.location.pathname.replace('/', ''), 'alert': true }, function(response) {
              var c = parseInt($('.' + selector + '-count').text());
              $('.' + selector + '-count').text(++c);

              // Attend to share count.
              Drupal.behaviors.picsforpetsCampaign.tip_shares(settings);
            });
          });

          return false;
        });
      });
    },

    tip_shares: function(settings) {
      settings.campaign.shares++;

      // Show the "become a furtographer" popup after 5 shares.
      if (settings.campaign.shares == 5) {
        $.fn.dsCampaignPopup(settings.campaign.campaign_root, 'tip', 0);
      }
    },
  };
})(jQuery);
