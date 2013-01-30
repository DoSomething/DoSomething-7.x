 <style type="text/css">
 	<!--
 	body { margin: 0px; padding: 0px; font-family: 'lucida grande', tahoma, verdana, arial, sans-serif; }
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
 		width: 480px;
 		height: 480px;
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
 		font-size: 10pt;
 		position: relative;
 		/*top: 20px;*/
 		height: 40px;
 		text-align: right;
 		padding: 10px;
 	}

 	div#submit-buttons label {
 		float: none;
 		color: #000;
        font-size: 10pt !important;
 		display: inline-block;
 	}

 	div#submit-buttons #submit-og-post, div#submit-buttons #cancel-og-post {
 		border-radius: 0px;
 		-moz-border-radius: 0px;
 		-webkit-border-radius: 0px;
 		-ms-border-radius: 0px;
 		-o-border-radius: 0px;
 		text-shadow: none;
 	}

 	div#submit-buttons #submit-og-post {
 		background: #5B74A8;
 		color: #fff;
 		border-width: 1px;
 		border-color: #29447E #29447E #1A356E;
 		font-size: 13px;
 		font-weight: bold;
 		box-shadow: 0px 0px 1px #808080;
 		cursor: pointer;
 	}

 	div#submit-buttons #cancel-og-post {
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


    .ui-autocomplete {
        width: 467px;
        padding: 0px;
        border: 1px solid #000;
        position: absolute;
        left: 24px;
        top: 250px;
        z-index: 9999;
    }

    .ui-autocomplete li {
        min-height: 32px;
        padding: 2px;
        list-style-type: none;
        background: #fff;
        cursor: pointer;
        border-top: 1px solid #fff;
        border-bottom: 1px solid #fff;
    }

    .ui-autocomplete li:hover {
        background: #6d84b4;
        border-top: 1px solid #000;
        border-bottom: 1px solid #000;
        color: #fff;
        cursor: pointer;
    }

    .ui-autocomplete li a {
        display: block;
        height: 32px;
    }

    .ui-autocomplete li img {
        float: left;
        margin-right: 5px;
        width: 32px;
        height: 32px;
    }

    .ui-autocomplete li span {
        margin-top: 6px;
        font-size: 9pt;
        font-weight: bold;
        display: inline-block;
    }

 	#hidden_comments {
 		display: none;
 	}

    #alert {
        margin: 0px 10px 10px 0px;
        background: #FEF5F1;
        border: 1px solid #ED541D;
        padding: 5px;
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
        <?php if ($message) { ?><div id="alert"><?php echo $message; ?></div><?php } ?>
		<div id="img"><img src="<?php echo $photo; ?>" alt="" /></div>
		<div id="text">
				<textarea name="comments" id="fb_og_comments" placeholder="Say something about this..."></textarea>
				<textarea name="hidden_comments" id="hidden_comments"></textarea>

				<div id="shared">
					<img src="<?php echo $image; ?>" width="480" height="480" alt="" />
				</div>
		</div>
		<div style="clear: both"></div>
	</div>
	<div id="submit-buttons">
		<input type="checkbox" id="explicit-share" checked="checked" /> <label for="explicit-share">Post to my wall</label>
		<input type="submit" value="Share" id="submit-og-post" />
		<input type="reset" value="Cancel" class="close-fb-dialog" id="cancel-og-post" />
	</div>
</div>
</div>

<?php if ($tagging) { ?>
<script type="text/javascript">
(function($) {
	var p = $('#fb_og_comments').position();
	var ai = window.setInterval(function () {
		if ($('.ui-autocomplete').length > 0) {
		  window.clearInterval(ai);

		  $('.ui-autocomplete').css('left', p.left + 'px').css('top', (p.top + $('#fb_og_comments').height() - 10) + 'px');
		}
	}, .1);
    $('#fb_og_comments').click(function() {
        FB.getLoginStatus(function(response) {
            var friends = new Array();
            FB.api('/me/friends?fields=id,name,picture', function(response) {
                for (i in response.data) {
                    var stuff = {
                        'value': response.data[i].id,
                        'label': response.data[i].name,
                        'img': response.data[i].picture.data.url
                    };

                    friends.push(stuff);

                    $('#fb_og_comments').triggeredAutocomplete({
                        hidden: '#hidden_comments',
                        source: friends,
                        trigger: "@" 
                    });
                }
            });
        });
    });
})(jQuery);
</script>
<?php } ?>