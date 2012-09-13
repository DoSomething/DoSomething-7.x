var google = {
  name: 'Google',
  config: {
    'client_id': '1000659299351.apps.googleusercontent.com',
    'scope': 'https://www.google.com/m8/feeds'
  },
  token: [],

  pull: function(token) {
    $.post('/sites/all/modules/dosomething/dosomething_contact_picker/gapi.php', { 'do': 'blah', 'key': token }, function(response) {
       $('#response').slideDown().html(response);
       $('#check-area, #send-emails').fadeIn('fast');
       $('#loading').fadeOut('fast');
       prepare_clicks();
    });
  },

  auth: function() {
    $('#loading').show().html('<p style="text-align: center"><img src="/sites/all/modules/dosomething/dosomething_contact_picker/images/loading.gif" alt="" /> Loading.  Please wait...</p>');
    gapi.auth.authorize(this.config, function() {
      var t = gapi.auth.getToken();
      console.log('Login complete');
      console.log(t);
      this.token = t;

      google.pull(this.token);
    });
  },
}