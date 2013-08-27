<?php 
/**
 * @file
 * Page callbacks for the dosomething_profile module.
 */

/**
 * Page callback to display given user's basic info and profile data.
 */
function dosomething_profile_info_page($user) {
  $rows = array(
    array('Username', $user->name),
    array('Email', $user->mail),
    array('Status', $user->status),
    array('Last login', format_date($user->login)),
    array('Roles', implode(', ', $user->roles)),
  );
  $profile = profile2_load_by_user($user, 'main');
  $output = theme('table', array('rows' => $rows));
  $output .= render($profile->view('page'));
  return $output;
}
