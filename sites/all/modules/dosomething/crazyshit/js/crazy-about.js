(function($) {
	Drupal.behaviors.crazy_about = {
		attach: function(context, settings) {
    
      // create three arrays to hold content
      var savings = []; 
      var credit_debt = []; 
      var school_loans = []; 

      // define array content
      
      savings = [
        "savings",
        "Save one-third of any money you receive to create a cushion for your future. Use a visual tool like a piggy bank or money jar to help reinforce saving habits.",
        "Be prepared for emergencies. Start a fund to cover at least six months of bills such as car insurance, cell phone, gas and food.",
        "Establish a savings habit and stick to it. Commit to paying yourself first every time money comes into your possession.",
        "Going on spring break? Create a travel budget so you come back from vacation with happiness and some sun, rather than regret.",
        "Create a budget and stick to it, ensuring your expenses do not exceed your income. Track even the smallest expenses, as numerous $5 purchases can add up to a lot of money.",
        "Avoid buying on impulse. Wait at least a week before making pricey purchases to ensure you really want the item.",
        "Pack a lunch instead of eating out. Saving a few dollars at each meal will add up in the long run, helping you to buy other items you crave.",
        "Check your account balance at least once per week. You will be less likely to write a check for money you don't have available.",
        "Secure information on fees that your bank may charge when you open a checking account, such as overdraft fees. These fees can add up quickly and become very costly, particularly if you bounce a check.",
        "Ask your financial institution about overdraft protection. This service can help you avoid costly fees.",
        "Before opening a checking account, consider the services you need. Seek a free checking account that doesn't require a minimum balance or charge you for each check written.",
        "Don't bounce your checks. Overdrawing your account will cause you to rack up big fees and further hurt a delicate financial situation.",
        "Use your own bank's ATM. Many banks charge a fee to use an ATM that doesn't belong to your bank.",
        "Review your bank statement every month. It will help you catch mistakes and keep track of any fees.",
        "Last one!"
      ];

      credit_debt = [
        "credit/debt",
        "Check for annual fees, now and in the future. Even your card starts without a fee, the credit card company may add one on later.",
        "Set your own credit card limit to avoid over-charging, which will result in pricey interest charges.",
        "Determine the default interest rate, which is what you will be charged if you do not pay the minimum payment on time. These interest rates are typically very high, some times 35 percent or more.",
        "Save now to spend later. Rather than buying a big-ticket item on credit, save up to make the purchase so you can avoid interest charges.",
        "Avoid using credit cards to make purchases, as people spend up to 30 percent more when using them.",
        "Before choosing a credit card, compare each card's terms and conditions, including the interest rate, default rate, annual fees and payment schedule.",
        "Beware of introductory \"zero percent interest\" rates. When the initial time frame rate is over, the interest rate will swell and so will your balance.",
        "Familiarize yourself with credit card interest rates. A pair of $50 jeans can become expensive if you are paying 20 percent interest.",
        "Pay your credit card in full each month. It will help you avoid expensive interest charges.",
        "Pay your credit card on time, even if you can't pay the balance in full. This will help you build a good credit score.",
        "Don't go over your credit card limit, as you will incur additional fees.",
        "Establish a good credit score by paying all bills and loans on time. Higher credit scores will help you secure better interest rates and card perks.",
        "Check your monthly credit card statement at the middle and end of the month. This will help you stay on top of unexpected charges or fees.",
        "Don't use a credit card as a way to borrow money. There are better options with less expensive interest rates, such as a small loan from a credit union.",
        "Last one!"
      ];

      school_loans = [
        "school loans",
        "Learn the difference between federal and private (or \"alternative\") loans, as the interest rates and repayment terms are very different. Taking out private loans can be expensive and risky.",
        "Looking for a loan for school? Complete the Free Application for Student Aid (FAFSA) to determine the programs you qualify for, including grants and low-interest federal loans.",
        "Before consulting a private lender, explore all of your federal sources.",
        "Take out federal loans first, as the interest rates don't change over time and aren't impacted by your credit score. Federal loans are the safest loans and come with some guaranteed borrower protections in the event you have financial challenges after college.",
        "The safest and most affordable federal loans are Perkins and Subsidized Stafford loans. Interest rates are fixed and the government pays the interest while you are in school.",
        "At the start of each quarter or semester, do an assessment of your loans. Keep track of the lender, balance and repayment status. Missing just one payment can result in an interest spike or other costly consequences.",
        "After Perkins and Subsidized Stafford loans, the next best option is an Unsubsidized Stafford Loan. Though you accrue interest while in school, you don't have to start making payments until six months following graduation - and you still get federal borrower protections.",
        "Think of private or \"alternative\" loans like credit cards. Even if interest rates are low to start, they can be raised at any time. You also don't have the same protection as you do with federal loans.",
        "Borrower beware! Interest rates for private or \"alternative\" loans can be so high, you might end up paying more in interest than you borrowed in the first place.",
        "Beware of alternative loans! Some schools put their own name on private loans, or the loans may have other brand names that make them look safer than they really are. Lenders often offer both federal and private loans, so make sure you know what you're getting before you sign on the dotted line.",
        "What's in your best interest? A \"fixed\" interest rate will not change. But a \"variable\" interest rate can be raised over time &emdash; often multiple times during the life of a loan. Explore your options before committing to a loan.",
        "Planning to save on interest charges by paying the loan off early? Before you borrow, determine if there are early repayment penalties. Some tricky lenders charge a fee for paying in advance, so they can recoup the loss of interest.",
        "If your lender offers a discount on fees or interest rates for your federal loan, find out if the discount will remain if your loan is sold. This can happen many times in the life of your loan, so you want to be sure you retain these benefits in the long-term.",
        "If you are offered a good rate on a private loan, get the full offer in writing along with any terms or restrictions, then reach out to other lenders to see if they will beat the rate or offer.",
        "Last one!"
      ];
      
      // create containing array
      var all_subjects = [savings, credit_debt, school_loans];
      var current_array = [];
      var current_array = all_subjects[0];

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
          if (old_num < 15) {
            var new_num = parseFloat(old_num) + 1;
          }
        }
        else {
          if (old_num > 1) {
            var new_num = parseFloat(old_num) - 1;
          }
        }

        // some CSS to hide and show [prev] and [next]
        var ghost_button = {
          'visibility' : 'hidden'
        }

        var blue_button = {
          'visibility' : 'visible'
        }

        // cache variables
        var $tip_prev = $('#tip_prev');
        var $tip_next = $('#tip_next');

        // hide [prev] if no previous tips exist
        if (new_num == 1) {
          $tip_prev.css(ghost_button);
        }

        // show [prev] if previously hidden
        if (new_num == 2) {
          $tip_prev.css(blue_button);
        }

        // hide [next] if no more tips exist
        if (new_num == 15) {
          $tip_next.css(ghost_button);
        }

        // show [next] if previously hidden
        if (new_num == 14) {
          $tip_next.css(blue_button);
        }

        $('.tip_wrapper p').text(current_array[new_num]);
        $('#tip_no').text(new_num);

        e.preventDefault();
      });

      function add_remove_flat(class_name) {
        $this
          .addClass('justClicked')
          .parent()
          .children()
          .removeClass(class_name);
        $('.justClicked').removeClass('justClicked').addClass(class_name);
      }

      function add_remove_nested(class_name) { 
        $this
          .addClass(class_name)
          .parent()
          .siblings()
          .children()
          .removeClass(class_name);
      }

      function switch_active(target, class_name, is_nested) {
        $(target).click(function() {
          $this = $(this);
          if ($this.not(class_name)) { 
            if(is_nested) { 
              add_remove_nested(class_name);
            }
            else { 
              add_remove_flat(class_name);
            }
          }
        });            
      }

      // active class hack on submenu
      $('.crazy-sub-menu .1 a, .crazy-sub-menu .2 a').removeClass('active');

      // active class switching on /about subject menu and /about sub-menu
      switch_active('.tip_subject', 'active_subject');
      switch_active('.crazy-sub-menu li a', 'active', true);

      // animate scroll to fragment identifier
      function smooth_scroll(targets) {
        $(targets).click(function(event) {
          $('html,body').animate({scrollTop: $(event.target.hash).offset().top}, 'slow');  
          event.preventDefault();
        });
      }

      smooth_scroll('.crazy-sub-menu li a');

		},
	};
})(jQuery);
