<?php

/**
 * @file
 * Node template file for the Project content type.
 *
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div role="main" class="wrapper">
    <section class="header" id="header">
      <h1 class="header-logotype">Logo</h1>
      <p class="header-date">
        June 1st — July 29th, 2013
      </p>

      <div class="header-social">
        <!-- Facebook Like Button -->
        <div class="fb-like fb_edge_widget_with_comment fb_iframe_widget" data-href="http://developers.facebook.com/docs/reference/plugins/like" data-send="false" data-layout="button_count" data-width="90" data-show-faces="false" fb-xfbml-state="rendered"><span style="height: 20px; width: 88px;"><iframe id="f76b1fd7" name="f3f6556488" scrolling="no" title="Like this content on Facebook." class="fb_ltr" src="http://www.facebook.com/plugins/like.php?api_key=193555714029599&amp;locale=en_US&amp;sdk=joey&amp;channel_url=http%3A%2F%2Fstatic.ak.facebook.com%2Fconnect%2Fxd_arbiter.php%3Fversion%3D25%23cb%3Df362ea0734%26origin%3Dhttp%253A%252F%252Fds-neue.local%252Ff3d565afbc%26domain%3Dds-neue.local%26relation%3Dparent.parent&amp;href=http%3A%2F%2Fdevelopers.facebook.com%2Fdocs%2Freference%2Fplugins%2Flike&amp;node_type=link&amp;width=90&amp;layout=button_count&amp;colorscheme=light&amp;show_faces=false&amp;send=false&amp;extended_social_context=false" style="border: none; overflow: hidden; height: 20px; width: 88px;"></iframe></span></div>
        <!-- Twitter Tweet Button -->
        <div class="header-twitter-share">
          <iframe allowtransparency="true" frameborder="0" scrolling="no" src="http://platform.twitter.com/widgets/tweet_button.1374787011.html#_=1375730235388&amp;count=none&amp;id=twitter-widget-0&amp;lang=en&amp;original_referer=http%3A%2F%2Fds-neue.local%2Fcampaigns.html&amp;size=m&amp;text=1%20in%206%20people%20in%20America%20will%20go%20hungry%20at%20some%20point%20during%20the%20year.%20Help%20%40dosomething%20about%20feeding%20the%20hungry%3A%20http%3A%2F%2Fwww.dosomething.org%2Fpbj&amp;url=http%3A%2F%2Fwww.dosomething.org%2Fpbj" class="twitter-share-button twitter-count-none" title="Twitter Tweet Button" data-twttr-rendered="true" style="width: 56px; height: 20px;"></iframe>
          <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
        </div>
      </div>
    </section>

    <section class="headline" id="headline">
      <h2 class="headline-callout"><span><?php print $node->field_headline[LANGUAGE_NONE][0]['value']; ?></span></h2>
      <h3 class="headline-callout"><span><?php print $node->field_subheadline[LANGUAGE_NONE][0]['value']; ?></span></h3>
    </section>

    <section class="campaign-section sms full-width" id="sms">
      <div class="content-center">
        <p class="section-intro"><?php print $node->field_sms_referral_info_copy[LANGUAGE_NONE][0]['value']; ?></p>

        <form action="//dosomething.mcommons.com/profiles/join" method="POST" class="form-default">
          <input type="hidden" name="redirect_to" value="mango">

          <div class="two-col">
            <label>Your First Name:</label>
            <input type="text" name="person[first_name]" placeholder="Your name:">
          </div>

          <div class="two-col">
            <label>Your Cell #:</label>
            <input type="text" name="person[phone]" placeholder="Your cell #:">
          </div>

          <div class="one-col">
            <label>Friend's Cell #s:</label>
          </div>

          <div class="two-col">
            <input type="text" name="friends[]" placeholder="Friend's cell #:">
            <input type="text" name="friends[]" placeholder="Friend's cell #:">
            <input type="text" name="friends[]" placeholder="Friend's cell #:">
          </div>

          <div class="two-col">
            <input type="text" name="friends[]" placeholder="Friend's cell #:">
            <input type="text" name="friends[]" placeholder="Friend's cell #:">
            <input type="text" name="friends[]" placeholder="Friend's cell #:">
          </div>

          <div class="one-col callout">
            <input type="hidden" name="opt_in_path" value="mango">
            <input type="hidden" name="friends_opt_in_path" value="mango">

            <input type="submit" class="btn primary large" value="invite friends">

            <p><a class="official-rules" href="mango" target="_blank">Official Rules &amp; Regulations</a></p>
            <p class="legal"><?php print $node->field_sms_referral_ctia_copy[LANGUAGE_NONE][0]['value']; ?></p>
          </div>
        </form>
       </div>
    </section>

    <section class="campaign-section call-to-action full-width" id="call-to-action">
      <p>
        <span><?php print $node->field_cta_copy[LANGUAGE_NONE][0]['value']; ?></span>
        <a class="left btn primary large js-jump-scroll"><?php print $node->field_cta_button_label[LANGUAGE_NONE][0]['value']; ?></a>
      </p>
    </section>

    <section class="campaign-section how-it-works full-width" id="how-it-works">
        <h2 class="section-header"><span><?php print $node->field_action_items_headline[LANGUAGE_NONE][0]['value']; ?></span></h2>

        <section class="how-it-works-container">
          <div class="three-col block">
            <img src="/images/placeholder.png" alt="X (placeholder image)">
            <h3>Learn the Issue</h3>
            <p>1 in 3 teenagers have slept through Math or English class in the past week.</p>
          </div>

          <div class="three-col block">
            <img src="/images/placeholder.png" alt="X (placeholder image)">
            <h3>Complete the Action</h3>
            <p>Drink coffee to stay awake! DoSomething.org recommends 3 cups per day.</p>
          </div>

          <div class="three-col block">
            <img src="/images/placeholder.png" alt="X (placeholder image)">
            <h3>Get Friends Involved</h3>
            <p><a href="#">Invite</a> your friends to hang out at a café with you and drink some 'fee.</p>
          </div>
        </section>

        <div class="action-kit callout" id="action-kit">
          <p>Want help running your drive? <a href="#">Download</a> our action kit, sailor.</p>
        </div>
    </section>

    <section class="campaign-section prizing full-width" id="prizing">
      <h2 class="section-header"><span>Prizing</span></h2>
      <p class="section-intro">This is the prizing section. You could win a prize!</p>

      <div class="content-center">
        <div class="one-col block">
          <img src="/images/placeholder.png" alt="x placeholder">
          <h2>Big Ol' Grand Prize</h2>
          <p>You can drink coffee all by yourself. That's why they call it a "solo" espresso!</p>
        </div>

        <div class="two-col block">
          <img src="/images/placeholder.png" alt="x placeholder">
          <h3>Individual Scholarship</h3>
          <p>You can drink coffee all by yourself. That's why they call it a "solo" espresso!</p>
        </div>

        <div class="two-col block">
          <img src="/images/placeholder.png" alt="x placeholder">
          <h3>Group Scholarship</h3>
          <p>You can coffee with your friends. Order a "quad americano" and see what happens. #YOLO</p>
        </div>
        <div class="callout">
          <p><a href="#headline" class="btn primary large js-jump-scroll">Tell Us About It</a></p>
          <p><a href="#" class="official-rules">Official Rules &amp; Regulations</a></p>
        </div>
      </div>
    </section>

    <section class="campaign-section sms-game-example full-width" id="sms-game-example">
      <h2 class="section-header"><span>An Example From the Game</span></h2>

      <div class="content-center narrow">
        <div class="game-conversation game-ds">
          <p>Girl, you got any 'fee?</p>
        </div>

        <div class="game-conversation game-user">
          <p>Yeah, I got that 'fee. Desmond gave it to me.</p>
        </div>

        <div class="game-conversation game-ds">
          <p>Double americano? Lemme get some!</p>
        </div>
      </div>
      <div class="callout">
        <a href="#headline" class="btn primary large js-jump-scroll">Play The Game</a>
      </div>
    </section>

    <section class="campaign-section gallery full-width">
      <h2 class="section-header"><span>Your Impact</span></h2>

      <div class="gallery-image">
        <img src="http://www.placekitten.com/g/960/500" alt="">
      </div>

      <ul class="gallery-thumbs">
        <li class="gallery-thumb">
          <a href="#" title=""><img src="http://www.placekitten.com/g/220/220" alt=""></a>
        </li>
        <li class="gallery-thumb">
          <a href="#" title=""><img src="http://www.placekitten.com/g/200/200" alt=""></a>
        </li>
        <li class="gallery-thumb">
          <a href="#" title=""><img src="http://www.placekitten.com/g/240/240" alt=""></a>
        </li>
        <li class="gallery-thumb">
          <a href="#" title=""><img src="http://www.placekitten.com/g/250/250" alt=""></a>
        </li>
        <li class="gallery-thumb">
          <a href="#" title=""><img src="http://www.placekitten.com/g/260/260" alt=""></a>
        </li>
        <li class="gallery-thumb">
          <a href="#" title=""><img src="http://www.placekitten.com/g/270/270" alt=""></a>
        </li>
        <li class="gallery-thumb">
          <a href="#" title=""><img src="http://www.placekitten.com/g/400/400" alt=""></a>
        </li>
        <li class="gallery-thumb">
          <a href="#" title=""><img src="http://www.placekitten.com/g/200/200" alt=""></a>
        </li>
        <li class="gallery-thumb">
          <a href="#" title=""><img src="http://www.placekitten.com/g/300/300" alt=""></a>
        </li>
        <li class="gallery-thumb">
          <a href="#" title=""><img src="http://www.placekitten.com/g/320/320" alt=""></a>
        </li>
      </ul>

      <ul class="pager">
        <li class="pager-next"><span class="btn small inactive" title="Go to previous page">‹ prev</span></li>
        <li class="pager-current"><span class="btn small inactive">1</span></li>
        <li class="pager-item"><a class="btn small" title="Go to page 2" href="/teensforjeans?page=1">2</a></li>
        <li class="pager-item"><a class="btn small" title="Go to page 3" href="/teensforjeans?page=2">3</a></li>
        <li class="pager-item"><a class="btn small" title="Go to page 4" href="/teensforjeans?page=3">4</a></li>
        <li class="pager-item"><a class="btn small" title="Go to page 5" href="/teensforjeans?page=4">5</a></li>
        <li class="pager-next"><a class="btn small" title="Go to next page" href="/teensforjeans?page=1">next ›</a></li>
      </ul>
    </section>

    <section class="campaign-section content full-width" id="content">
      <h2 class="section-header"><span>More Information on 'fee</span></h2>
      <div class="content-center">
        <p>Part of growing up means making decisions and sometimes hard life choices*. Are you going to order a double or triple espresso? Do you want that 'fee to go?</p>

        <p class="legal">*Disclaimer: The best way to prevent an underconsumption of 'fee is to order more 'fee (duh). Whether you choose to have a lot or even more, it's important to know the facts, so we've provided a list of different resources so that you can inform your own decisions.</p>

        <h4 class="headline-callout">This is a fact.</h4>
        <p>Not having any 'fee today will probably make you a terrible person.</p>

        <h4 class="headline-callout">This is a fact.</h4>
        <p>You should probably drink more 'fee. You should probably drink more 'fee. You should probably drink more 'fee. You should probably drink more 'fee. You should probably drink more 'fee. You should probably drink more 'fee.</p>

        <h4 class="headline-callout">This is a fact.</h4>
        <p>You should probably drink more 'fee. You should probably drink more 'fee. You should probably drink more 'fee. You should probably drink more 'fee. You should probably drink more 'fee. You should probably drink more 'fee.</p>

        <h4 class="headline-callout">This is a fact.</h4>
        <p>You should probably drink more 'fee. You should probably drink more 'fee. You should probably drink more 'fee. You should probably drink more 'fee. You should probably drink more 'fee. You should probably drink more 'fee.</p>

        <h4 class="headline-callout">Additional Resources</h4>
        <p>Need more? Check out these additional resources:</p>
        <ul>
          <li><a href="http://www.birchcoffee.com/" target="_blank">Birch Coffee</a></li>
          <li><a href="https://tonx.org/" target="_blank">Tonx Coffee</a></li>
          <li><a href="http://equalexchange.coop/products/coffee" target="_blank">Equal Exchange</a></li>
        </ul>
      </div>
    </section>

    <section class="campaign-section profiles full-width" id="profiles">
      <h2 class="section-header"><span>Meet the Baristas</span></h2>

      <div class="column-break">
        <div class="three-col"><img src="//www.placekitten.com/g/580/350" class="bordered" alt="Diane Nash"></div>
        <div class="three-col span-two">
         <h3>Diane Nash, 22</h3>
         <p>After seeing public bathrooms marked “white” or “colored” as a student in Nashville Tennessee, Nash was determined to fight racism. She attended nonviolent, civil disobedience workshops lead by Rev. James Lawson, and became a leader of the Nashville sit-ins, a nonviolent tactic to integrate restaurants around the city. Students would sit in “whites only” sections of lunch counters, accepting arrest and even violence to prove a point about making a change. She also helped found and led the Student Nonviolent Coordinating Committee, the largest student activist group that led key grassroots action against discrimination during the civil rights movement.</p>
        </div>
      </div>

      <div class="column-break">
        <div class="three-col"><img src="//www.placekitten.com/g/590/360" class="bordered" alt="Barbara Johns"></div>
        <div class="three-col span-two">
         <h3>Barbara Johns, 16</h3>
         <p>As a student, she was part of a segregated school district in Virginia that crammed 450 kids into a 200 person building. She started a two week strike with the help of the NAACP to advocate for an integrated school district, marching to the town courthouse to make officials aware of the large difference in quality between black and white schools. In response, her house was burned to the ground. NAACP took her case to court, which became a part of the groundbreaking Brown v. Board of Education case that ruled "separate but equal” facilities based on race illegal.</p>
        </div>
      </div>

      <div class="column-break">
        <div class="three-col"><img src="//www.placekitten.com/g/550/320" class="bordered" alt="James Zwerg"></div>
        <div class="three-col span-two">
         <h3>James Zwerg, 22</h3>
         <p>He developed an interest in civil rights after seeing his African-American roommate experience prejudice. Attending an exchange program, he went to Fisk University and met John Lewis, a leader of the Student Nonviolent Coordinating Committee, and decided to go on a Freedom Ride, a nonviolent action to test out integration laws on buses. He was arrested, and at one point ambushed during the ride. He was beaten so badly he was unconscious for two days and stayed in a hospital for five. His photos were used in many newspapers and magazines across the country, stirring even more support for the civil rights movement.</p>
        </div>
      </div>
    </section>

    <section class="campaign-section faq full-width" id="faq">
      <h2 class="section-header"><span>Frequently Asked Questions</span></h2>
      <div class="content-center">
        <div class="answer">
          <h4>What's this game about?</h4>
          <p> Would You Rather is a game where you and your friends will be given crazy, money saving situations to choose from. At the end of the game, you'll be given a few tips on how you could actually save money a bit easier.
          </p>
        </div>

        <div class="answer">
          <h4 class="active">Why should I participate?</h4>
          <p>It's fun, you can see what your friends would do, and you'll all learn something. Awesome.</p>
        </div>

        <div class="answer">
          <h4>Does the game cost anything?</h4>
          <p>The game is completely free to play, but standard text messaging rates do apply.</p>
        </div>

        <div class="answer">
          <h4>How many times can I play?</h4>
          <p>You can text "WYR" as many times as you'd like. There are a bunch of questions waiting for you!</p>
        </div>

        <div class="answer">
          <h4>How do I enter the scholarship?</h4>
          <p>All you have to do is invite 6 friends to play the game with you and you'll be entered to win a $3,000 scholarship.</p>
        </div>
      </div>

      <div class="callout">
        <a href="#headline" class="btn primary large js-jump-scroll">I want to play</a>
        <p><a href="#top" class="btn-top js-jump-scroll">Back to Top</a></p>
      </div>
    </section>

    <footer class="sponsor full-width" id="sponsor">
      <h3>Sponsored by:</h3>

      <p>
        <a href="#"> <img src="images/placeholder.png" alt="x placeholder"></a>
        <a href="#"> <img src="images/placeholder.png" alt="x placeholder"></a>
      </p>
    </footer>

    <footer class="contact" id="footer">
      <p>Questions? E-mail <a href="mailto:help@dosomething.org">help@dosomething.org</a>!</p>
    </footer>

    <!--
    Edvisors tracking pixel
    @todo - Ideally this will be handled in a more automated fashion.  This
    can be achieved by Stashing the Edvisor offer id on the campaign and
    using a a standardize (but themable) webform confirmation page.
    @todo - add a http referrer check as well
    -->
    <!-- Offer Conversion: DoSomething.org -->
    <iframe src="http://tracking.edvisors.com/aff_l?offer_id=98" scrolling="no" frameborder="0" width="1" height="1"></iframe>
    <!-- // End Offer Conversion -->
  </div>

</div>
