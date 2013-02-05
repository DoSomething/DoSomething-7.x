(function($) {
	Drupal.behaviors.crazy = {
		handle_text_change: function(field, elm) {
			$('#' + field).data('val',  $('#' + field).val() ); // save value
			$('#' + field).change(function() { // works when input will be blured and the value was changed
			  // console.log('input value changed');
			  $('#' + elm).text($(this).val());
			});
			$('#' + field).keyup(function() { // works immediately when user press button inside of the input
			  if( $('#' + field).val() != $('#' + field).data('val') ){ // check if value changed
			      $('#' + field).data('val',  $('#' + field).val() ); // save new value
				  if ($('#' + field).val() != "") {
				  	if ($('#' + elm).css('visibility') != "visible") {
						$('#' + elm).css('visibility', 'visible');
					}
				  }
				  else {
					$('#' + elm).css('visibility', 'hidden');
				  }
			      $(this).change(); // simulate "change" event
			  }
			});
		},

		attach: function(context, settings) {
		  var o = this;
		  if ($('.image-preview img').length > 0) {
			  jQuery('.image-preview img').appendTo('.image-widget-data').css({
			  'margin-top': '-50px',
			  'margin-bottom': '0',
			    '-webkit-box-shadow': 'none',
			    '-moz-box-shadow': 'none',
			    'box-shadow': 'none',
			    'border': '0'
			  });
		  }
		  else if ($('#edit-submitted-field-crazy-crazy-picture-und-0-upload').length) {
        $('<div></div>').attr('class', 'upload-placeholder').text('Upload a picture and it will appear here').css({
          'text-align': 'center',
          'font-size': '30px',
          'font-weight': '600',
          'line-height': '1.2',
          'margin-top': '43%',
          'text-transform': 'uppercase',
        }).appendTo('.image-widget-data');
        $('#edit-actions').remove();
		  }

		  if ($('input[value="Submit"]').length > 0) {
		  	$('input[value="Submit"]').click(function() {
		  	   $(this).hide();
		  	});
		  }

		   if ($('.image-widget-data').length > 0) {
         var topText = $('<div></div>').attr('id', 'top_text');
         var bottomText = $('<div></div>').attr('id', 'bottom_text');

         this.handle_text_change('edit-submitted-field-crazy-top-text-und-0-value', 'top_text');
         this.handle_text_change('edit-submitted-field-crazy-bottom-text-und-0-value', 'bottom_text');

         $('.image-widget-data').append(topText);
         $('.image-widget-data').append(bottomText);
		   }

	       $('#edit-submitted-field-crazy-crazy-picture-und-0-upload').click(function() {
	      	  var img = window.setInterval(function() {
              if ($('#edit-submitted-field-crazy-crazy-picture-und-0-upload').val() != '') {
                window.clearInterval(img);
                // Crazy shit
                $('.upload-placeholder').remove();
                $('.image-widget-data').css('background', 'url(/sites/all/modules/dosomething/crazyshit/images/loading-img.gif) center center no-repeat');
                $('[id^="webform-client-form-"]').submit();
              }
	      	  });
	       });

		   if ($('#edit-submitted-field-crazy-crazy-picture-und-0-remove-button').length > 0) {
		 	 $('#edit-submitted-sbutton-button').hide();
		 	 $('#edit-submitted-field-crazy-crazy-picture-und-0-remove-button').appendTo('#edit-submitted-sbutton').val('Delete me');
         var i = window.setInterval(function() {
           if ($('.image-widget-data img').length == 0) {
             window.clearInterval(i);
             var s = window.setInterval(function() {
               if ($('#edit-submitted-sbutton-button').length > 0) {
                 window.clearInterval(s);
                 $('#edit-submitted-sbutton-button').click();
               }
             })
           }
		     });
		   }

		  // styles the choose file button
		  var f = jQuery('.form-file');
		  jQuery('<div>').attr('id', 'upload-cover').insertBefore('.form-file');
		  f.appendTo('#upload-cover').addClass('new');
		  var n = jQuery('<div>').addClass('fakefile').text('Upload Picture').appendTo('#upload-cover');
      
      // changes [back] behavior on form
      $('#edit-previous').click(function(a){
        a.preventDefault();
        window.location = '/crazy/submit';
      });
      
      // hide "meme text" divs if either is empty
      $('#edit-submit').click(function(b){

        if( $('#top_text').html() == "" ) {
          $('#top_text').remove();
        }

        if( $('#bottom_text').html() == "" ) {
          $('#bottom_text').remove();
        }
        
      });

		},
	};
})(jQuery);
