<!doctype>
<html>
  <head>

    <meta charset=utf-8 />
    <title><?php print $node->gate_page_title; ?></title>

    <style>

      body {
        background: #fff;
      }

      form {
        margin: 0 0 5px 0;
      }

      input {
        display: block;
        margin: 0 auto;
        padding: 10px;
        width: 150px;
        background: yellow;
        color: #1e1d1c;
        text-transform: uppercase;
        font-weight: bolder;
        font-size: 16px;
        border: 1px solid #FFCB15;
        background: linear-gradient(#FFCB15, #FEB800) repeat scroll 0 0 #FFCB15;
        -webkit-border-radius: 2px;
        -moz-border-radius: 2px;
        -o-border-radius: 2px;
        border-radius: 2px;
        cursor: pointer;
      }

      input:hover {
        background: #feb800;
      }

      .logo {
        width: 500px;
        margin: 0 auto;
        display: block;
      }

      .copy {
        margin: 50px auto;
      }
3
    </style>

  </head>
  <body class="gate-<?php print $node->nid; ?>">

    <section class="container">
      <h1><?php print $node->gate_headline; ?></h1>
      <p><?php print $node->gate_description; ?></p>
      <div class="copy">
        <h3><?php print $node->gate_sidebar_headline; ?>.</h3>
        <p><?php print $node->gate_sidebar_description; ?></p>
        <p><?php print $node->gate_sidebar_footer; ?></p>
      </div>

      <?php print render($form); ?>
    </section>

  </body>
</html>
