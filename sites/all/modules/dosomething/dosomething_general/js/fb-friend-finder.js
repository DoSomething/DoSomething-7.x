(function ($) {
  Drupal.friendFinder = function (attach, permission, callback, options, auto_click) {
    asked_permission = false;

    var to = window.setInterval(function () {
      if (typeof FB != 'undefined') {
        window.clearInterval(to);
        build_selector();
        ffInit();
      }
    }, 5);

    function build_selector() {
      var selector_title, selector_desc;
      if (typeof options !== 'undefined') {
        selector_title = options.selector_title || Drupal.t('Share with your friends');
        selector_desc = options.selector_desc || '';
      }
      else {
        selector_title = Drupal.t('Share with your friends');
        selector_desc = '';
      }

      var raw = "<div id=\"TDFriendSelector\"><div class=\"TDFriendSelector_dialog\"><a href=\"#\" id=\"TDFriendSelector_buttonClose\">x<\/a><div class=\"TDFriendSelector_form\"><div class=\"TDFriendSelector_header\"><p>" + selector_title + "<\/p><\/div><div class=\"TDFriendSelector_content\"><p id=\"TDFriendSelector_head_desc\">" + selector_desc + "</p><div class=\"TDFriendSelector_searchContainer TDFriendSelector_clearfix\"><div class=\"TDFriendSelector_selectedCountContainer\"><span class=\"TDFriendSelector_selectedCount\">0<\/span> \/ <span class=\"TDFriendSelector_selectedCountMax\">0<\/span> friends selected<\/div><input type=\"text\" placeholder=\"Search friends\" id=\"TDFriendSelector_searchField\" \/><\/div><div class=\"TDFriendSelector_friendsContainer\"><\/div><\/div><div class=\"TDFriendSelector_footer TDFriendSelector_clearfix\"><a href=\"#\" id=\"TDFriendSelector_pagePrev\" class=\"TDFriendSelector_disabled\">Previous<\/a><a href=\"#\" id=\"TDFriendSelector_pageNext\">Next<\/a><div class=\"TDFriendSelector_pageNumberContainer\">Page <span id=\"TDFriendSelector_pageNumber\">1<\/span> \/ <span id=\"TDFriendSelector_pageNumberTotal\">1<\/span><\/div><a href=\"#\" id=\"TDFriendSelector_buttonOK\">OK<\/a><\/div><\/div><\/div><\/div>";
      $('body').append($(raw));
    }

    function ffInit() {
      FB.getLoginStatus(function(response) {
        if(response.status == 'connected') {
          FB.api('/me/permissions', parsePermissions);
        }
      });
    }

    function parsePermissions(response) {
      var has_perm = permission in response.data[0];
      if (has_perm) {
        attachClick(attach, callback);
      }
      else {
        if (typeof Drupal.behaviors.fb == 'undefined') {
          attach.click(function (e) {
            e.preventDefault();
              FB.ui({
                method: 'permissions.request',
                perms: permission,
                display: 'dialog'
              }, function() {
                attachClick(attach, callback);
              });
          });

        	if (auto_click) {
        	  attach.click();
        	}
        }
        else {
          attachClick(attach, callback);
        }
      }
    }

    function attachClick(attach, callback) {
      TDFriendSelector.init({
        speed : 0
      });
      var friendSelector = TDFriendSelector.newInstance({
        callbackSubmit : callback,
        maxSelection   : (typeof options !== 'undefined' ? options.max_friends : 10),
        friendsPerPage : 7,
        autoDeselection: true,
        callbackCancel: function() {
          if (jQuery('#fb-modal').length > 0) {
            jQuery('#fb-modal').remove();
          }
        },
      });

      Drupal.friendFinder.instance = friendSelector;

      attach.click(function (e) {
        e.preventDefault();
        friendSelector.showFriendSelector();
      });

      if (auto_click) {
      	attach.click();
      }
    }
  };

  Drupal.friendFinder.clear_friends = function() {
    if (typeof Drupal.friendFinder.instance !== 'undefined') {
      Drupal.friendFinder.instance.reset();
      Drupal.behaviors.fb.receivers = {};
    }
  };
}(jQuery));
