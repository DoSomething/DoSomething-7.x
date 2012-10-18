(function($) {

Drupal.behaviors.dsPfpShare = {
  adjectives: $('meta[property=cpj]').attr('content'),
  pname: $('meta[property=cpn]').attr('content'),
  pimg: $('.field-name-field-fb-app-image img').attr('src'),

  attach: function (context, settings) {

    // Retrieve the id of this webform submission.
    if (settings.fbappsAnimals.images == undefined) {
      var sid = settings.fbappsAnimals.sid;
    }
    else {
      var sid = settings.fbappsAnimals.images[settings.fbappsAnimals.index].sid;
    }

    // Grab some metadata.
    var pictureUrl = $('.field-name-field-fb-app-image img').attr('src');
    var petName = $('.hi-pet-name p').text();

    // Use the 'feed' method because it allows us to post metadata.
    var shareUrl = settings.picsforpetsFBAuth.app_secure_url + '/submit-pet-picture/submission/' + sid;

    $('#picsforpets-share').click(function () {
      if ($(this).hasClass('shared')) return;
      else {
        $(this).addClass('shared');
      }

      FB.getLoginStatus(function(response) {
        if (response.status == 'unknown') {
          // Not logged in.
          FB.login(function(response) {
            if (response.authResponse) {
              Drupal.behaviors.dsPfpShare.submit_share(sid, settings);
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
          Drupal.behaviors.dsPfpShare.submit_share(sid, settings);
        }
      });
    });
  },

  submit_share: function(sid, settings) {
    var pname = Drupal.behaviors.dsPfpShare.pname;
    var adjectives = Drupal.behaviors.dsPfpShare.adjectives;
    var pimg = Drupal.behaviors.dsPfpShare.pimg;
    var shareUrl = settings.picsforpetsFBAuth.app_secure_url + '/submit-pet-picture/submission/' + sid;

    var threeWords = [];
    jQuery.each($('.field-name-field-fb-app-three-words .field-items').children(), function() {
      threeWords.push($(this).text());
    });

    // Old share
    var share = {
      method: 'feed',
      name: pname + ' is homeless and needs a bed.',//'I need a home.  Click here to share me and help me find one.',
      link: shareUrl,
      picture: pimg,
      caption: 'With 1,000 shares Do Something will send one to ' + pname + "'s shelter.",//"Hi, I'm " + pname + ". I'm " + threeWords[0] + ", " + threeWords[1] + ", and " + threeWords[2],
      description: "Click the pic to share!"
    };

    // Fixed 10/18 by using Facebook Connections (see below)
    // Possible fix for lack-of-permission problem
    //FB.api('/me/permissions', function (response) {
    //  var perms = response.data[0];
    //  if (!perms.publish_actions) {
    //    FB.ui({
    //    method: 'permissions.request',
    //    perms: 'publish_actions',
    //    display: 'popup'
    //    }, function(response) {
    //      // Just making sure that they have this permission.
    //    });
    //  }
    //});

    //FB.api(
    // '/me/dosomethingapp:share',
    //  'post',
    //  {
    //      pet_who_needs_a_home: document.location.href,
    //      pet_name: pname,
    //      pet_adjectives: adjectives,
    //      image: pimg
    //  },
    //FB.ui(share,
     /*       og_namespace         (The namespace of the app to use.)
     *       og_type              (The open graph object to use.)
     *       og_action            (The open graph action to use.)
     *       og_post_image        (An (optional) image to be sent with the Open Graph call.)
     *       og_post_description  (The description that appears under the caption)
     *       og_selector          (A selector on the page to call the event on)
     *       og_allow_multiple    (Uses the TD Friend Selector to allow multiple friends to be posted-to)
     *       og_require_login     (Initializes the login procedure if a user is not logged in.)
     *       og_fake_dialog       (Whether or not to use the "Fake" dialog that lets users post message with the share)
     *       og_post_custom       (Custom variables as set on the user interface.)*/
      var conf = Drupal.behaviors.dsPfpShare.create_ograph_config();
      Drupal.behaviors.fb.ograph(conf, function(response) {
        if ((typeof response !== 'undefined') && (response !== null) && !response.error) {
          // Use FB's JS SDK to retrieve and store the user's facebook id.
          var fbuid = FB.getUserID();

          $('.fb-share-me').text('Shared!');
          // Make POST request to this URL to update the share count on the
          // webform submission, passing in the webform submission id and the
          // user's facebook id as URL arguments.
          $.post('/fb/pics-for-pets/share/js/' + sid + '/' + fbuid, function (userShares) {
            // Increment the displayed share count.
            var count = $('.picsforpets-share-count').text();
            count++;
            $('.picsforpets-share-count').text(count);
            var titles = {
              200  : '200 shares gets me a toy!',
              500  : '500 shares gets me food!',
              1000 : '1000 Shares gets me a bed!'
            };

            for (i in titles) {
              if (count < i) {
                $('#picsforpets-share').find('h1').html(titles[i]);
                break;
              }
            }

            // Display a modal dialog depending on the total number of shares
            // the user has made.
            if (userShares == 1 && !settings.picsforpetsGeneral.furtographer) {
              $loader = $('<div></div>');
              $loader.load('/fb/pics-for-pets/ajax/thanks-for-sharing?sid=' + sid + ' #dosomething-picsforpets-general-thanks-form', function() {
                if ($('html').hasClass('ie9') || $('html').hasClass('ie8') || $('html').hasClass('ie7') || $('html').hasClass('ie6')) {
                  $cellval = $loader.find('#edit-cell')
                  $emailval = $loader.find('#edit-email');
                  $cellval.val('Cell:');
                  $emailval.val('Email:');
                  $cellval.focus(function() {
                    if ($(this).val() == 'Cell:') {
                      $(this).val('');
                    }
                  });
                  $emailval.focus(function() {
                    if ($(this).val() == 'Email:') {
                      $(this).val('');
                    }
                  });
                  $cellval.blur(function() {
                    if ($(this).val() == '') {
                      $(this).val('Cell:');
                    }
                  });
                  $emailval.blur(function() {
                    if ($(this).val() == '') {
                      $(this).val('Email:');
                    }
                  });
                }
              });
              $loader.find('#edit-cell').val('cell');
              $loader.dialog({
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
                });
            }
            else if (userShares == 3) {
              $inviteDialog = $('<div class="invite-modal"></div>');
              $inviteDialog.load('/fb/pics-for-pets/ajax/invite-friends #dosomething-picsforpets-invite-form', function() {
                  $('#picsforpets-invite-friends').click(function() {
                    // We don't actually care what they click after they get
                    // into the invite friends FB dialog. So if they click the
                    // button we'll close the dialog no matter what.
                    $inviteDialog.dialog('close');
                    FB.ui({
                      method: 'apprequests',
                      display: 'iframe',
                      title: "DoSomething.org's Pics for Pets",
                      message: 'You’ve been invited to help find shelter animals a new home with Pics for Pets. The more shares, the more food and toy donations the animals can get for their shelters. Help animals find a home!',
                      access_token: settings.picsforpetsFBAuth.access_token,
                      show_error: true
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
                }
              );
            }
          });

          setTimeout('jQuery(".slideshow-next").click();', 1000);
        }
    });
  },

  create_ograph_config: function() {
    var c = {
        og_namespace: 'dosomethingapp',
        og_type: 'pet_who_needs_a_home',
        og_action: 'share',
        og_post_description: '4 million animals are killed each year because can\'t find a home.  Click SHARE NOW to share this animal.',
        og_post_image: $('meta[property="og:image"]').attr('content'),
        og_title: $('meta[property="og:title"]').attr('content'),
        og_fake_dialog: 0,
        og_require_login: 1
      };

      Drupal.behaviors.fb.log(c);

    return c;
  },

  update_attrs: function(image, name, adjectives) {
    this.pname = name;
    this.pimg = image;
    this.adjectives = adjectives;
  }
};

}(jQuery));