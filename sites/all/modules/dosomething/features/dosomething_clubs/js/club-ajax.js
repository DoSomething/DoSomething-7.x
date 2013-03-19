(function($) {
  Drupal.behaviors.clubAjax = {
    attach: function(context, settings) {
      var $members = $('.pane-club-members:not(.club-processed)').addClass('club-processed');
      $members.hide();
      $members.find('form').hide();

      $('.blurb-wrapper a').click(function() {
        if (!$(this).hasClass('done')) {
          $(this).data('current-text', $(this).parent().parent().find('textarea').val());
          $(this).text('Done');
          $(this).addClass('done');
          $(this).parent().parent().addClass('editing');
        }
        else {
          var elm = $(this);
          var v = $(this).parent().parent().find('textarea').val();
          if ($(this).data('current-text') != v) {
            $.post('/club/edit-blurb/727244', { 'text': v }, function(response) {
              var res = $.parseJSON(response);
              if (!res.error) {
                elm.removeClass('done');
                elm.text('Edit');
                $('.blurb-wrapper').removeClass('editing');
                $('.blurb-placeholder').text(v);
              }
            });
          }
          else {
            elm.removeClass('done');
            elm.text('Edit');
            $('.blurb-wrapper').removeClass('editing');
            $('.blurb-placeholder').html(v);
          }
        }
        return false;
      });

      var memberclick = false;
      $('a.member-change-owner:not(.club-processed)').addClass('club-processed').click(function() {
        if (memberclick) {
          return false;
        }
        memberclick = true;

        var disclaimer = '';
        if ($(this).hasClass('to-user-from-admin')) {
          disclaimer = 'You will no longer be the leader, but you will retain administrator rights.';
        }
        else if ($(this).hasClass('to-user')) {
          disclaimer = 'The previous leader will still retain administration rights.'
        }

        if (confirm('Are you SURE you want to change the leader of this club? ' + disclaimer)) {
          var h = $(this).parent().find('.member-change-owner').attr('href');
          var components = h.split('/');
          var nid = components[4];
          var uid = components[5];

          var elm = $(this);
          var loading_msg = "Updating club leader.  This page will refresh when complete.  Please wait... <img src='/sites/all/modules/dosomething/features/dosomething_clubs/images/ajax-loader.gif' alt='' style='margin-left: 5px;' />";

          var tr = elm.parent().parent().find('.response-box');
          if (tr.html().indexOf('Please wait...') == -1) {
            tr.append(loading_msg);
          }

          $.post('/club_admin/change-owner/js/' + nid + '/' + uid, { }, function(response) {
            if (response) {
              memberclick = false;
              $(this).removeClass('.club-processed');
              $('.club-owner-label').remove();
              $('<div class="club-owner-label"><em>Club Leader</em></div>').insertAfter(elm.parent().parent().find('h2'));
              window.location.href = window.location.href;
            }
          });
          return false;
        }
        else {
          memberclick = false;
          $(this).removeClass('.club-processed');
        }

        return false;
      });

      $('.jcarousel-container a').attr('target', '_blank');

      $('.club-image, #club-edit-logo').click(function() {
        if (!$('.club-image').hasClass('admin-manage')) {
          return false;
        }

        var id = $('#club-edit-logo').attr('class');

        $logo = $('<div></div>').attr('id', 'edit-logo-modal');
        $logo.load('/clubs/edit-logo/' + id, function() {
          $logo.dialog({
            resizable: false,
            draggable: false,
            modal: true,
            width: 550,
            dialogClass: 'club-edit-logo'
          });

          $('#edit-upload-button').click(function() {
            $('.loading').show();
          });
        });
        return false;
      });

      $('#clubs-share-on-facebook').click(function() {
        window.open($(this).attr('href'), 'FBShare', 'width=500,height=300,toolbar=no,scrollbars=no,status=no,resizeable=no,menubar=no,location=no');
        return false;
      });

      $('.member-popup-trigger:not(.club-processed)').addClass('club-processed').click(function () {
        $members.dialog({
          resizable: false,
          draggable: false,
          modal: true,
          width: 650,
          height: 500
        });
        return false;
      });
      $('.member-delete:not(.club-processed)').addClass('club-processed').click(function () {
        var $form = $(this).parents('tr').find('form.club-member-delete');
        $form.toggle();
        if ($form.is(':visible')) {
          $(this).text('close');
        }
        else {
          $(this).text('Delete member');
        }
        return false;
      });
      $('.member-title-update:not(.club-processed)').addClass('club-processed').click(function () {
        var $form = $(this).parents('tr').find('form.club-title-update');
        $form.toggle();
        if ($form.is(':visible')) {
          $(this).text('close');
        }
        else {
          $(this).text('Update title');
        }
        return false;
      });
    }
  }
}(jQuery));

(function ($) {
  $.fn.extend({
    dsClubsSubmit: function (url) {
      delete Drupal.behaviors.dosomethingLoginRegister;
      
      if (!url) {
        var u = window.location.href.replace('http://', '');
        url = u.substr(u.indexOf('/')+1, u.length);
      }

      var popupForm = $('#dosomething-login-register-popup-form');
      var hash2 = ($('#register-benefits').length);
      if (!hash2) {
        popupForm.find('#edit-title-text label').after('<h2 id="register-benefits">Just Sign Up and you\'ll be able to join this club.</h2>');
      }

      popupForm.attr('action', '/user/registration?destination=' + url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination=' + url);
      $('#dosomething-login-login-popup-form').attr('action', '/user?destination=' + url);

      popupForm.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550
      });

      return false;
    }
  });
})(jQuery);
