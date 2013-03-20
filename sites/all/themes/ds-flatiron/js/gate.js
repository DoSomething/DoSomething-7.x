(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

    // create new HTML elements
    var reg_header  = '<div id="reg_header"><img class="ds_logo" src="//files.dosomething.org/files/campaigns/beta/logo.png" alt="DoSomething.org logo"/><h1>Peanut Butter & Jam Slam<img class="bang" src="//files.dosomething.org/files/campaigns/beta/bang.png" alt="exclamation point"/></h1><h2><strong>1 out of 6</strong> Americans goes hungry every year. Sign up to change this.</h2></div>'
    var reg_leftcol = '<div id="reg_leftcol"><h1>how it works</h1><h2>Donate 10 jars of peanut butter, jam or any other food and help end hunger in your community.</h2></div>'
    var reg_footer  = '<div id="reg_footer"><p>Clicking "Finish" won\'t sell your soul, but it means you agree to our <a href="/about/terms-of-service">terms of service</a> &amp; <a href="/about/privacy">privacy policy</a> &amp; to receive our weekly update.</p></div>'
    var form_header = '<img class="form_header" src="//files.dosomething.org/files/campaigns/beta/form_header.png" alt="sign up"/>'

    // add new elements to DOM
    $("#dosomething-login-register-popup-form").prepend(form_header).parent(".content").prepend(reg_header, reg_leftcol).append(reg_footer);

    }
  };

  Drupal.behaviors.dosomethingLoginLogin = {
  attach: function (context, settings) {
    var loginForm = $('#dosomething-login-login-popup-form--2').hide();
    $('.sign-in-popup').click(function (event) {
      loginForm.dialog({
        resizable: false,
        draggable: false,
        modal: true,
        width: 550,
      });
      event.preventDefault();
    });
  }
};
})(jQuery);
