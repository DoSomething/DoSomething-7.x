var yahoo = {
  name: 'Yahoo! Mail',

  auth: function() {
    $.post('/contact-picker/service/yahoo', {}, function(response) {
      var res = '';
      if (response.indexOf('{') !== -1) {
        res = $.parseJSON(response);
      }

  	  if (typeof res == 'object' && res.state == 0) {
  	    window.open('/contact-picker/service/yahoo', 'yahoo', 'width=500,height=350,scrollbars=no,resizeable=no,location=no,status=no,titlebar=no,toolbar=no');
  	  }
  	  else {
	      yahoo.pull(response);
  	  }
    });
  },

  pull: function(data) {
    DS.ContactPicker.load_data(data);
  }
}