<?php

/**
* @file
*  Template file for Create and Share campaigns (e.g. Pics for Pets, Craziest Thing)
*/

?>

<?php if ($utility = render($page['utility'])): ?>
  <div id="utility-bar">
      <div class="container">
          <?php print $utility; ?>
      </div>
  </div>
<?php endif; ?>

<div id="page" class="container">
  <header role="banner">
    <?php if (isset($site_name)): ?>
      <?php if (isset($title)): ?>
        <div id="site-name"><strong>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
        </strong></div>
      <?php else: /* Use h1 when the content title is empty */ ?>
        <h1 id="site-name">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
        </h1>
      <?php endif; ?>
    <?php endif; ?>
  </header>

  <div id="main-wrapper" class="clearfix">
    <div role="main">
     <div class="main-inner">
       <?php

       // Messages
       print $messages;

       // Top navigation bar
       print render($page['top_navbar']);

       // Get campaign information.
       if ($campaign = create_and_share_is_campaign_page()) {
         $settings = create_and_share_get_settings($campaign);

         $path = request_path();
         if (!isset($page['content']['system_main']['nodes']) && ($path != $campaign . '/submit')) {
           // View page
           $content = views_embed_view($settings['views']['wrapper'], $settings['views']['time-filters']);
         }
         elseif ($path == $campaign . '/submit') {
           // Submit page
           $node = menu_get_object('node', 1, 'node/' . $settings['campaign_nid']);
           $form = drupal_get_form('webform_client_form_' . $node->nid, $node);
           $content = '<div class="node-create-and-share-campaign">' . drupal_render($form) . '</div>';
         }
         else {
          // Content page
          $content = render($page['content']);
         }

         echo $content;
        }
       ?>
     </div>
    </div> <!-- /#main -->
  </div> <!-- /#main-wrapper -->
</div>
