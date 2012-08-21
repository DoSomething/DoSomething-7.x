/*jslint devel: true, bitwise: false, undef: false, browser: true, continue: false, debug: false, eqeq: false, es5: false, type: false, evil: false, vars: false, forin: false, white: true, newcap: false, nomen: true, plusplus: false, regexp: true, sloppy: true */
/*globals $, jQuery, FB, TDFriendSelector */

var s;
jQuery(document).ready(function () {
	var selector1, selector2, logActivity, callbackFriendSelected, callbackFriendUnselected, callbackMaxSelection, callbackSubmit;

	FB.init({appId: '169271769874704', status: true, cookie: false, xfbml: false, oauth: true});

	// When a friend is selected, log their name and ID
	callbackFriendSelected = function(friendId) {
		var friend, name;
		friend = TDFriendSelector.getFriendById(friendId);
		name = friend.name;
		console.log('Selected ' + name + ' (ID: ' + friendId + ')');
	};

	// When a friend is deselected, log their name and ID
	callbackFriendUnselected = function(friendId) {
		var friend, name;
		friend = TDFriendSelector.getFriendById(friendId);
		name = friend.name;
		console.log('Unselected ' + name + ' (ID: ' + friendId + ')');
	};

	// When the maximum selection is reached, log a message
	callbackMaxSelection = function() {
		console.log('Selected the maximum number of friends');
	};

	// When the user clicks OK, log a message
	callbackSubmit = function(selectedFriendIds) {
		console.log('Clicked OK with the following friends selected: ' + selectedFriendIds.join(", "));
	};

  var selector1, selector2, logActivity, callbackFriendSelected, callbackFriendUnselected, callbackMaxSelection, callbackSubmit;
  // Initialise the Friend Selector with options that will apply to all instances
  TDFriendSelector.init({debug: true});
  // Create some Friend Selector instances
  selector2 = TDFriendSelector.newInstance({
    callbackFriendSelected   : callbackFriendSelected,
    callbackFriendUnselected : callbackFriendUnselected,
    callbackMaxSelection     : callbackMaxSelection,
    callbackSubmit           : callbackSubmit,
    maxSelection             : 1,
    friendsPerPage           : 5,
    autoDeselection          : true,
      callbackSubmit       : function(selectedFriendIds) {
        window.open('http://www.facebook.com/dialog/feed?app_id=169271769874704&display=popup&to=' + selectedFriendIds + '&description=Yay+Stuff&redirect_uri=http://localhost:8080/sites/all/modules/dosomething/features/robocalls/facebook_popup.php', 'FBP', 'width=500,height=350');
      }
  });
  s = selector2;

	FB.getLoginStatus(function(response) {
		if (response.authResponse) {
			console.log("Logged in.");
			jQuery('.robocalls-fb-find-friends-birthdays').click(function() {
				pop();
				return false;
			});
		} else {
			console.log("Logged out.");
			jQuery('.robocalls-fb-find-friends-birthdays').click(function() {
				dostuff();
				return false;
			});
		}
	});
});

function pop() {
	s.showFriendSelector();
	return false;
}