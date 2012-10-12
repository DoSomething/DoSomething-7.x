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
      };
      FB.getLoginStatus(function(response) {
        if (response.status == 'unknown') {
          // Not logged in.
          FB.login(function(response) {
            if (response.authResponse) {
              obj.access_token = response.authResponse.accessToken
              FB.ui(obj);
            }
          });
        }
        else if (response.status == 'not_authorized') {
          FB.api('/me/permissions', function (response) {
            var perms = response.data[0];
            if (!perms.publish_actions) {
              FB.ui({
              method: 'permissions.request',
              perms: 'publish_actions',
              display: 'popup'
              }, function(response) {
                // Just making sure that they have this permission.
              });
            }
          });
        }
        else {
          FB.ui(obj);
        }
      });
    });   
  }       
};        
          
Drupal.behaviors.galleryShareButton = {
  share_url: '',
  pet_name: '',

  attach: function (context, settings) {
    $('.gallery-share-button').click(function () {
      if ($(this).hasClass('shared')) return;
      else {
        $(this).addClass('shared');
      }
     
      var sid = parseInt($(this).parent().attr('id'));

      Drupal.behaviors.galleryShareButton.pet_name = $(this).text();

      var item = this;
      FB.getLoginStatus(function(response) {
        if (response.status == 'unknown') {
          // Not logged in.
          FB.login(function(response) {
            if (response.authResponse) {
              Drupal.behaviors.galleryShareButton.submit_share(sid, item, settings);
            }
          });
        }
        else if (response.status == 'not_authorized') {
          FB.api('/me/permissions', function (response) {
            var perms = response.data[0];
            if (!perms.publish_actions) {
              FB.ui({
              method: 'permissions.request',
              perms: 'publish_actions',
              display: 'popup'
              }, function(response) {
                // Just making sure that they have this permission.
              });
            }
          });
        }
        else {
          Drupal.behaviors.galleryShareButton.submit_share(sid, item, settings);
        }
      });
    });
  },

  submit_share: function(sid, elm, settings) {
       var shareUrl = settings.picsforpetsFBAuth.app_secure_url + '/' + settings.picsforpetsFBAuth.fbFormAlias + '/submission/' + sid;
      var threeWords = [];
      threeWords[0] = 0 in settings.dosomething_picsforpets_general.gallery[sid].threeWords ? settings.dosomething_picsforpets_general.gallery[sid].threeWords[0].raw.safe_value : "Fun";
      threeWords[1] = 1 in settings.dosomething_picsforpets_general.gallery[sid].threeWords ? settings.dosomething_picsforpets_general.gallery[sid].threeWords[1].raw.safe_value : "Cute";
      threeWords[2] = 2 in settings.dosomething_picsforpets_general.gallery[sid].threeWords ? settings.dosomething_picsforpets_general.gallery[sid].threeWords[2].raw.safe_value : "Friendly";


      // Old share
    var share = {
        method: 'feed',
        name: settings.dosomething_picsforpets_general.gallery[sid].petName + ' is homeless and needs a bed.',//'I need a home.  Click here to share me and help me find one.',
        link: shareUrl,
        picture: settings.picsforpetsFBAuth.appBaseURL + '/' + settings.dosomething_picsforpets_general.gallery[sid].pictureUrl,
        caption: 'With 1,000 shares Do Something will send one to ' + settings.dosomething_picsforpets_general.gallery[sid].petName + "'s shelter.",//"Hi.  I'm " + settings.dosomething_picsforpets_general.gallery[sid].petName + ". I'm " + threeWords[0] + ", " + threeWords[1] + ", and " + threeWords[2],
        description: "Click the pic to share"//"Help me find this shelter animal a home.  Click here to share this animal."
      };

    // Possible fix for lack-of-permission problem.
    FB.api('/me/permissions', function (response) {
      var perms = response.data[0];
      if (!perms.publish_actions) {
        FB.ui({
        method: 'permissions.request',
        perms: 'publish_actions',
        display: 'popup'
        }, function(response) {
          // Just making sure that they have this permission.
        });
      }
    });

    FB.api(
        '/me/dosomethingapp:share',
        'post',     
        {         
            pet_who_needs_a_home: shareUrl,
            image: settings.picsforpetsFBAuth.appBaseURL + '/' + settings.dosomething_picsforpets_general.gallery[sid].pictureUrl,
        },  
    //FB.ui(share,  
      function(response) {
        if (typeof console !== 'undefined' && window.console) {
          console.log(response);
        }
        if ((typeof response !== 'undefined') && (response !== null)) {
          // Use FB's JS SDK to retrieve and store the user's facebook id.
          var fbuid = FB.getUserID();

          $(elm).text('Shared!');
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
            if (userShares == 1  && !settings.picsforpetsGeneral.furtographer) {
              $('<div></div>')
                .load('/fb/pics-for-pets/ajax/thanks-for-sharing?sid=' + sid + ' #dosomething-picsforpets-general-thanks-form')
                .dialog({
                  title: Drupal.t('Thanks for sharing!'),
                  resizable: false,
                  draggable: false,
                  modal: true,
                  top: 180,
                  width: 550,
                  dialogClass: 'pics-thx-for-sharing',
                  position: { my: 'top', at: 'top', of: 'body', offset: '0 180' },
                  open: function(event, ui) {
                    if (typeof FB != 'undefined') { 
                      FB.Canvas.scrollTo(0,0);
                    }
                  }
                }
              );
            }
            else if (userShares == 3) {
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
                  title: Drupal.t('Hey, you\'ve shared 3 animals!'),
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
      }, true
    );
  }
};

})(jQuery);
