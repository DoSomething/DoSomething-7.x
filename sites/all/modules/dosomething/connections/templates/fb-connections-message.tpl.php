<style type="text/css">
 	<!--
 	div#top-bar {
 		background: #6D84B4;
 		border: #3B5998;
 	}

 	div#post-title {
 		color: #fff;
 		font-size: 14px;
 		font-weight: bold;
 		font-family: 'lucida grande', tahoma, verdana, arial, sans-serif;
 		line-height: 1.28;
 		padding: 5px;
 		background: url(https://s-static.ak.fbcdn.net/rsrc.php/v2/yD/x/Cou7n-nqK52.gif) no-repeat 5px 50%;
 		padding-left: 25px;
 		border: 1px solid #3B5998;
 	}

 	div#zone {
 		padding: 20px;
 		background: #fff;
 		border-left: 1px solid #555;
 		border-right: 1px solid #555;
 	}

 	div#zone input {
 		color: #000;

 	}

 	div#zone img {
 		float: left; 
 	}

 	div#img { min-width: 50px; float: left; }
 	div#text { float: left; width: 475px; padding-left: 10px;}
 	div#zone textarea {
 		font-size: 13px;
		font-weight: normal;
		margin-top: 5
		overflow: hidden;
		width: 100%;
		border: 1px solid #BDC7D8;
 	}

 	div#shared {
 		margin-top: 10px;
 		padding: 10px;
 		border: 1px dashed #ccc;
 	}

 	div#shared img { margin-right: 10px; }

 	div#shared div {
 		/*float: left;*/
 		box-sizing: border-box;
 		/*width: 385px;*/
 		padding: 0px 10px;
 		height: 89px;
 		font-size: 11px;
 		font-family: 'lucida grande', tahoma, verdana, arial, sans-serif;
 		line-height: 1.28;
 		color: #808080;
 		font-weight: normal;
 	}

 	div#shared a {
 		color: #3B5598;
 		text-decoration: none;
 		font-weight: bold;
 	}

 	div#shared p { 
 		margin-top: 5px;
 		padding: 0px;
 	}

 	div#shared a:hover {
 		text-decoration: underline;
 	}

 	div#fb {
 		position: relative;
 		background: rgba(82, 82, 82, .7);
 		border-radius: 10px;
 		padding: 10px;
 		font-family: 'lucida grande', tahoma, verdana, arial, sans-serif;
 		font-size: 11px;
 		line-height: 1.28;
 		font-weight: bold;
 		color: #808080;
 	}

 	div#submit-buttons {
 		background: #f2f2f2;
 		box-shadow: -2px -2px 1px #808080;
 		clear: both;
 		position: relative;
 		/*top: 20px;*/
 		height: 40px;
 		text-align: right;
 		padding: 10px;
 	}

 	input[type="submit"] {
 		background: #5B74A8;
 		color: #fff;
 		border-width: 1px;
 		border-color: #29447E #29447E #1A356E;
 		font-size: 13px;
 		font-weight: bold;
 		box-shadow: 0px 0px 1px #808080;
 		cursor: pointer;
 	}

 	input[type="reset"] {
 		background: #eee;
 		color: #000;
 		border: 1px solid #999;
 		font-size: 13px;
 		font-weight: bold;
 		box-shadow: 0px 0px 1px #808080;
 		cursor: pointer;
 	}

 	#receivers {
 		width: 100%;
 		font-size: 13px;
		font-weight: normal;
		overflow: hidden;
		border: 1px solid #BDC7D8;
		background: #fff;
		color: #000;
		height: 20px;
		margin-bottom: 10px;
 	}

 	div.label {
 		margin-top: 15px;
 		font-weight: bold;
 		text-align: right;
 	}

 	div.label#to {
 		margin-top: 5px;
 	}
 	div#receivers-list {
		border: 1px solid #BDC7D8;
 		min-height: 22px;
 		width: 100%;
 		box-sizing: border-box;
 		margin-bottom: 10px;
 	}

 	div#receivers-list ul {
 		margin: 0px;
 		padding: 2px;
 	}

 	div#receivers-list ul li {
 		background: #E2E6F0;
		border: 1px solid #9DACCC;
		-webkit-border-radius: 2px;
		color: #1C2A47;
		cursor: default;
		display: block;
		float: left;
		height: 17px;
		margin: 0 4px 2px 0;
		padding: 0 3px;
		position: relative;
		white-space: nowrap;
 	}

 	div#receivers-list ul li a {
 		text-decoration: none;
 		font-family: Verdana;
 		font-size: 9px;
 		color: #9BAECD;
 		display: inline-block;
 		width: 11px;
 		height: 11px;
 		text-align: center;
 	}

 	div#receivers-list ul li a:hover {
 		background: #325c99;
 		color: #fff;
 	}

 	div.clearfix {
 		clear: both;
 	}
 	-->
 	</style>

 	<script type="text/javascript">
 	<!--
 		jQuery(document).ready(function() {
			var receivers = [<?php echo $to; ?>];
			elms = '';
			var to = window.setInterval(function () {
		      if (typeof FB != 'undefined') {
		        window.clearInterval(to);
		        var name = '';
		        for (var i in receivers) {
		        	name = '';
					FB.api(receivers[i] + '?fields=name', function(response) {
					   jQuery('<li class="fb_selector" fb:id="' + receivers[i] + '">' + response.name + '<a href="#">X</a></li>').appendTo(jQuery('#receivers-list ul'));
					});
				}
		      }
		    }, 5);
			

			function c(v) {
				for (i in receivers) {
					if (receivers[i] == v) {
						receivers.splice(i, 1);
					}
				}
			}

 			jQuery('.fb_selector').find('a').click(function() {
 				var fbid = jQuery(this).parent().attr('fb:id');
 				jQuery(this).parent().remove();
 				c(fbid);
 				return false;
 			});
 		});
 	-->
 	</script>

<div id="fb">
	<div id="wrapper">
	<div id="top-bar">
		<div id="post-title">Send a Message</div>
	</div>
	<div id="zone">
		<div id="img">
			<div class="label" id="to">To:</div>
			<div class="label" id="message">Message:</div>
		</div>
		<div id="text">
			<div id="receivers-list">
				<ul></ul>
				<div class="clearfix"></div>
			</div>

			<!--<input type="text" name="receivers" id="receivers" value="" />-->
			<textarea name="comments" id="comments"></textarea>

			<div id="shared">
				<img src="<?php echo $image; ?>" width="90" height="90" alt="" />
				<div>
						<a href="#"><?php echo $title; ?></a>
						<p><?php echo $caption; ?></p>
						<p><?php echo $description; ?></p>
				</div>
			</div>
		</div>
		<div style="clear: both"></div>
	</div>
	<div id="submit-buttons">
		<input type="submit" value="Share" onclick="" />
		<input type="reset" value="Cancel" onclick="" />
	</div>
</div>
</div>