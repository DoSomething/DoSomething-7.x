<?php
/**
 * @file Rules integration for the mailchimp module.
 */

function connections_og_fb_post() {
  $_SESSION['og_connect'] = func_get_args();
  unset($_SESSION['form']['op']);
}

function connections_og_feed() {
    $_SESSION['fb_connect'] = func_get_args();
    unset($_SESSION['form']['op']);
}

function connects_fb_app_id($app_id) {
  $_SESSION['fb_app_id'] = $app_id;
  unset($_SESSION['form']['op']);
}

function connections_app_request() {
  $_SESSION['fb_app_request'] = func_get_args();
  unset($_SESSION['form']['op']);
}

function connections_fb_message() {
  $_SESSION['fb_message'] = func_get_args();
  unset($_SESSION['form']['op']);
}

/**
 *  Implements hook_rules_condition_info()
 */
function connections_rules_condition_info() {
  $items['connections_on_page'] = array(
    'label' => t('On a particular page (by path)'),
    'parameter' => array(
      'connection_page_path' => array(
        'type' => 'text',
        'label' => t('The path to the page'),
        'description' => t('You may use wildcards (*) to broaden the scope.  For example: blog/* applies to blog/, blog/blog-post, etc.  &lt;front&gt; will apply to the front page.'),
        'default mode' => 'input'
      ),
    ),
    'group' => t('General')
  );

  return $items;
}

function connections_on_page($connection_page_path) {
  $path = request_uri();
  if ($path{0} == '/') {
    $path = substr($path, 1);
  }

  if ($connection_page_path == '<front>' && drupal_is_front_page()) {
    return true;
  }
  else {
    if (strpos($connection_page_path, '*') !== FALSE) {
      $wanna = str_replace('*', '', $connection_page_path);
      return (boolean) strstr($path, $wanna);
    }
    else {
      return (boolean) ($path == $connection_page_path);
    }
  }
}

/**
 * Implements hook_rules_action_info().
 */
function connections_rules_action_info() {

  // Open Graph post
  $items['connections_og_fb_post'] = array(
    'label' => t('Post to the user\'s wall (with Open Graph)'),
    'parameter' => array(
      'og_namespace' => array(
        'type' => 'text',
        'label' => t('Open Graph Namespace'),
        'description' => t('The namespace for the Open Graph app.  This can be found on !devfb.  Default is "dosomethingapp".', array('!devfb' => url('http://developers.facebook.com', array('absolute' => TRUE)))),
        'default value' => 'dosomethingapp',
        'default mode' => 'input'
      ),
      'og_type' => array(
        'type' => 'text',
        'label' => t('Open Graph Object Type'),
        'description' => t('The Object type (e.g. pet_who_needs_a_home) of the open graph object.  This can be found on http://developers.facebook.com under "Open Graph".'),
        'default mode' => 'input'
      ),
      'og_action' => array(
        'type' => 'text',
        'label' => t('Open Graph Action Type.'),
        'description' => t('The Action Type (e.g. share) for Open Graph.  This can be found on http://developers.facebook.com under "Open Graph"'),
        'default mode' => 'input',
      ),
      'og_document' => array(
        'type' => 'text',
        'label' => t('Document (URL) to share'),
        'description' => t('The document (url) to share, in absolute format (e.g. http://www.google.com including the http:// part).  Leave this blank to default to the page the user is currently on.'),
        #'default value' => 'document.location.href',
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'og_post_image' => array(
        'type' => 'text',
        'label' => t('Picture (image) to share'),
        'description' => t('The picture that will appear alongside the post, in absolute format (e.g. http://www.google.com including the http:// part).  Leave this blank to use the default page image.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'og_post_description' => array(
        'type' => 'text',
        'label' => t('Post Description'),
        'description' => t('The description (if applicable) for the share.  This is usually set on http://developers.facebook.com, but you can copy + paste here.  This will override all other descriptions.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'og_post_custom' => array(
        'type' => 'text',
        'label' => t('Custom variables (Developers only)'),
        'description' => t('You may define custom variables here.  These will be passed with the share array to FB.api().  One per line.  Format: VARIABLE_NAME: VARIABLE_VALUE.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'og_selector' => array(
        'type' => 'text',
        'label' => t('Only share if a user clicks on an element with this class / id:'),
        'description' => t('If you define a class (.class) or ID (#id) here, Open Graph will trigger when that element is clicked.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'og_require_login' => array(
        'type' => 'boolean',
        'label' => t('Require a user to log in to Facebook if they aren\'t already?'),
        'description' => t('If a user is not logged in to Facebook, provide them with a Facebook Login box.'),
        'default value' => 1,
        'optional' => TRUE
      ),
      'og_fake_dialog' => array(
        'type' => 'boolean',
        'label' => t('Pop up a message dialog?'),
        'description' => t('If this is checked, a message dialog will appear where users can input text about their share.  If this is not checked, no pop-up will appear and Open Graph will immediately post to the user\'s wall without user input.'),
        'default value' => 1,
        'optional' => TRUE
      )
    ),
    'group' => t('Facebook Connections'),
  );

  // Feed Dialog post
  $items['connections_og_feed'] = array(
    'label' => t('Post to the user\'s wall (with Feed Dialog)'),
    'parameter' => array(
      'feed_document' => array(
        'type' => 'text',
        'label' => t('Document (URL) to share'),
        'description' => t('The document (url) to share, in absolute format (e.g. http://www.google.com including the http:// part).  Leave this blank to default to the page the user is currently on.'),
        #'default value' => 'document.location.href',
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'feed_title' => array(
        'type' => 'text',
        'label' => t('Post Title'),
        'description' => t('The (optional) title that will appear on the post.  Leave this blank to default to the page\'s title.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'feed_picture' => array(
        'type' => 'text',
        'label' => t('Post picture'),
        'description' => t('The picture that will appear alongside the post, in absolute format (e.g. http://www.google.com including the http:// part).  Leave this blank to use the default page image.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'feed_caption' => array(
        'type' => 'text',
        'label' => t('Post caption'),
        'description' => t('The (optional) caption that will appear under the title.  If this is left blank, the caption will be the current page\'s URL.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'feed_description' => array(
        'type' => 'text',
        'label' => t('Post description'),
        'description' => t('An (optional) description, that will appear under the caption.  If this is left blank, the description will be the current page\'s description.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'feed_selector' => array(
        'type' => 'text',
        'label' => t('Only share if a user clicks on an element with this class / id:'),
        'description' => t('If you define a class (.class) or ID (#id) here, the feed dialog will trigger when a user clicks on that element.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'feed_allow_multiple' => array(
        'type' => 'boolean',
        'label' => t('Allow users to post to multiple friends\' walls?'),
        'description' => t('If selected, users will be able to select several of their friends to message, all at once.  Requires log-in before users can select their friends.  If this is not selected, shares will post to the user\'s wall.'),
        'default value' => 1,
        'optional' => TRUE
      ),
      'feed_require_login' => array(
        'type' => 'boolean',
        'label' => t('Require a user to log in to Facebook if they aren\'t already?'),
        'description' => t('If a user is not logged in to Facebook, provide them with a Facebook Login box.'),
        'default value' => 1,
        'optional' => TRUE
      ),
    ),
    'group' => t('Facebook Connections'),
  );

  // Facebook Message
  $items['connections_fb_message'] = array(
    'label' => t('Send a message'),
    'parameter' => array(
      'msg_document' => array(
        'type' => 'text',
        'label' => t('Document (URL) to share'),
        'description' => t('The document (url) to share.  "document.location.href" defaults to the page the current user is on.'),
        'default value' => 'document.location.href',
        'default mode' => 'input',
      ),
      'msg_picture' => array(
        'type' => 'text',
        'label' => t('Post picture'),
        'description' => t('The picture that will appear alongside the post.  Wrap javascript variables in {curly braces}.  Optional.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'msg_selector' => array(
        'type' => 'text',
        'label' => t('Only share if a user clicks on an element with this class / id:'),
        'description' => t('If you define a class (.class) or ID (#id) here, Open Graph will post to their wall if they click on that element.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'msg_require_login' => array(
        'type' => 'boolean',
        'label' => t('Require a user to log in to Facebook if they aren\'t already?'),
        'description' => t('If a user is not logged in to Facebook, ask them to log in with a Facebook Login box.'),
        'default value' => 1,
        'optional' => TRUE
      ),
      // Not possible through Facebook :( -- and no, there isn't a FB.API() call for it.
      /*'msg_allow_multiple' => array(
        'type' => 'boolean',
        'label' => t('Allow messaging to multiple people at once?'),
        'description' => t('This will pop the friend selector so people can message more than one person at once.'),
        'default value' => 1,
        'optional' => TRUE
      ),*/
    ),
    'group' => t('Facebook Connections'),
  );

  // Change the FB App Id
  $items['connects_fb_app_id'] = array(
    'label' => t('Change the Facebook App ID'),
    'parameter' => array(
      'appid' => array(
        'type' => 'text',
        'label' => t('New App ID'),
        'description' => t('The new Facebook App ID to replace on the page.  This can be found on developers.facebook.com'),
        'default mode' => 'input',
      ),
    ),
    'group' => t('Facebook Connections'),
  );

  // Feed Dialog post
  $items['connections_app_request'] = array(
    'label' => t('Pop-up the app request dialog'),
    'parameter' => array(
      'app_request_title' => array(
        'type' => 'text',
        'label' => t('Dialog box title'),
        'description' => t('The title of the <em>dialog box</em> that pops up.  This bears no correlation to the actual request sent to the user.  Wrap javascript variables in {curly braces}.  Optional.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'app_request_message' => array(
        'type' => 'text',
        'label' => t('App Request Message'),
        'description' => t('The message that will appear alongside the app request.  Wrap javascript variables in {curly braces}.'),
        'default mode' => 'input',
      ),
      'app_request_selector' => array(
        'type' => 'text',
        'label' => t('Only fire if a user clicks on an element with this class / id:'),
        'description' => t('If you define a class (.class) or ID (#id) here, the dialog box will only appear when they click on that element.'),
        'default mode' => 'input',
        'optional' => TRUE
      ),
      'app_request_require_login' => array(
        'type' => 'boolean',
        'label' => t('Require a user to log in to Facebook if they aren\'t already?'),
        'description' => t('If a user is not logged in to Facebook, ask them to log in.  Otherwise nothing will happen if they are not logged into Facebook.'),
        'default value' => 1,
        'optional' => TRUE
      ),
    ),
    'group' => t('Facebook Connections'),
  );
  
  return $items;
}

