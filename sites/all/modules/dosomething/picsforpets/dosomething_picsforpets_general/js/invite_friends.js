(function ($) {

Drupal.behaviors.inviteFriendsModal = {
  attach: function(context, settings) {
    $('.views-widget-sort-order, .views-submit-button').hide();
    $('#picsforpets-invite-friends').click(function() {
      var obj = {
        method: 'apprequests',
        display: 'iframe',
        title: "DoSomething.org's Pics for Pets",
        message: 'You’ve been invited to help find shelter animals a new home with Pics for Pets. The more shares, the more food and toy donations the animals can get for their shelters. Help animals find a home!',
        access_token: settings.picsforpetsFBAuth.access_token,
        show_error: true
      };
      FB.ui(obj);
    });   
  }       
};        
          
Drupal.behaviors.galleryShareButton = {
  attach: function (context, settings) {
    $('.gallery-share-button').click(function () {
      if ($(this).hasClass('shared')) return;
      else {
        $(this).addClass('shared');
      }

      $('div#' + sid + ' span.gallery-share-button').text('Shared!');
            
      var sid = parseInt($(this).parent().attr('id'));
      var shareUrl = settings.picsforpetsFBAuth.app_secure_url + '/' + settings.picsforpetsFBAuth.fbFormAlias + '/submission/' + sid;
      var threeWords = [];
      threeWords[0] = 0 in settings.dosomething_picsforpets_general.gallery[sid].threeWords ? settings.dosomething_picsforpets_general.gallery[sid].threeWords[0].raw.safe_value : "Fun";
      threeWords[1] = 1 in settings.dosomething_picsforpets_general.gallery[sid].threeWords ? settings.dosomething_picsforpets_general.gallery[sid].threeWords[1].raw.safe_value : "Cute";
      threeWords[2] = 2 in settings.dosomething_picsforpets_general.gallery[sid].threeWords ? settings.dosomething_picsforpets_general.gallery[sid].threeWords[2].raw.safe_value : "Friendly";
      var share = {
        method: 'feed',
        name: 'DoSomething.org\'s Pics For Pets',
        link: shareUrl,
        picture: settings.picsforpetsFBAuth.appBaseURL + '/' + settings.dosomething_picsforpets_general.gallery[sid].pictureUrl,
        caption: settings.dosomething_picsforpets_general.gallery[sid].petName + ". I'm " + threeWords[0] + ", " + threeWords[1] + ", and " + threeWords[2],
        description: "Do Something about homeless animals, share photos of shelter pets and help them find homes. The more shares a pet gets the better chance it'll be adopted, their shelter will also be rewarded for every share!"   
      };

  FB.api('/me/permissions', function (response) {
            var perms = response.data[0];

            if (perms.publish_stream) {                
               // User has permission
            } else {                
              FB.ui({
              method: 'permissions.request',
              perms: 'publish_actions',
              display: 'popup'
              },function(response) {
                // Just making sure that they have this permission.
              });
            }                                            
    } );

    FB.api(         
        '/me/dosomethingapp:share',
        'post',     
        {         
            pet_who_needs_a_home: shareUrl,
            image: settings.picsforpetsFBAuth.appBaseURL + '/' + settings.dosomething_picsforpets_general.gallery[sid].pictureUrl,
        },  
    //FB.ui(share,  
      function(response) {
        console.log(response);
        // If the share was unsuccessful or the user clicked cancel, response
        // will be undefined. Otherwise it will be an object that contains the
        // post_id of the share.
        if ((typeof response !== 'undefined') && (response !== null)) {
          // Use FB's JS SDK to retrieve and store the user's facebook id.
          var fbuid = FB.getUserID();
          // Make POST request to this URL to update the share count on the
          // webform submission, passing in the webform submission id and the
          // user's facebook id as URL arguments.
          $.post('/fb/pics-for-pets/share/js/' + sid + '/' + fbuid, function (userShares) {
            // Update the page with the new share count.
            // Increment the displayed share count.
            var countBox = $('#' + sid + ' .gallery-share-count');
            var count = countBox.text();
            count++;
            countBox.text(count);
            // Display a modal dialog depending on the total number of shares
            // the user has made.
            if (userShares == 3  && !settings.picsforpetsGeneral.furtographer) {
              $('<div></div>')
                .load('/fb/pics-for-pets/ajax/thanks-for-sharing?sid=' + sid + ' #dosomething-picsforpets-general-thanks-form')
                .dialog({
                  title: Drupal.t('Thanks for sharing!'),
                  resizable: false,
                  draggable: false,
                  modal: true,
                  top: 180,
                  width: 550,
                  position: { my: 'top', at: 'top', of: 'body', offset: '0 180' },
                  open: function(event, ui) {
                    if (typeof FB != 'undefined') { 
                      FB.Canvas.scrollTo(0,0);
                    }
                  }
                }
              );
            }
            else if (userShares == 5) {
              $('<div class="invite-dialog"></div>')
                .load('/fb/pics-for-pets/ajax/invite-friends #dosomething-picsforpets-invite-form', function () {
                  $('.ui-dialog form').click(function() {
                    var obj = {
                      method: 'apprequests',
                      display: 'iframe',
                      title: "DoSomething.org's Pics for Pets",
                      message: 'You’ve been invited to help find shelter animals a new home with Pics for Pets. The more shares, the more food and toy donations the animals can get for their shelters. Help animals find a home!',
                      access_token: settings.picsforpetsFBAuth.access_token,
                      show_error: true
                    };
                    FB.ui(obj, function(response) {
                      $('div.invite-dialog').dialog('close');
                    });
                  });
                })
                .dialog({
                  title: Drupal.t('Hey, you\'ve shared 5 animals!'),
                  resizable: false,
                  draggable: false,
                  modal: true,
                  top: 180,
                  width: 550,
                  position: { my: 'top', at: 'top', of: 'body', offset: '0 180' },
                  open: function(event, ui) {
                    if (typeof FB != 'undefined') { 
                      FB.Canvas.scrollTo(0,0);
                    }
                  }
                });
            }
          });
        }
      });
    });
  }
};

})(jQuery);
