var google = {
  name: 'Gmail',
  config: {
    'client_id': '1000659299351.apps.googleusercontent.com',
    'scope': 'https://www.google.com/m8/feeds',
    'immediate': true,
  },
  token: [],
  path: '',

  pull: function(token, path) {
    $.post('/contact-picker/service/google', { 'key': token }, function(response) {
       $('#loading').fadeOut('fast');
       $('#response').html(response).queue(function() {
         DS.ContactPicker.init_results();
       });
       //stretch_scraper();
    });
  },

  auth: function(path) {
    // @TODO: Make this suck less.
    google.path = path;

    gapi.auth.authorize(this.config);
    // The issue:
    // gapi.auth.authorize *does* have a callback function (see below)...
    // ...but it can only be called once within the same scope.  Otherwise nothing happens.
    // Instead, wait 1 second and call handle_tokens() to "mock" a callback function
    // This lets us ask people to login (with popup), but never see the popup again.
    setTimeout('google.handle_token()', 1000);
  },

  handle_token: function(token, path) {
    google.token = gapi.auth.getToken();

    if (google.token === null) {
      gapi.auth.authorize({
        'client_id': '1000659299351.apps.googleusercontent.com',
        'scope': 'https://www.google.com/m8/feeds',
        'immediate': false
      }, function() {
        google.token = gapi.auth.getToken();
        google.pull(google.token, path);
      });
    }
    else {
      this.token = google.token;
      google.pull(this.token, path);
    }
    return false;
  },
};