<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Here\'s What You Do'),
  'description' => t('Words, words, words.'),
  'category' => t('Campaign - Thumb Wars'),
);

/** render callback **/

function dosomething_panels_what_you_do_content_type_render($subtype, $conf, $panel_args, $context){
  $block = new stdClass();

  $block->module = 'dosomething_panels';
  $block->delta = 'static-blah';
  $block->title = t('Here\'s What You Do');

  $block->content = <<<EOF
  <div class="section do" id="do">
    <div class="divider"><span>here's what you do</span></div>
    <div class="col">
      <h1>1</h1>
      <h2>get thumb socks</h2>
      <img src="http://files.dosomething.org/files/campaigns/thumb/scroll/do1.png"/>
      <p class="bottom">Sign up to the left to enter for a chance to get two pairs of thumb socks. *You must be 25 or younger to get thumb socks.</p>
    </div> <!-- .col -->
    <div class="col mid">
      <h1>2</h1>
      <h2>share the socks</h2>
      <img src="http://files.dosomething.org/files/campaigns/thumb/scroll/do2.png"/>   
      <p class="bottom">Wear them on your thumbs or pick a friend who texts and drives and share the socks with them in a surprising way.</p>
    </div> <!-- .col -->
    <div class="col">
      <h1>3</h1>
      <h2>tell us about it</h2>
      <img src="http://files.dosomething.org/files/campaigns/thumb/scroll/do3.png"/>
      <p class="bottom">Take a pic of you and your friends wearing the thumb socks and send it to us <a href="/thumbwars/tell-us">here</a>. That will enter you for a $10k scholarship.</p>
    </div> <!-- .col -->
  </div> <!-- .section .do (first)-->
EOF;
  return $block;
}

