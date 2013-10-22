// Generated by CoffeeScript 1.6.3
// Backported from Neue with minor modifications for compatability with jQuery 1.4.


(function() {
  var $, bindResetButton, findLocation;

  $ = jQuery;

  window.initializeLocationFinder = function() {
    $(".no-js-feature-warning").hide();
    $(".no-js-hide-feature").show();
    $(".js-location-finder-results").hide();
    $(".js-location-finder-button").click(function(e) {
      e.preventDefault();
      return findLocation();
    });
    return $(".js-location-finder-form").submit(function(e) {
      e.preventDefault();
      return findLocation();
    });
  };

  findLocation = function() {
    var zip;
    $(".js-location-finder-button").addClass("loading");
    zip = $(".js-location-finder-input").val();

    $.ajaxSetup({
      error: function(xhr, status, error) {
        $(".js-location-finder-results").html("<div class='alert error'>We had trouble talking to the server. Check that your internet connection is working, or try reloading the page.");
        $(".js-location-finder-form").slideUp(400);
        return $(".js-location-finder-results").slideDown(400);
      }
    })


    if (zip.match(/^\d{5}$/)) {
      return $.get('http://lofialcoa.herokuapp.com/?zip='+zip+'&radius=100', function(data) {
        $(".js-location-finder-results-zip").text(zip);
        $(".js-location-finder-results .location-list").html("");
        $.each(data, function(index, value) {
          return $(".js-location-finder-results .location-list").append("<li>\n  <strong>" + value.name + "</strong><br>\n  " + value.address + ", " + value.city + ", " + value.state + " " + value.zip + "<br>\n"+ value.phone + "\n</li>");
        });
        $(".js-location-finder-form").slideUp(400);
        $(".js-location-finder-results").slideDown(400);
        return bindResetButton();
      });
    } else {
      $(".js-location-finder-button").removeClass("loading");
      $(".js-location-finder-alert-container").html("<div class='alert error'>Slow down buddy, that's not a zip code.</div>").slideDown(400);
        return $(".js-location-finder-input").bind("propertychange input keyup", function() {
          $(".js-location-finder-alert-container").slideUp(400);
      });
    }
  };

  bindResetButton = function() {
    return $(".js-location-finder-reset").click(function(e) {
      e.preventDefault();
      $(".js-location-finder-results").slideUp(400);
      $(".js-location-finder-form").slideDown(400);
      $(".js-location-finder-results .location-list").html("");
      return $(".js-location-finder-button").removeClass("loading");
    });
  };

}).call(this);