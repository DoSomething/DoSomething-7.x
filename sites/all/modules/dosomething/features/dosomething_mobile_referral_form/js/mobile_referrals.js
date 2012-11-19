jQuery(document).ready(function() {
	jQuery('#webform-component-referall-your-info, #webform-component-referral-friend-info').find('input[type="text"]').each(function() {
		var t = jQuery(this);
		var v = t.val();
		t.attr('placeholder', v);
		t.attr('value', '');
	});

	if (jQuery('#campaign-opt-in-help').length > 0) {
	  jQuery('#campaign-opt-in-help').dialog({
	    autoOpen: false,
	  }).css('padding-top', '10px').parent().css('background', 'white');
	  jQuery('#opt-in-help, #opt-in-help-mobile').click(function () {
	    jQuery('#campaign-opt-in-help').dialog('open');
	    return false;
	  });
	}
});



(function ($) {
  $.fn.extend({
    dsReferSubmit: function (url, name, cell) {
      delete Drupal.behaviors.dosomethingLoginRegister;
      
      var popupForm = $('#dosomething-login-register-popup-form');
      popupForm.find('input[name="cell"]').val(cell);
	  popupForm.find('input[name="first_name"]').val(name);

      popupForm.attr('action', '/user/registration?destination=' + url);
      popupForm.find('.already-member .sign-in-popup').attr('href', '/user?destination=' + url);
      $('#dosomething-login-login-popup-form').attr('action', '/user?destination=' + url);

      popupForm.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550
      });
    }
  });
})(jQuery);