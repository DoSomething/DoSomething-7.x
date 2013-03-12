var yahoo = {
  name: 'Yahoo! Mail',

  auth: function() {
    $.post('/contact-picker/service/yahoo', {}, function(response) {
  	  if (typeof response == 'object' && response.state == 0) {
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