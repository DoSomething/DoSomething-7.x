// sidebar
jQuery.post(url_base + 'sidebar.php', function (data) {
  jQuery('.region-sidebar-first').html(data).show().removeClass('region-sidebar-first');
  jQuery('.contact_form-aside').append(sign_up_form);
});


function init_content() {
  var $window = jQuery(window);
  var $nav = jQuery('.webform');
  var $hole = jQuery('#cask');
  var $olive = jQuery('.webform .divider');
  var $pit = jQuery('.webform .divider span');
  var scrollLimitTop = 251;
  var scrollLimitBot = 3346;

  $window.scroll(function () {
    var st = $window.scrollTop();
    if (st > scrollLimitTop && st < scrollLimitBot) {
      $nav
        .css('position','fixed')
        .css('top','0px')
        .css('margin','0 0 0 0')
        .css('background','#231F20')
        .css('width','727px')
        .css('z-index','3')
        .css('padding-top','15px');
      $olive
        .css('border-top','2px solid white');
      $hole
        .css('padding-top','202px');
    }
    else if (st >= scrollLimitBot) {
      $nav
        .css('position', 'absolute')
        .css('top', 'auto')
        .css('bottom', '5px')
        .css('padding-top','0px');
      $pit
        .css('top','-15px');
      $hole
        .css('padding-top','0');
    }
    else {
      $nav
        .css('position', 'static')
        .css('padding-top','0px');
      $hole
        .css('padding-top','0');
    }
  });

  jQuery('.nav-aside a').click(function () {
    if (jQuery(this).attr('href').charAt(0) == '#') {
      jQuery('html,body').animate({scrollTop: jQuery(jQuery(this).attr('href')).offset().top-20});
      return false;
    }
  });

  jQuery('.faq h4').next('p').css('display','none');
  jQuery('.faq h4.activeFAQ').next('p').css('display','block');
  jQuery('.faq h4').click(function(){
    if(jQuery(this).hasClass('activeFAQ')){
      jQuery(this).removeClass().next('p').slideUp();
    }
    else{
      jQuery(this).addClass('activeFAQ');
      jQuery(this).siblings('h4').removeClass('activeFAQ');
      jQuery(this).next('p').slideToggle();
      jQuery(this).siblings().next('p').slideUp();      
    }
  });
  jQuery('.learn1').mouseover(function(){
    jQuery('.share-here1').css('display', 'block');
  }).mouseout(function(){
    jQuery('.share-here1').css('display', 'none');
  });
  jQuery('.learn2').mouseover(function(){
    jQuery('.share-here2').css('display', 'block');
  }).mouseout(function(){
    jQuery('.share-here2').css('display', 'none');
  });
  jQuery('.learn3').mouseover(function(){
    jQuery('.share-here3').css('display', 'block');
  }).mouseout(function(){
    jQuery('.share-here3').css('display', 'none');
  });
  init_scroller();
  init_social();
}

function init_scroller() {
  jQuery('.action-guide-picture:not(:first)').hide();
  jQuery('#thumb-wars-action-guide-nav li').click(function () {
    var index = jQuery(this).index() + 1;
    jQuery('.action-guide-picture').hide();
    jQuery('.action-guide-picture:nth-child('+index+')').fadeIn(1000);
    activeButton();
  });
  activeButton();

  jQuery('#action-guide-right').click(function () {
    var $current = jQuery('.action-guide-picture:visible').hide();
    $next = $current.next();
    if ($next.length === 0) $next = jQuery('.action-guide-picture:first');
    $next.fadeIn(1000);
    activeButton();
    return false;
  });

  jQuery('#action-guide-left').click(function () {
    var $current = jQuery('.action-guide-picture:visible').hide();
    $prev = $current.prev();
    if ($prev.length === 0) $prev = jQuery('.action-guide-picture:last');
    $prev.fadeIn(1000);
    activeButton();
    return false;
  });
}

function activeButton() {
  var index = jQuery('.action-guide-picture:visible').index('.action-guide-picture') + 1;
  jQuery('.action-guide-circle').removeClass('active');
  jQuery('.action-guide-circle:nth-child('+index+')').addClass('active');
}

function init_social() {
  var $shareTop = jQuery('#top-fb-share');
  var $share1 = jQuery('.share1 .social-f');
  var $share2 = jQuery('.share2 .social-f');
  var $share3 = jQuery('.share3 .social-f');

  $shareTop.click(function () {
    var fbObj = {
      method: 'feed',
      link: 'http://www.dosomething.org/thumbwars?rel=betaTop',
      picture: 'http://files.dosomething.org/files/styles/thumbnail/public/fb_thumbs_0.jpg',
      name: 'Thumb Wars',
      description: 'Save your friends from the dangers of texting and driving with thumb socks, and even win scholarship money! Click here to join Do Something\'s Thumb Wars now!'
    };
    FB.ui(fbObj);
    return false;
  });

  $share1.click(function () {
    return shareClick(1, 'Drivers under 20 years old are most likely to get into a distracted driving crash.');
  });
  $share2.click(function () {
    return shareClick(2, 'At 55 mph, sending or receiving a text can take a driver\'s eyes off the road for the length of an entire football field.');
  });
  $share3.click(function () {
    return shareClick(3, 'Texting drivers are 23 times more likely to get involved in a crash.');
  });
}

function shareClick(num, captionText) {
  var fbObj = {
    method: 'feed',
    link: 'http://www.dosomething.org/thumbwars?rel=betaShare'+num,
    picture: 'http://files.dosomething.org/files/styles/thumbnail/public/fb_thumbs_0.jpg',
    name: 'Thumb Wars',
    caption: captionText,
    description: 'Save your friends from the dangers of texting and driving with thumb socks, and even win scholarship money! Click here to join Do Something\'s Thumb Wars now!'
  };
  FB.ui(fbObj);
  return false;
}

