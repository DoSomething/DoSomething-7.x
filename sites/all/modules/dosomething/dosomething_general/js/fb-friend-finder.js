(function ($) {
  Drupal.behaviors.friendSelector = {
    attach: function (context, settings) {
      // is this shitty? yup
      // does it work?   yup
      var raw="<div id=\"TDFriendSelector\"><div class=\"TDFriendSelector_dialog\"><a href=\"#\" id=\"TDFriendSelector_buttonClose\">x<\/a><div class=\"TDFriendSelector_form\"><div class=\"TDFriendSelector_header\"><p>Select your friends<\/p><\/div><div class=\"TDFriendSelector_content\"><div class=\"TDFriendSelector_searchContainer TDFriendSelector_clearfix\"><div class=\"TDFriendSelector_selectedCountContainer\"><span class=\"TDFriendSelector_selectedCount\">0<\/span> \/ <span class=\"TDFriendSelector_selectedCountMax\">0<\/span> friends selected<\/div><input type=\"text\" placeholder=\"Search friends\" id=\"TDFriendSelector_searchField\" \/><\/div><div class=\"TDFriendSelector_friendsContainer\"><\/div><\/div><div class=\"TDFriendSelector_footer TDFriendSelector_clearfix\"><a href=\"#\" id=\"TDFriendSelector_pagePrev\" class=\"TDFriendSelector_disabled\">Previous<\/a><a href=\"#\" id=\"TDFriendSelector_pageNext\">Next<\/a><div class=\"TDFriendSelector_pageNumberContainer\">Page <span id=\"TDFriendSelector_pageNumber\">1<\/span> \/ <span id=\"TDFriendSelector_pageNumberTotal\">1<\/span><\/div><a href=\"#\" id=\"TDFriendSelector_buttonOK\">OK<\/a><\/div><\/div><\/div><\/div>";
      $('body').append($(raw));
    }
  };
  Drupal.friendFinder = function (attach, permission, callback, auto_click) {
    var to = window.setInterval(function () {
      if (typeof FB != 'undefined') {
        window.clearInterval(to);
        ffInit();
      }
    }, 5);

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
        attach.click(function (e) {
          e.preventDefault();
          FB.login(function(authResponse) {
            attachClick(attach, callback);
          }, {scope: permission});
        });

      	if (auto_click) {
      	  attach.click();
      	}
      }
    }

    function attachClick(attach, callback) {
      TDFriendSelector.init({
        speed : 0
      });
      var friendSelector = TDFriendSelector.newInstance({
        callbackSubmit : callback,
        maxSelection   : 5,
        friendsPerPage : 7,
        autoDeselection: true,
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
