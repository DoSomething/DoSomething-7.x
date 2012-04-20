<div class="twtr-widget twtr-widget-profile" id="twtr-widget-1">

  <?php foreach ($tweets as $tweet): ?>
    <div class="twtr-tweet">
      <div class="twtr-tweet-wrap">
        <div class="twtr-avatar">
          <div class="twtr-img">
            <a href="http://twitter.com/intent/user/<?php print $tweet['user']['screen_name'] ?>" target="_blank">
              <img src="<?php print$tweet['user']['profile_image_url'] ?>"/>
            </a>
          </div>
        </div>
        <div class="twtr-tweet-text">
          <p>
            <a class="twtr-user" href="http://twitter.com/intent/user?screen_name=<?php print $tweet['user']['screen_name'] ?>" target="_blank"><?php print $tweet['user']['screen_name'] ?></a>
            <?php print $tweet['text'] ?>
            <em>
              <?php print $tweet['date'] ?> · 
              <a target="_blank" class="twtr-reply" href="http://twitter.com/intent/tweet?in_reply_to= <?php print $tweet['id'] ?> ">reply</a> · 
              <a target="_blank" class="twtr-rt" href="http://twitter.com/intent/retweet?tweet_id= <?php print $tweet['id'] ?> ">retweet</a> · 
             <a target="_blank" class="twtr-fav" href="http://twitter.com/intent/favorite?tweet_id= <?php print $tweet['id'] ?> ">favorite</a>
          </em>
          </p>
        </div>
      </div>
    </div>
  <?php endforeach; ?>

</div>
