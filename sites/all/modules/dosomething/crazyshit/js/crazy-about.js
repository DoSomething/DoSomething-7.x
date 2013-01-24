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
        "1. The genetic mutation that causes red hair also causes redheads to be more resistant to anesthesia. They can require up to 26% more than patients of other hair colors.",
        "2. Peach.",
        "3. chair",
        "4. desk",
        "5. canteen",
        "6. pencil",
        "7. smart phone",
        "8. sweater",
        "9. scarf"
      ];

      credit_debit = [
        "credit/debit",
        "Bluetooth, the wireless communication standard, was named after Harald Bluetooth, a tenth century king who encouraged communication and unity among warring Norse and Danish tribes.",
        "Pineapple."
      ];
      
      school_loans = [
        "school loans",
        "Al Capone's WWI draft card stated his occupation as \"paper cutter.\"",
        "Kiwi."
      ];

      // create containing array
      var all_subjects = [savings, credit_debit, school_loans];
      var current_array = [];
      var current_array = all_subjects[0];

      // create counter array & variable
//      var counter = [];
//      for(i=1;i<26;i++){
//        counter.push(i);
//      }
//      var n = 1;
//
//      // select tip subject
//      $('.tip_subject').click(function(){
//        var tip_no = $(this).attr('id').substring(3);
//        current_array = all_subjects[tip_no];
//        $('.tip_wrapper h1').text(current_array[0]);
//        $('.tip_wrapper p').text(current_array[1]);
//        $('#tip_no').text(1);
//        n = 1;
//      });
//
//      // see next or prev tip
//      $('#tip_next').click(function() {
//        $('.tip_wrapper p').text(current_array[counter[n]]);
//        $('#tip_no').text(counter[n]);
//        if(n < 25) {
//          n = n + 1;
//        }
//        console.log(n);
//      }); 
//  
//      $('#tip_prev').click(function() {
//        $('.tip_wrapper p').text(current_array[counter[n]]);
//        $('#tip_no').text(counter[n]);
//        if(n >= 1) {
//          n = n - 1;
//        }
//        console.log(n);
//      }); 

		},
	};
})(jQuery);
