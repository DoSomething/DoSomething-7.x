<div id="webform-subscribe-report">
  <p>A report of external services (MailChimp and Mobile Commons) forms with the related group assignments for submissions.</p>
  <?php print(drupal_render(drupal_get_form('dosomething_subscribe_webform_search_form', $_GET['search'], $_GET['sort'], $_GET['order']))); ?>
  <p>
    <?php print($forms_listing); ?>
  </p>
</div>