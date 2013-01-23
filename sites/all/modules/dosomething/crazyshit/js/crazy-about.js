(function($) {
	Drupal.behaviors.crazy_about = {
		attach: function(context, settings) {
    
    // create three arrays to hold content
    var savings = []; 
    var credit_debit = []; 
    var school_loans = []; 

    // define array content
    savings = [
      "savings",
      "The genetic mutation that causes red hair also causes redheads to be more resistant to anesthesia. They can require up to 26% more than patients of other hair colors.",
      "Peach."
    ]

    credit_debit = [
      "credit/debit",
      "Bluetooth, the wireless communication standard, was named after Harald Bluetooth, a tenth century king who encouraged communication and unity among warring Norse and Danish tribes.",
      "Pineapple."
    ]
    
    school_loans = [
      "school loans",
      "Al Capone's WWI draft card stated his occupation as \"paper cutter.\"",
      "Kiwi."
    ]

    // create containing array
    var all_subjects = [savings, credit_debit, school_loans];

    // select tip section
    var current_array = all_subjects[0];

    $('.tip_subject').click(function(){
      var tip_no = $(this).attr('id').substring(3);
      var current_array = [];
      current_array = all_subjects[tip_no];
    });

    $('#tip_wrapper h1').text(current_array[0]);
    $('#tip_wrapper p').text(current_array[1]);

    for(n=1;n<=25;){
      $('#tip_next').click(function() {
        n++;
        $('#tip_wrapper p').text(current_array[n]);
      }); 
      $('#tip_prev').click(function() {
        n--;
        $('#tip_wrapper p').text(current_array[n]);
      }); 
      $('#tip_no').text(n);
    }

		},
	};
})(jQuery);
