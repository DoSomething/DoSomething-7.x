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
        padding-bottom: 0px;
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

    div#shared img {
        margin-right: 10px;
        width: 90px;
        height: 90px;
    }

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

    div#text strong {
        float: left;
        position: relative;
        top: 3px;
        margin-right: 5px;
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

body {
font-family: 'lucida grande', tahoma, verdana, arial, sans-serif;
margin: 0px;
}
textarea {
    width: 300px;
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

#your-friends {
    float: left;
    background: #fff;
    margin: 5px;
    padding-bottom: 5px;
    width: 50%;
}

#your-friends #your-info {
    border-bottom: 1px solid #9DACCC;
    border-right: 1px solid #9DACCC;
    min-height: 55px;
}

#friends-info {
    clear: left;
    margin: 0px;
    padding: 0px;
    padding-top: 10px;
    list-style-type: none;
    border-right: 1px solid #9DACCC;
    min-height: 325px;
    max-height: 325px;
    overflow: auto;
}

#friends-info li {
    clear: both;
    min-height: 55px;
    cursor: pointer;
    position: relative;
    border-top: 1px solid #D8D6D6;
    padding-top: 5px;
}

#friends-info a {
    /*display: block;*/
    min-height: 55px;
    display: block;
    /*float: left;*/
}

#friends-info li.selected {
    background: #f1f1f1;
}

#friends-info li:hover {
    background: #f1f1f1;
    text-decoration: none;
}

#friends-info li:hover > div.comment {
    display: inline-block;
}

#friends-info li a, #find-close-friends, #close-close-friends {
    text-decoration: none;
    color: #2c4e7c;
}

#friends-info a img {
    clear: both;
    margin-right: 5px;
    float: left;
}

#friends-info a div {
    /*padding-top: 15px;*/
}

#friends-info div.comment {
    margin-top: 5px;
    padding: 3px;
    display: none;
    float: left;
    width: auto;
}

#friends-info li div input[type="text"], .my-post {
    width: 230px;
    background: #fff;
    border: 1px solid #808080;
    color: #000;
}

#friends-info li div input[type="submit"], .my-submit {
    margin-left: 10px;
    margin-top: 3px;
    background: #fed22e;
    border-radius: 3px;
    -moz-border-radius: 3px;
    -webkit-border-radius: 3px;
    -o-border-radius: 3px;
    margin-top: 0px;
    height: 27px;
    border: 1px solid #808080;
}

#choosers {
    max-height: 390px;
    overflow: auto;
    width: 320px;
    margin: 0px auto;
}

#choosers img {
    margin: 15px;
    float: left;
    cursor: pointer;
}

li#select {
    min-height: 25px;
}

li#select:hover {
    background: #fff;
    cursor: default;
}

#select {
    border-right: 1px solid #9DACCC;
    text-align: center;
    padding: 5px 0px;

    border-bottom: 1px solid #9DACCC;
    background: #f1f1f1;
}

#select a {
    display: inline;
}

#search {
    position: relative;
    min-height: 37px;
    padding: 5px;
    background: #f1f1f1;
    border-right: 1px solid #9DACCC;
}

#search input {
    width: 100%;
    padding: 5px;
    background: #fff;
    border: 1px solid #808080;
    color: #000;
}

.hidden, .close-hidden {
    display: none;
}

#alert {
    margin: 0px -7px 10px 365px;

    background: #FEF5F1;
    border: 1px solid #ED541D;
    padding: 5px;
}

#search a.clear-search {
    background: #EEE;
    border: 1px solid gray;
    padding: 1px 4px;
    position: absolute;
    text-decoration: none;
    right: 10px;
    top: 10px;
    color: black;
    border-radius: 20px;
}

#search a.clear-search:hover {
    background: #f5f5f5;
}

#close-close-friends {
    display: none;
}
-->
</style>
<script type="text/javascript" src="/sites/all/modules/dosomething/connections/js/selector.js"></script>

<script>
<!--
   FB_extra.friendSelector.init({
      'limit': 0,
   });
-->
</script>

<div id="fb">
    <div id="wrapper">
    <div id="top-bar">
        <a href="#" class="close-fb-dialog" id="close-fb-dialog"></a>
        <div id="post-title">Share with your friends</div>
    </div>
    <div id="your-friends">
        <div id="your-info">
            <img src="http://www.loremipsum.net/pixelgif/pics/pixel.gif" width="50" height="50" style="float: left; margin-right: 5px" id="profile-pic" alt="" />
            <div style="display: inline-block" id="profile-name">&nbsp;</div>
            <div style="margin-top: 8px" id="my-share">
                <input type="text" name="share-to-me" placeholder="Post on my own wall..." class="my-post" style="background: #fff; border: 1px solid #808080; color: #000" />
                <input type="submit" value="SHARE" class="my-submit" />
            </div>
        </div>
        <div id="search">
            <input id="search-friends" type="text" placeholder="Search for friends by name..." />
            <a href="#" class="clear-search" title="Clear Your Search">X</a>
        </div>
        <div id="select">
            <a href="#" id="find-close-friends">Show my close friends</a>
            <a href="#" id="close-close-friends" style="display: none">Show all of my friends again</a>
            <!--| <a href="#" id="show-selected">Show Selected</a>-->
            <!--<a href="#" id="select-all">Select All</a> / <a href="#" id="select-none">None</a>-->
        </div>

        <ul id="friends-info">
            <li class="loading"><img src="/sites/all/modules/dosomething/dosomething_contact_picker/images/loading.gif" alt="Loading..." /> Loading your friends...</li>
        </ul>
    </div>
    <div id="zone">
        <p id="alert">On the left, select friends to share with.</p>
        <div id="choosers">
        </div>
        <div style="clear: both"></div>
    </div>
    <div id="submit-buttons">
        <input type="submit" value="I'm Finished" id="submit-og-post" />
        <!--<input type="reset" value="Cancel" id="cancel-og-post" class="close-fb-dialog" />-->
    </div>
</div>
</div>