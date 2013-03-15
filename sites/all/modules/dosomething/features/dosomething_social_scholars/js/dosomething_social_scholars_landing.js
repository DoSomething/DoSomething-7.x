(function ($) {
  Drupal.behaviors.sas = {
    attach: function(context, settings) { 
      // styles the choose file button
      var f = jQuery('.form-file');
      $('<div>').attr('id', 'upload-cover').insertBefore('.form-file');
      f.appendTo('#upload-cover').addClass('new');
      var n = $('<div>').addClass('fakefile').text('Upload Picture').appendTo('#upload-cover');

      $('h1#page-title').wrap('<div class="background-image"></div>');

      $('#edit-submitted-field-share-your-own-image-und-0-upload').click(function() {
        var img = window.setInterval(function() {
          if ($('#edit-submitted-field-share-your-own-image-und-0-upload').val() != '') {
            window.clearInterval(img);
            $('[id^="webform-client-form-"]').submit();
          }
        });
      });

      var caption = window.setInterval(function() {
        if ($('#caption').length) {
          window.clearInterval(caption);

          $('.view-share-a-stat-gallery').addClass('view-campaign-gallery view-id-campaign_gallery');

          var block = $('<div></div>').addClass('buttons');
          var facebook = $('<a></a>').attr('href', 'http://facebook.com').html('<img src="/sites/all/modules/dosomething/features/dosomething_social_scholars/images/facebook.png" class="share-button" alt="Share on Facebook" />').click(function() {
            var img = $('.current img').attr('src');
            var nid = parseInt(document.location.pathname.replace('/sas-landing/', ''));
            Drupal.behaviors.fb.feed({
              'feed_document': 'http://www.dosomething.org/node/' + nid,
              'feed_title': 'I just shared a stat',
              'feed_picture': document.location.origin + img,
              'feed_caption': 'Caption',
              'feed_description': 'Description',
              'feed_require_login': true
            }, function(response) { });
            return false;
          });
          facebook.appendTo(block);
          //var twitter = $('<a></a>').attr('href', 'http://twitter.com').text('Twitter').click(function() {
          //  var img = $('.current img').attr('src');
          //  var url = 'https://twitter.com/intent/tweet?original_referer=' + encodeURIComponent(document.location.origin + img) + '&text=Thanks&tw_p=tweetbutton&url=google.com&via=dosomething';
          //  window.open(url, '_twitter', 'toolbar=no,location=no,directories=no,status=no, menubar=no,scrollbars=no,resizable=no,width=600,height=300');
          //  return false;
          //  //<a href="http://www.tumblr.com/share/photo?source=&caption=<?php echo urlencode(INSERT_CAPTION_HERE) ?>&clickthru=<?php echo urlencode(INSERT_CLICK_THRU_HERE) ?>" title="Share on Tumblr" style="display:inline-block; text-indent:-9999px; overflow:hidden; width:81px; height:20px; background:url('http://platform.tumblr.com/v1/share_1.png') top left no-repeat transparent;">Share on Tumblr</a>
          //});
          //twitter.appendTo(block);
          var tumblr = $('<a></a>').attr('href', 'http://tumblr.com').html('<img src="/sites/all/modules/dosomething/features/dosomething_social_scholars/images/tumblr.png" class="share-button" alt="Share on Tumblr" />').click(function() {
            var img = $('.current img').attr('src');
            window.open('http://www.tumblr.com/share/photo?source=' + encodeURIComponent(document.location.origin + img) + '&caption=Caption&clickthru=' + encodeURIComponent(document.location.href), '_tumblr', 'toolbar=no,location=no,directories=no,status=no, menubar=no,scrollbars=no,resizable=no,width=600,height=300');
            return false;
          });
          tumblr.appendTo(block);
          block.insertBefore($('#caption'));
        }
      });
    }
  };
})(jQuery);