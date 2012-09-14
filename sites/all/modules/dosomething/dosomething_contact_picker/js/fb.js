$(document).ready(function() {
  $('#petition-fb').click(function () {
    window.parent.close_scraper();
    window.parent.launch_fb_share();
  });
});