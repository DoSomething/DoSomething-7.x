// hunt hunt hunt hunt
// drupal jQuery initialization
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
  });
})(jQuery);