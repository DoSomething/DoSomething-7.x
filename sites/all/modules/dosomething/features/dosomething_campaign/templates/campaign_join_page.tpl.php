<!doctype>
<html>
  <head>

    <meta charset=utf-8 />
    <title>Sign Up for the Campaign!</title>

    <link rel="stylesheet" href="https://c308566.ssl.cf1.rackcdn.com/din-511.css" media="all" />

    <style>

      body {
        background: #fff;
        font-family: din-web-reg;
      }

      form {
        margin: 0 0 5px 0;
      }

      h3 {
        font-size: 36px;
      }

      p {
        font-size: 32px;
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
        font-size: 24px;
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

      .container {
        width: 550px;
        margin: 2% auto;
        padding: 30px;
        color: #fff;
        background: #302d2d;
        border: 1px solid #444;
        -webkit-border-radius: 3px;
        -moz-border-radius: 3px;
        -o-border-radius: 3px;
        border-radius: 3px;
        cursor: pointer;
        -webkit-box-shadow: 0px 15px 20px -10px #ccc;
        -moz-box-shadow: 0px 15px 20px -10px #ccc;
        -o-box-shadow: 0px 15px 20px -10px #ccc;
        box-shadow: 0px 15px 20px -10px #ccc;
      }

      @media only screen and (max-width: 650px) {

        h3 {
          font-size: 24px;
        }

        p {
          font-size: 18px;
        }

        .container, .logo {
          width: 89.5%;
          margin: 0;
          padding: 3% 5%;
        }

        .copy {
          margin: 0;
        }

      }

    </style>

  </head>
  <body>

    <section class="container">
      <img src="http://www.dosomething.org/files/campaigns/hunt13/header2.png" alt="The Hunt!" class="logo" />

      <div class="copy">
        <h3>You have 11 days to kick ass on causes you care about.</h3>
        <p>Send us a pic of what you do and be featured in our national commercial.</p>
      </div>

      <?php print render($form); ?>
    </section>

  </body>
</html>
