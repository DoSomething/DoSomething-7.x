<?php

if (module_exists('entity')) {
  $plugin = array(
    'title' => t('Beta Campaign Report Back'),
    'description' => t('Submits report back for the Beta (Cleanup) campaign'),
    'handler' => array('class' => 'ConductorActivityBetaReportBack'),
  );
}
