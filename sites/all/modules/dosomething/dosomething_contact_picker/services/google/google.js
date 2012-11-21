var google = {
  name: 'Gmail',
  config: {
    'client_id': '1000659299351.apps.googleusercontent.com',
    'scope': 'https://www.google.com/m8/feeds',
    'immediate': true
  },
  token: [],

  pull: function(token, path) {
    jQuery.post('/' + path + '/gapi.php', { 'do': 'blah', 'key': token }, function(response) {
       jQuery('#response').html(response).css('overflow', 'auto');
       jQuery('#check-area, #send-emails, #submit-emails-block').fadeIn('fast');
       jQuery('#loading').fadeOut('fast');
       stretch_scraper();
       prepare_clicks();
    });
  },

  auth: function(path) {
    gapi.auth.authorize(this.config, function(r) {
      var t = gapi.auth.getToken();
      //console.log('Login complete');
      //console.log(t);
      this.token = t;

      google.pull(this.token, path);
    });
    return false;
  },
}