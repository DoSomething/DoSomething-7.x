 <style type="text/css">
 	<!--
 	body { margin: 0px; padding: 0px; }
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

 	div#zone img {
 		float: left; 
 	}

 	div#img { min-width: 50px; }
 	div#text { float: left; width: 485px; padding-left: 10px;}
 	div#zone textarea {
 		font-size: 13px;
		font-weight: normal;
		margin-top: 5px;
		overflow: hidden;
		width: 100%;
 	}

 	div#shared {
 		background: #f7f7f7;
 		margin-top: 10px;
 	}

 	div#shared img {
 		float: left;
 	}

 	div#shared div {
 		float: left;
 		background: #f7f7f7;
 		border: 1px solid #efefef;
 		width: 385px;
 		box-sizing: border-box;
 		padding: 10px;
 		height: 89px;
 		font-size: 11px;
 		font-family: 'lucida grande', tahoma, verdana, arial, sans-serif;
 		line-height: 1.28;
 		color: #808080;
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
 		text-align: left;
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

 	div#submit-buttons input {
 		border-radius: 0px;
 		-moz-border-radius: 0px;
 		-webkit-border-radius: 0px;
 		-ms-border-radius: 0px;
 		-o-border-radius: 0px;
 		text-shadow: 0px;
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

 	div#top-bar a {
 		float: right;
 		font-family: Verdana;
 		font-size: 9px;
 		margin: 7px 2px;
 		text-decoration: none;
 		color: #b6c2da;
 		padding: 3px;
 		display: inline-block;
 		width: 20px;
 		height: 15px;
 		background: url(http://static.ak.fbcdn.net/rsrc.php/v2/yA/x/IE9JII6Z1Ys.png) no-repeat scroll 0 0px transparent;
 	}

 	div#top-bar a:hover {
 		background: #2b63b1;
 		color: #fff;
 		background: url(http://static.ak.fbcdn.net/rsrc.php/v2/yA/x/IE9JII6Z1Ys.png) no-repeat scroll 0 -15px transparent;
 	}
 	-->
</style>
<div id="fb">
	<div id="wrapper">
	<div id="top-bar">
		<a href="#" class="close-fb-dialog" id="close-fb-dialog"></a>
		<div id="post-title">Post to Your Wall</div>
	</div>
	<div id="zone">
		<div id="img"><img src="<?php echo $photo; ?>" alt="" /></div>
		<div id="text">
				<textarea name="comments" id="fb_og_comments" placeholder="Say something about this..."></textarea>

				<div id="shared">
					<img src="<?php echo $image; ?>" width="90" height="90" alt="" />
					<div>
							<a href="#"><?php echo $title; ?></a>
							<p><?php echo $description; ?></p>
					</div>
				</div>
		</div>
		<div style="clear: both"></div>
	</div>
	<div id="submit-buttons">
		<input type="submit" value="Share" id="submit-og-post" />
		<input type="reset" value="Cancel" class="close-fb-dialog" id="cancel-og-post" />
	</div>
</div>
</div>