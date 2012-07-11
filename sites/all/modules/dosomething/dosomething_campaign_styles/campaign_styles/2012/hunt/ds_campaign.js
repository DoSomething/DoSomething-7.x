// Hunt, Hunt, Hunt, Hunt.
// jQuery! Get some.
(function ($) {
  $(document).ready(function() {

    // move webform fields into containing fieldset
    // #webform-component-tabs
    $("#edit-submitted-field-leader-info,#edit-submitted-field-team-name,#webform-component-derp,#edit-submitted-field-team-invite").appendTo("#webform-component-create-or-join > .fieldset-wrapper");
  
    // hide sunglass address fieldset & show if opt-in is checked
    $("#webform-component-address-holder").hide(); 

    $("#edit-submitted-yes-1").change(function () {
      if ($("#edit-submitted-yes-1").is(':checked')) {
        $("#webform-component-address-holder").slideToggle();
      }
      else {
        $("#webform-component-address-holder").slideToggle();        
      }
    });

    // create & join functionality
    // show:join
    $("#join_team").click(function(){
      // CSS >> display:none; to current div
      $("#edit-submitted-field-team-name").css("display","none");
      $("#edit-submitted-field-team-invite").css("display","none");
      $("#webform-component-derp").css("display","none");
      $("#edit-submitted-field-leader-info").css("display","block");
        // CSS >> highlight current active tab
        $("a#join_team > h2").removeClass("inactive");
        $("a#create_team > h2").addClass("inactive");
          return false
    });
  
    // show:create
    $("#create_team").click(function(){
      // CSS >> display:none; to current div
      $("#edit-submitted-field-leader-info").css("display","none");
      $("#edit-submitted-field-team-name").css("display","block");
      $("#edit-submitted-field-team-invite").css("display","block");
      $("#webform-component-derp").css("display","block");
        // CSS >> highlight current active tab
        $("a#create_team > h2").removeClass("inactive");
        $("a#join_team > h2").addClass("inactive");
          return false
     });
   
     // challenges!
     // determine current time
     var today = new Date();
     var day = today.getDate();
     var hour = today.getHours();
     var minute = today.getMinutes();
   
     // eq() offset = slice() + 1
   
    if(hour < 11){
      var eqNo = 11;
      var sliceNo =  10;
    }
    else if(hour >= 11){
      if(minute < 11) {
      }
      else if(minute >= 11){
        var eqNo = 10;
        var sliceNo = 9;
      }
    }

    // hide challenges
    $("#challenges_open ul").css("display","none");

    // gate functionality before the 10th at 11:11
    // activate available challenges
    $("#challenges_open h3").slice(0, (day - sliceNo)).click(function(){
     $(this).next("ul").slideToggle();
     $(this).siblings().next("ul").slideUp();
    });

    // add "today" to current challenge && color all other active challenges    
    $("#challenges_open h3:eq(" + (day - eqNo) + ")").append("<strong>[ today's challenge ]</strong>");
    $("#challenges_open h3 > span").slice(0, (day - sliceNo)).css("color","#D32A1B");
    $("#challenges_open h3").slice(0, (day - sliceNo)).css("cursor","pointer");

    // show current challenge
    $("#challenges_open ul:eq(" + (day - eqNo) + ")").css("display","block");

    // remove future challenges from DOM
    $("#challenges_open ul").slice((day - sliceNo), 11).remove();
  });
})(jQuery);
