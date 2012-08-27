(function ($) {
  Drupal.behaviors.campaignName = {
    attach: function (context, settings) {

// Top Head Graphic   
  var banner = $('<img />').attr('src', 'http://files.dosomething.org/files/campaigns/vote/vote-head2.jpg').css({'width': '750px', 'max-width': 'none'}).hide();
    $('div.panel-campaign:not(.vote-head)').addClass('vote-head').prepend(banner);
  banner.fadeIn();

// FAQ
$('.faq h4').next('p').css('display','none');
$('.faq h4.activeFAQ').next('p').css('display','block');
$('.faq h4').click(function(){
  if($(this).hasClass('activeFAQ')){
    $(this).removeClass().next('p').slideUp();
  }
  else{
    $(this).addClass('activeFAQ');
    $(this).siblings('h4').removeClass('activeFAQ');
    $(this).next('p').slideToggle();
    $(this).siblings().next('p').slideUp(); 
  }
});
    }
  };
})(jQuery);