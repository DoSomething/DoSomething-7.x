var google = {
  name: 'Gmail',
  config: {
    'client_id': '1000659299351.apps.googleusercontent.com',
    'scope': 'https://www.google.com/m8/feeds'
  },
  token: [],

  pull: function(token, path) {
    $.post('/' + path + '/gapi.php', { 'do': 'blah', 'key': token }, function(response) {
       $('#response').slideDown().html(response);
       $('#check-area, #send-emails').fadeIn('fast');
       $('#loading').fadeOut('fast');
       prepare_clicks();
    });
  },

  auth: function(path) {
    gapi.auth.authorize(this.config, function() {
      var t = gapi.auth.getToken();
      console.log('Login complete');
      console.log(t);
      this.token = t;

      google.pull(this.token, path);
    });
  },
}