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
      var counter = [];
      for(i=1;i<26;i++){
        counter.push(i);
      }

      // select tip subject
      $('.tip_subject').click(function(e){
        var tip_no = $(this).attr('id').substring(3);
        current_array = all_subjects[tip_no];
        $('.tip_wrapper h1').text(current_array[0]);
        $('.tip_wrapper p').text(current_array[1]);
        $('#tip_no').text(1);
        e.preventDefault();
      });

      // increment or decrement tip num.
      $('.small_button').click(function(e){
        var $small_button = $(this);
        var $tip_num = $('#tip_no');
        var old_num = $tip_num.text();

        if ($small_button.attr('id') == 'tip_next') {
          if (old_num < 25) {
            var new_num = parseFloat(old_num) + 1;
          }
        }
        else {
          if (old_num > 1) {
            var new_num = parseFloat(old_num) - 1;
          }
        }

        $('.tip_wrapper p').text(current_array[counter[new_num - 1]]);
        $('#tip_no').text(new_num);

        e.preventDefault();
      });

      // active class hack on submenu
      $('.crazy-sub-menu .0 a, .crazy-sub-menu .2 a').removeClass('active');
      $('.crazy-sub-menu li a').click(function() {
        var $this = $(this);
        if ($this.hasClass('active')) {
          $this.removeClass();
        }
        else {
          $this
            .addClass('active')
            .parent()
            .siblings('li')
            .children()
            .removeClass('active');
        }
      });

		},
	};
})(jQuery);
