<?php

// Whether or not to allow notifications.
$allow_notifications = true;

// The relative URI to the campaign.  Don't include a leading slash.
$crazy_root = 'crazy';
if (!defined('CRAZY_ROOT')) define('CRAZY_ROOT', $crazy_root);

// Pages where users can get notifications.
// This follows a regular expression syntax.
// If you don't know what that means, don't change this.
$crazy_notification_pages = array(
	'crazy',
	'crazy/([0-9]+)',
	'crazy/time-(today|week)',
	'crazy/friends'
);

// The first image can't be lazy loaded because it causes issues when you create a new post.
// Increase this number to turn off lazy loading for more images.
// THIS SHOULD ALWAYS BE AT LEAST 1
$lazy_load_count = 1;

// Allow lazy loading? 1 = yes, 0 = no
$allow_lazy_loading = 1;

// Campaign title
$campaign_title = "The Craziest Thing I Did to Save Money";

// Top menu links.
$top_links = array(
	'crazy(/(time-.*?|[0-9]+))?$' => array(
		'title' => 'Gallery',
		'href' => CRAZY_ROOT,
	),
	'crazy/friends' => array(
		'title' => 'Friends',
		'href' => CRAZY_ROOT . '/friends',
		'attributes' => array(
			'onclick' => "return fb_auth('login', " . $fbed . ")",
		),
	),
	'crazy/about' => array(
		'title' => 'About',
		'href' => CRAZY_ROOT . '/about',
		'parent' => '/about',
	),
	'crazy/submit' => array(
		'title' => 'Submit',
		'href' => CRAZY_ROOT . '/submit/start',
		'parent' => '/submit',
		'attributes' => array(
			'onclick' => "return fb_auth('submit', " . $fbed . ")",
		),
	),
);

// Sub menus
$sub_menus = array(
	// Time based filters sub-menu (landing page)
	'crazy(/(time-.*?|[0-9]+))?$' => array(
		'today' => array(
			'title' => 'Today',
			'href' => CRAZY_ROOT . '/time-today',
		),
		'week' => array(
			'title' => 'This Week',
			'href' => CRAZY_ROOT . '/time-week',
		),
		'forever' => array(
			'title' => 'All Time',
			'href' => CRAZY_ROOT,
		),
	),
	// About pages sub-menu
	'crazy/about' => array(
		'tips' => array(
			'title' => 'Tips',
			'href' => CRAZY_ROOT . '/about#tips'
		),
		'scholarship' => array(
			'title' => 'Scholarship',
			'href' => CRAZY_ROOT . '/about#scholarship',
		),
/* hidden until PSA released */
/*		'video' => array(
			'title' => 'Video',
			'href' => CRAZY_ROOT . '/about#video'
    ), */
	),
);

// Submit form
$submit_form = array(
	// Submit form steps
	'steps' => array(
		'step1' => 'Step 1 of 2: Select a picture to upload.',
		'step2' => 'Step 2 of 2: Add text (optional)',
	),
);

/** 
  * An array of arrays indicating the page(s) you want CSS to show up on.
  * The sub-array should be a list of CSS files.
  *
  * Sub-sections are counted.  For example: "crazy/about" will match crazy/about/tips
  * and "crazy" by itself will match everything.
  *
  * All CSS will be loaded from /sites/all/modules/dosomething/crazyshit/css in the order
  * that they are listed below.
  */
$crazy_css = array(
	'crazy' => array(
		'crazy.css'
	),
	'crazy/about' => array(
		'crazy-about.css',
	),
	'crazy/submit' => array(
		'crazy-form.css',
	),
);

/** 
  * An array of arrays indicating the page(s) you want JS to show up on.
  * The sub-array should be a list of JS files.
  *
  * Sub-sections are counted.  For example: "crazy/about" will match crazy/about/tips
  * and "crazy" by itself will match everything.
  *
  * All javascript will be loaded from /sites/all/modules/dosomething/crazyshit/js in the order
  * that they are listed below.
  */
$crazy_js = array(
	'crazy' => array(
		'crazy.js',
	),
	'crazy/submit' => array(
		'crazy-form.js',
	),
	'crazy/about' => array(
		'crazy-about.js',
	),
);

// Money saving tips
$money_saving_tips = array(
	// Savings
    "Establish a savings habit and stick to it. Commit to paying yourself first every time money comes into your possession.",
    "Track even the smallest expenses, as numerous $5 purchases can add up to a lot of money.",
    "Avoid buying on impulse. Wait at least a week before making pricey purchases to ensure you really want the item.",
    "Pack a lunch instead of eating out. Saving a few dollars at each meal will add up in the long run, helping you to buy other items you crave.",
    "Before opening a checking account, consider the services you need. Seek a free checking account that doesn't require a minimum balance or charge you for each check written.",
    "Use your own bank's ATM. Many banks charge a fee to use an ATM that doesn't belong to your bank.",

	// Credit/Debt
    "Save now to spend later. Rather than buying a big-ticket item on credit, save up to make the purchase so you can avoid interest charges.",
    "Avoid using credit cards to make purchases, as people spend up to 30 percent more when using them.",
    "Familiarize yourself with credit card interest rates. A pair of $50 jeans can become expensive if you are paying 20 percent interest.",
    "Pay your credit card in full each month. It will help you avoid expensive interest charges.",
    "Pay your credit card on time, even if you can't pay the balance in full. This will help you build a good credit score.",
    "Don't go over your credit card limit, as you will incur additional fees.",

	// School Loans
    "Looking for a loan for school? Complete the Free Application for Student Aid (FAFSA) to determine the programs you qualify for, including grants and low-interest federal loans.",
    "What's in your best interest? A \"fixed\" interest rate will not change. But a \"variable\" interest rate can be raised over time &emdash; often multiple times during the life of a loan. Explore your options before committing to a loan.",
    "Planning to save on interest charges by paying the loan off early? Before you borrow, determine if there are early repayment penalties. Some tricky lenders charge a fee for paying in advance, so they can recoup the loss of interest.",
    "If your lender offers a discount on fees or interest rates for your federal loan, find out if the discount will remain if your loan is sold. This can happen many times in the life of your loan, so you want to be sure you retain these benefits in the long-term.",
    "If you are offered a good rate on a private loan, get the full offer in writing along with any terms or restrictions, then reach out to other lenders to see if they will beat the rate or offer.",

    // Tips from mobile game
    "Sign up for every free custom rewards program you can.  Regardless of how often you shop there, having a rewards card for that place will eventually net you some coupons and sweet discounts.",
    "Make your own gifts instead of buying stuff from the store.  You can make food mixes, candles, personalized picture frames and a variety of other things for little to no cost.  Plus, it comes from the heart.  #win.",
    "Become a 30-day master.  Whenever you're considering purchasing something that you want rather than need, wait thirty days and then ask yourself if you still want that item.",
    "Make a shopping list before you leav ethe house.  If you go into the store knowing exactly what you need, chances are you'll cut out any unnecessary purchases.  Easy money.",
    "Invite friends over instead of going out.  Most activities can be done at home for far cheaper than if you went out.  Get ready to dust off those board games!",
    "Turn off the lights before you leave.  Spend the extra minute to turn off all the lights in your house when you leave.  Think about the lightswitch as a cash damn - the more switches you turn off, the more money you keep.",
    "Install CFL or LED bulbs wherever you can.  They may cost more up front, but they save you energy costs in the long run.  CFL's tend to save about 25% of the electricity of an incandescent, and LEDs use a measly 2%.",
    "Clean your car's air filter.  A clean air filter can improve your gas mileage by up to 7%, saving you more than $100 for every 10,000 miles you drive in an average vehicle.",
    "Don't spend money just to de-stress.  Instead, do a physical activity, or take time doing something else you enjoy.  You'll end up saving money and feeling a lot better.",
	"Keep your hands clean. Wash your hands a few times a day, especially after using the bathroom or handling raw foods. You'll keep yourself healthier, saving money on medical bills and loss of productivity.",
	"Do holiday shopping right after the holidays. A lot of retailers cut prices right after holidays, saving you tons of cash by buying during a light shopping time.",
	"Try generic brands of items you buy regularly. Instead of just picking up the ordinary brand of an item you buy, try out the store brand or generic version of the item. Generic brands tend to be cheaper and, many times, just as good.",
	"Prepare some meals at home. Get a good cook book and start making meals you can bring with you to school or work. You’ll save money on takeout, and you’ll most likely eat healthier too (which means you'll actually know what is going into your food).",
	"Wait 10 seconds before buying something. Whenever you are shopping, pick up the item you are thinking about buying and see if you truly need it. This can stop you from making impulse buys.",
 	"Create a visual reminder of your debt. Make it into something way more fun than debt. If you make a progress bar of your debt, you can start to fill it up each week as you pay it off. It'll help you stay on track and feel accomplished when you do it.",
	"Check out what's going on at your local park or rec center. Many towns have tons of free parks, basketball and tennis courts, disc golf, trails, and tons of other cool stuff that you can enjoy without paying a dime.",
	"Air up your tires. For every two PSI (pounds per square inch, or amount of air in your tires) that all of your tires are below the recommended level, you lose 1% on your gas mileage. That's money right out the window! Check out your owner’s manual for the recommended PSI.",
	"Take public transportation. If the city's transit system is available near you, use it. It's far cheaper than driving a car and you don’t have to worry about parking or gas.",
	"Carpool. Going the same place as a friend, schoolmate or coworker? Carpool! You'll save money on gas and maintenance, and you'll get free conversation.",
	"Have a bike? Ride it! If you can rely on a bike for any of your day-to-day traveling, you can save money and get some exercise. It’s even cheaper than public transportation which can cost up to $105 per month, depending on the city.",
	"Pack food before you go on a road trip. You'll save money and most likely eat healthier.",
	"Libraries are cool again. They offer more than old books. You can get tons of free stuff, like magazines, CDs, DVDs, and even games.",
	"Always ask for fees to be waived. When you register for a service of any kind and there are sign-up fees, ask for them to be waived. You'll be surprised by how often they are waived.",
	"Eat less meat. For the nutritional value, meat is expensive when compared to vegetables and fruits. Add more fruits, vegetables and grains to your diet and you'll eat healthier while saving money.",
	"Set your thermostat at 68, year round. In the winter, you'll save money on heat, and in the summer, you'll save money on A/C This can save you hundreds of dollars a year on heating and cooling costs.",
	"Buy Clothes on Sale. If you buy clothes out of season, you can save tons of dough just by buying what isn't currently in demand. A pair of jeans or a sweater can quickly end up on the clearance rack in off months, and save you up to 75%.",
	"Buy non-perishable items in bulk. Many items are cheaper when purchased in large quantities. Obviously, you want to stay away from things that will spoil (basically, don't buy milk in bulk), but it's a gold mine for things like pasta and toilet paper.",
	"Brew coffee at home. You can often brew a cup of coffee at home for more than half the price that you can buy it at coffee chains. That $2 you save a day quickly adds up to a ton of beans.",
	"Reduce Paper Towel Usage. Instead of spending money on paper towels, get a few microfiber towels. They grab dirt like a pro and you can wash them and reuse them over and over.",
	"Use rewards credit cards. If you use a credit card and pay the full balance each month, make sure to get one that gives you cash back or other rewards. It's like getting free money, especially if you are avoiding interest charges.",
);

// Facebook aggregation messages
// Note: Do NOT use the t() function here.
// Use !n (exclamation-point, lowercase "N") for the number.
$fb_messages = array(
	#'vouch' => '!n people have vouched for you! Good for you!',
	#'bs' => '!n people called BS on your submission.  Boooo...',
	'notification' => '!n people have rated your story on ' . $campaign_title . '.  Go to app to find out what they said!',
);

// Facebook posts
$facebook_posts = array(
	// Vouch request
	'posts' => array(
		'title' => t('The Craziest Thing I Did to Save Money'),
		'caption' => '',
		'description' => t('I just told the story about the craziest thing I did to save money, and I need your help to vouch for me.  No one believes me, click here to support!'),
	),
	// Invite from friends page.
	'invite' => array(
		'document' => 'http://www.dosomething.org/' . CRAZY_ROOT,
		'title' => t('The Craziest Thing I Did to Save Money'),
		'caption' => '',
		'description' => t('I never told anyone this before, but this one time I did this crazy thing to save money..'),
		'image' => 'http://files.dosomething.org/files/campaigns/crazy13/logo.png',
	),
	// Share a particular post.
	'share' => array(
		'namespace' => 'dosomethingapp',
		'object' => 'crazy_thing',
		'action' => 'share',
		//'message' => t('I just posted the craziest thing I did to save money.  Now it\'s your turn! Go here to do so.'),   # Ignored -- we can't force a message on a user.
	),
);

/********************************
 *	Don't edit below this line  *
 ********************************/


// Batch limit.  Probably better if this is left alone.
$batch_limit = 50;

if (!defined('CRAZY_LAZY_LOAD_COUNT')) define('CRAZY_LAZY_LOAD_COUNT', $lazy_load_count);
if (!defined('CRAZY_ALLOW_NOTIFICATIONS')) define('CRAZY_ALLOW_NOTIFICATIONS', $allow_notifications);
if (!defined('CRAZY_ALLOW_LAZY_LOADING')) define('CRAZY_ALLOW_LAZY_LOADING', $allow_lazy_loading);
