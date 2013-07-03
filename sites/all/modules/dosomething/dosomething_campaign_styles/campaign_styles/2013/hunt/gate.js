(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

    // Create new HTML elements
    var reg_header  = '<div id="reg_header"><img class="ds_logo" src="//files.dosomething.org/files/campaigns/beta/logo.png" alt="DoSomething.org logo"/><img class="hunt-logo" src="http://www.dosomething.org/files/campaigns/hunt13/header2.png" alt="hunt logo"/></h1><h2>PREPARE FOR 11 DAYS OF 11 KICK ASS WAYS TO MAKE CHANGE IN YOUR COMMUNITY</h2></div>'
    var reg_leftcol = '<div id="reg_leftcol"><h1>how it works</h1><h2>We\'ll give you 11 actions over 11 days to help you show the world the kick ass things you can do.</h2></div>'
    var reg_footer  = '<div id="reg_footer"><p>Clicking "Finish" won\'t sell your soul, but it means you agree to our <a href="/about/terms-of-service">terms of service</a> &amp; <a href="/about/privacy">privacy policy</a> &amp; to receive our weekly update.</p></div>'
    var form_header = '<img class="form_header" src="//files.dosomething.org/files/campaigns/beta/form_header.png" alt="sign up"/>'

    // Add new elements to DOM
    $("#dosomething-login-register-popup-form").prepend(form_header).parent(".content").prepend(reg_header, reg_leftcol).append(reg_footer);

    }
  };
})(jQuery);
