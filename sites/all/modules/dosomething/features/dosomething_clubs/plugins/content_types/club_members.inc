
<?php

/*************************
 * ADD A REMOVE ME BUTTON
 **************************/

function dosomething_clubs_club_members_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Dosomething Club Members'),
    'description' => t('Club members popup module'),
    'category' => t('DoSomething'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
  );
}

function dosomething_clubs_club_members_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $block = new stdClass();
  $block->title = 'Club Members';

  drupal_add_library('system', 'drupal.ajax');
  drupal_add_js(drupal_get_path('module', 'dosomething_clubs') . '/js/club-ajax.js');
  drupal_add_css(drupal_get_path('module', 'dosomething_clubs') . '/css/clubs-addons.css', array(
         'group' => CSS_THEME,
         'weight' => 100
       ));

  $gid = og_get_group('node', $context->data->nid)->gid;
  $user_membership = og_get_group_membership($gid, 'user', $user->uid);

  $og_admin = user_access('administer group');
  $is_member = og_is_member($gid) || $og_admin;
  $is_admin = dosomething_clubs_is_club_admin($gid);

  $mt = new EntityFieldQuery();
  $memberships_titles = $mt
    ->entityCondition('entity_type', 'og_membership')
    ->propertyCondition('gid', $gid)
    ->propertyCondition('entity_type', 'user')
    ->fieldCondition('field_membership_description', 'value', 'NULL', '!=')
    ->execute();

    if (!empty($membership_titles)) {
      $titles = array_keys(reset($memberships_titles));
    }
    else {
      $titles = array(0);
    }

    if (empty($memberships_titles)) {
      $memberships_titles = array();
    }

  $mnt = new EntityFieldQuery();
  $memberships_no_titles = $mnt
    ->entityCondition('entity_type', 'og_membership')
    ->propertyCondition('gid', $gid)
    ->propertyCondition('entity_type', 'user')
    ->propertyCondition('id', $titles, 'NOT IN')
    ->execute();

  if (empty($memberships_no_titles)) {
    $memberships_no_titles = array();
  }

  $members = array();
  if (!empty($memberships_titles)) {
    $members += reset($memberships_titles);
  }
  if (!empty($memberships_no_titles)) {
    $members += reset($memberships_no_titles);
  }

  $memberships = entity_load('og_membership', array_keys($members));

  $member_list['member_list'] = array('#type' => 'container', '#attributes' => array());
  $member_list['member_list']['current_members'] = array('#theme' => 'table', '#rows' => array(), '#attributes' => array('id' => 'member-list-current'));
  $member_list['member_list']['pending_members'] = array('#theme' => 'table', '#rows' => array(), '#attributes' => array('id' => 'member-list-pending'));

  // Convenience array
  $accessor = array(
    OG_STATE_ACTIVE => &$member_list['member_list']['current_members'],
    OG_STATE_PENDING => &$member_list['member_list']['pending_members'],
  );

  $owner = $context->data->uid;
  foreach ($memberships as $membership) {
    $row = array(
      'data' => array(
        array(
          'data' => array(
            'name' => array(
              '#markup' => dosomething_clubs_member_icon($membership->etid) . '</h2>' . ($membership->etid == $owner ? '<div class="club-owner-label">' . t('Club Leader') . '</div>' : '') . ($membership->etid == $user->uid ? '<div>(This is you)</div>' : ''),
              '#prefix' => '<h2>',
              '#suffix' => '</h2>',
            ),
            'title' => array(
              '#markup' => $membership->field_membership_description[LANGUAGE_NONE][0]['value'],
              '#prefix' => '<div class="member-title" id="member-title-'.$membership->etid.'">',
              '#suffix' => '</div>',
            ),
          ),
          'class' => array('member-name'),
        ),
      ),
      'id' => 'club-member-'.$membership->etid,
    );

    if ($membership->state == OG_STATE_ACTIVE && $is_admin) {
      $base = array('fragment' => ' ', 'external' => TRUE);

      $links = array();
      $links[] = l(t('Update title'), '',  array('attributes' => array('class' => array('member-title-update')))+$base);
      if ($membership->etid <> $user->uid && $membership->etid <> $owner) {
        $links[] = l(t('Delete member'), '', array('attributes' => array('class' => array('member-delete')))+$base);
      }
      if ($owner <> $membership->etid) {
        $links[] = dosomething_clubs_role_link($gid, $membership->etid);
      }
      if (($og_admin || $is_admin || user_access('administer group', $user)) && $owner <> $membership->etid) {
        $addclass = '';
        if ($owner == $user->uid) {
          $addclass = ' to-user-from-admin';
        }
        else {
          $addclass = ' to-user';
        }

        $links[] = l(t('Make Club Leader'), 'club_admin/change-owner/nojs/' . $gid . '/' . $membership->etid, array('attributes' => array('class' => array('member-change-owner' . $addclass))));
      }
      
      $row['data'][] = array(
        'data' => implode('<br />', $links),
        'class' => array('member-manage-links'),
      );

      if ($membership->etid == $owner) {
        $row['data'][1]['class'][0] .= ' club-leader';
      }

      $forms = array();
      $forms[] = drupal_get_form('dosomething_clubs_member_title_form', $gid, $membership->etid);
      $forms[] = drupal_get_form('dosomething_clubs_member_delete_form', $gid, $membership->etid);
      $row['data'][] = array(
        'data' => $forms,
        'class' => 'response-box'
      );
    }
    else if ($membership->state == OG_STATE_PENDING && $is_member) {
      $link = "club_admin/approve/nojs/$gid/{$membership->etid}";
      $row['data'][] = array(
        'data' => l(t('Approve'), $link, array('attributes' => array('class' => 'use-ajax'))),
      );
    }
    else {
      $row['data'][] = array(
        'data' => ''
      );
    }
    $accessor[$membership->state]['#rows'][] = $row;
  }

  $block->content[] = $member_list;
  return $block;
}
