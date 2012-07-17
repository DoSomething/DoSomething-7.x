<?php header('Access-Control-Allow-Origin: *'); ?>

<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.4.4/jquery.min.js"></script>
<script type="text/javascript" src="script.js"></script>

<link href="style.css" media="all" rel="stylesheet" type="text/css">

<div id="cask">
  
  <div class="section cause">
    <h1>
      <span>texting and driving is one of the</span>
      <br>
      <span>biggest killers of teens</span>
    </h1>
    <h2>
      <span>But now, you can save your friends with</span>
      <br>
      <span>the power of your thumbs.</span>
    </h2>
  </div> <!-- /.section .cause -->
  
  <div class="section do">
    <div class="divider"><span>here's what you do</span></div>
    <div class="col">
      <h1>1</h1>
      <h2>get thumb socks</h2>
      <img src="assets/do1.png"/>
      <p>Sign up to the left to enter for a chance to get two pairs of thumb socks. *You must be 25 or younger to get thumb socks.</p>
    </div> <!-- /.col -->
    <div class="col">
      <h1>2</h1>
      <h2>share the socks</h2>
      <img src="assets/do2.png"/>
      <p>Wear them on your thumbs or pick a friend who texts and drives and share the socks with them in a surprising way.</p>
    </div> <!-- /.col -->
    <div class="col">
      <h1>3</h1>
      <h2>tell us about it</h2>
      <img src="assets/do3.png"/>
      <p>Take a pic of you and your friends wearing the thumb socks and send it to us <a href="/mango/report-back">here</a>. That will enter you for a $10k scholarship.</p>
    </div> <!-- /.col -->
  </div> <!-- /.section .do (first)-->
  
  <div class="section do">
    <div class="col">
      <h1>4</h1>
      <h2>win a scholarship</h2>
      <img src="assets/do4.png"/>
      <p>There are two ways to win &ndash; send 5 friends texting and driving stats, and <a href="/mango/report-back">send us</a> pics. Check out <a href="/mango/#scholarships">scholarships</a> for more info.</p>      
    </div> <!-- /.col -->
    
    <div class="col2">
      <h3>Send 5 friends texting and driving stats to win a $10k scholarship</h3>
      <!-- refer friends webform -->
      <form action="http://dosomething.mcommons.com/profiles/join" method="POST">
        <input type="hidden" name="redirect_to" value="http://www.dosomething.org/thumbwars/mango" />
        <div class="mcommons-webform-column">
          <label>Your First Name:<br><input type="text" name="person[first_name]" class="field space-after" /></label>
          <label>Your Cell Number:<br><input type="text" name="person[phone]" class="field space-after" /></label>
          <div id="refer-opt-in" style="width: 175px">
            <p class="disclaimer">By clicking submit, you are opting into these <a target="_blank" href="http://www.dosomething.org/mango">official rules</a> and our weekly updates. <a href="#" id="opt-in-help-mobile">?</a></p>
          </div> <!-- /.refer-opt-in -->
        </div> <!-- /.mcommons-webform-column -->
        <div class="mcommons-webform-column">
          <label>Friends' Cell Numbers:</label>
          <input type="text" class="field left" name="friends[]"/>
          <input type="text" class="field left" name="friends[]"/>
          <input type="text" class="field left" name="friends[]"/>
          <input type="text" class="field left" name="friends[]"/>
          <input type="text" class="field left" name="friends[]"/>
          <input type="hidden" name="friends_opt_in_path" value="mango" />
          <input type="hidden" name="opt_in_path" value="mango">
          <input type="submit" class="go-button" value="go" />
        </div> <!-- /.mcommons-webform-column -->
      </form>
    </div> <!-- /.col2 -->    
  </div> <!-- /.section .do (second) -->
  
  <div class="section do">
    <h1>how to use your socks:</h1>
    
    <br><h1>gallery</h1>
    <br><h1>goes</h1>
    <br><h1>here</h1>
    
  </div> <!-- /.section .do (third) -->
  
  <div class="section learn">
    <div class="divider"><span>learn the issue</span></div>    
    <h1>SHARE STATS</h1>
  </div> <!-- /.section .learn -->
  
  <div class="section scholarship">
    <div class="divider"><span>scholarship info</span></div>
    <h1 class="massive">$10,000 Scholarship</h1>
    <img src="mango (arrows)" alt="two ways to enter"/>
    <div class="row">
      <div class="col3">
        <h3>send 5 friends texting &amp; driving stats</h3>
        <img src="mango (arrows)" alt="two ways to enter"/>
        <p>Sign-up above to get two pairs of thumb socks. Once you get your socks in the mail, take some pics of you and/or your friends wearing them and <a href="mango">upload them here</a>!</p>
      </div> <!-- /.col3 -->
      <div class="col4">
        <h3>send us your thumb pics</h3>
        <img src="mango (arrows)" alt="two ways to enter"/>
        <p>Use <a href="mango">this form</a> to send your friends some crazy stats on texting &amp; driving. You'll qualify to win a $10,000 scholarship.</p>
      </div> <!-- /.col4 -->
    </div> <!-- /.row -->
    <h3>You'll DOUBLE your chances of winning if you do both steps #1 and #2.</h3>
    <p class="disclaimer">One randomly selected participant will be selected to win.
      <br>
    <a href="mango">Check out the official rules and regulations</a>
    </p>
  </div> <!-- /.section .scholarship -->
  
  <div class="section did">
    <div class="divider"><span>tell us what you did</span></div>
    <h1>GALLERY</h1>
  </div> <!-- /.section .did -->
  
  <div class="section faq">
    <div class="divider"><span>questions?</span></div>
      <h4>What is this thing you call “Thumb Wars”?</h4>
      <h4>Is texting and driving really that dangerous?</h4>
      <h4>Ah! That’s insane! What do I do?</h4>
      <h4>How do I use the socks?</h4>
        <p>We think picking a friend or family member that you know texts while driving is a good first step. After that, you can tape the socks to their steering wheel, ask them to wear them while driving for a day, or hide them in the glove compartment. Be creative! Have fun with it! And if you take a picture of what you do and send it to us, you’ll be entered to win a scholarship (more info on that after June 18th).</p>      
      <h4>Does everybody get socks?</h4>
      <h4>This is kinda silly.</h4>
      <h4>Hey! I entered to get some socks! Where are they?</h4>
      <h4>I have more questions!</h4>
      <p class="help">*Thumb Socks do not actually have superpowers. We’re working on that. But we think you’re a hero for doing this to help make your friends and family safer.</p>
  </div> <!-- /.section .faq -->
  
</div> <!-- /#cask -->
