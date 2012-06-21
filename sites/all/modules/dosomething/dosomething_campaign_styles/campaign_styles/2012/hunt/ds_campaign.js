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
     
     // // challenges!
     // // determine current time
     // var today = new Date(); // specify time zone
     // var day = today.getDate();
     // var hour = today.getHours();
     // var testDate = 4
     // 
     // // holy challenges, batman!
     // $("#challenges div").css("display","none"); // on production hide in CSS
     // 
     // // activate available challenges
     // $("h3").slice(0, (day - 14)).click(function(){
     //   $(this).next("div").slideToggle();
     //   $(this).siblings().next("div").slideUp();
     // });
     // 
     // // add "today" to current challenge && color all other active challenges    
     // $("#challenges h3:eq(" + (day - 16) + ")").append("<strong>[ today's challenge ]</strong>");
     // $("h3 > span").slice(0, (day - 14)).css("color","#D32A1B");
     // $("h3").slice(0, (day - 14)).css("cursor","pointer");
     // 
     // // show current challenge
     // $("#challenges div:eq(" + (day - 16) + ")").css("display","block");
     // 
     // // remove future challenges from DOM
     // $("#challenges div").slice((day - 15), 11).remove(); 
  });
})(jQuery);