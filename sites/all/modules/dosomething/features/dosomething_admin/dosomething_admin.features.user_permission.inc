<?php
/**
 * @file
 * dosomething_admin.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dosomething_admin_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'system',
  );

  // Exported permission: access all webform results.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'webform',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: access own webform results.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: access own webform submissions.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'webform',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'user',
  );

  // Exported permission: add media from remote sources.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: administer all queues.
  $permissions['administer all queues'] = array(
    'name' => 'administer all queues',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds product team',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: administer files.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: administer imce.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'imce',
  );

  // Exported permission: administer nodequeue.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds product team',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: administer optimizely.
  $permissions['administer optimizely'] = array(
    'name' => 'administer optimizely',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds product team',
    ),
    'module' => 'optimizely',
  );

  // Exported permission: administer profiles.
  $permissions['administer profiles'] = array(
    'name' => 'administer profiles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds product team',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: administer url aliases.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create action_guide content.
  $permissions['create action_guide content'] = array(
    'name' => 'create action_guide content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create bc_bio_form content.
  $permissions['create bc_bio_form content'] = array(
    'name' => 'create bc_bio_form content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create blog content.
  $permissions['create blog content'] = array(
    'name' => 'create blog content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create campaign_content_page content.
  $permissions['create campaign_content_page content'] = array(
    'name' => 'create campaign_content_page content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create club_event content.
  $permissions['create club_event content'] = array(
    'name' => 'create club_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create dsaward_rec content.
  $permissions['create dsaward_rec content'] = array(
    'name' => 'create dsaward_rec content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create final_grant_update content.
  $permissions['create final_grant_update content'] = array(
    'name' => 'create final_grant_update content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create grant_application content.
  $permissions['create grant_application content'] = array(
    'name' => 'create grant_application content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create help_ticket content.
  $permissions['create help_ticket content'] = array(
    'name' => 'create help_ticket content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create member_opportunity content.
  $permissions['create member_opportunity content'] = array(
    'name' => 'create member_opportunity content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create page content.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create petition content.
  $permissions['create petition content'] = array(
    'name' => 'create petition content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create poll content.
  $permissions['create poll content'] = array(
    'name' => 'create poll content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create press content.
  $permissions['create press content'] = array(
    'name' => 'create press content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create project content.
  $permissions['create project content'] = array(
    'name' => 'create project content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create quiz content.
  $permissions['create quiz content'] = array(
    'name' => 'create quiz content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create scroller content.
  $permissions['create scroller content'] = array(
    'name' => 'create scroller content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create share_of_day content.
  $permissions['create share_of_day content'] = array(
    'name' => 'create share_of_day content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create social_scholarship content.
  $permissions['create social_scholarship content'] = array(
    'name' => 'create social_scholarship content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create sponsor content.
  $permissions['create sponsor content'] = array(
    'name' => 'create sponsor content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create tips_and_tools content.
  $permissions['create tips_and_tools content'] = array(
    'name' => 'create tips_and_tools content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create url aliases.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'path',
  );

  // Exported permission: create webform content.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete all webform submissions.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: delete any action_guide content.
  $permissions['delete any action_guide content'] = array(
    'name' => 'delete any action_guide content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any bc_bio_form content.
  $permissions['delete any bc_bio_form content'] = array(
    'name' => 'delete any bc_bio_form content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any blog content.
  $permissions['delete any blog content'] = array(
    'name' => 'delete any blog content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any campaign_content_page content.
  $permissions['delete any campaign_content_page content'] = array(
    'name' => 'delete any campaign_content_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any club_event content.
  $permissions['delete any club_event content'] = array(
    'name' => 'delete any club_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any dsaward_rec content.
  $permissions['delete any dsaward_rec content'] = array(
    'name' => 'delete any dsaward_rec content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any final_grant_update content.
  $permissions['delete any final_grant_update content'] = array(
    'name' => 'delete any final_grant_update content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any grant_application content.
  $permissions['delete any grant_application content'] = array(
    'name' => 'delete any grant_application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any help_ticket content.
  $permissions['delete any help_ticket content'] = array(
    'name' => 'delete any help_ticket content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any member_opportunity content.
  $permissions['delete any member_opportunity content'] = array(
    'name' => 'delete any member_opportunity content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any petition content.
  $permissions['delete any petition content'] = array(
    'name' => 'delete any petition content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any poll content.
  $permissions['delete any poll content'] = array(
    'name' => 'delete any poll content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any press content.
  $permissions['delete any press content'] = array(
    'name' => 'delete any press content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any project content.
  $permissions['delete any project content'] = array(
    'name' => 'delete any project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any quiz content.
  $permissions['delete any quiz content'] = array(
    'name' => 'delete any quiz content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any scroller content.
  $permissions['delete any scroller content'] = array(
    'name' => 'delete any scroller content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any share_of_day content.
  $permissions['delete any share_of_day content'] = array(
    'name' => 'delete any share_of_day content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any social_scholarship content.
  $permissions['delete any social_scholarship content'] = array(
    'name' => 'delete any social_scholarship content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any sponsor content.
  $permissions['delete any sponsor content'] = array(
    'name' => 'delete any sponsor content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any tips_and_tools content.
  $permissions['delete any tips_and_tools content'] = array(
    'name' => 'delete any tips_and_tools content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any webform content.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own action_guide content.
  $permissions['delete own action_guide content'] = array(
    'name' => 'delete own action_guide content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own bc_bio_form content.
  $permissions['delete own bc_bio_form content'] = array(
    'name' => 'delete own bc_bio_form content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own blog content.
  $permissions['delete own blog content'] = array(
    'name' => 'delete own blog content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own campaign_content_page content.
  $permissions['delete own campaign_content_page content'] = array(
    'name' => 'delete own campaign_content_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own club_event content.
  $permissions['delete own club_event content'] = array(
    'name' => 'delete own club_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own dsaward_rec content.
  $permissions['delete own dsaward_rec content'] = array(
    'name' => 'delete own dsaward_rec content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own final_grant_update content.
  $permissions['delete own final_grant_update content'] = array(
    'name' => 'delete own final_grant_update content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own grant_application content.
  $permissions['delete own grant_application content'] = array(
    'name' => 'delete own grant_application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own help_ticket content.
  $permissions['delete own help_ticket content'] = array(
    'name' => 'delete own help_ticket content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own member_opportunity content.
  $permissions['delete own member_opportunity content'] = array(
    'name' => 'delete own member_opportunity content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own petition content.
  $permissions['delete own petition content'] = array(
    'name' => 'delete own petition content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own poll content.
  $permissions['delete own poll content'] = array(
    'name' => 'delete own poll content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own press content.
  $permissions['delete own press content'] = array(
    'name' => 'delete own press content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own project content.
  $permissions['delete own project content'] = array(
    'name' => 'delete own project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own quiz content.
  $permissions['delete own quiz content'] = array(
    'name' => 'delete own quiz content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own scroller content.
  $permissions['delete own scroller content'] = array(
    'name' => 'delete own scroller content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own share_of_day content.
  $permissions['delete own share_of_day content'] = array(
    'name' => 'delete own share_of_day content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own social_scholarship content.
  $permissions['delete own social_scholarship content'] = array(
    'name' => 'delete own social_scholarship content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own tips_and_tools content.
  $permissions['delete own tips_and_tools content'] = array(
    'name' => 'delete own tips_and_tools content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own webform content.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own webform submissions.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: edit Open Graph meta tags.
  $permissions['edit Open Graph meta tags'] = array(
    'name' => 'edit Open Graph meta tags',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'opengraph_meta',
  );

  // Exported permission: edit all webform submissions.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'webform',
  );

  // Exported permission: edit any action_guide content.
  $permissions['edit any action_guide content'] = array(
    'name' => 'edit any action_guide content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any bc_bio_form content.
  $permissions['edit any bc_bio_form content'] = array(
    'name' => 'edit any bc_bio_form content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any blog content.
  $permissions['edit any blog content'] = array(
    'name' => 'edit any blog content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any campaign_content_page content.
  $permissions['edit any campaign_content_page content'] = array(
    'name' => 'edit any campaign_content_page content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any club_event content.
  $permissions['edit any club_event content'] = array(
    'name' => 'edit any club_event content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any dsaward_rec content.
  $permissions['edit any dsaward_rec content'] = array(
    'name' => 'edit any dsaward_rec content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any final_grant_update content.
  $permissions['edit any final_grant_update content'] = array(
    'name' => 'edit any final_grant_update content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any grant_application content.
  $permissions['edit any grant_application content'] = array(
    'name' => 'edit any grant_application content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any help_ticket content.
  $permissions['edit any help_ticket content'] = array(
    'name' => 'edit any help_ticket content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any main profile.
  $permissions['edit any main profile'] = array(
    'name' => 'edit any main profile',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: edit any member_opportunity content.
  $permissions['edit any member_opportunity content'] = array(
    'name' => 'edit any member_opportunity content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any petition content.
  $permissions['edit any petition content'] = array(
    'name' => 'edit any petition content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any poll content.
  $permissions['edit any poll content'] = array(
    'name' => 'edit any poll content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any press content.
  $permissions['edit any press content'] = array(
    'name' => 'edit any press content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any project content.
  $permissions['edit any project content'] = array(
    'name' => 'edit any project content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any quiz content.
  $permissions['edit any quiz content'] = array(
    'name' => 'edit any quiz content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any scroller content.
  $permissions['edit any scroller content'] = array(
    'name' => 'edit any scroller content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any share_of_day content.
  $permissions['edit any share_of_day content'] = array(
    'name' => 'edit any share_of_day content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any social_scholarship content.
  $permissions['edit any social_scholarship content'] = array(
    'name' => 'edit any social_scholarship content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any sponsor content.
  $permissions['edit any sponsor content'] = array(
    'name' => 'edit any sponsor content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any tips_and_tools content.
  $permissions['edit any tips_and_tools content'] = array(
    'name' => 'edit any tips_and_tools content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any webform content.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit file.
  $permissions['edit file'] = array(
    'name' => 'edit file',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit own member_opportunity content.
  $permissions['edit own member_opportunity content'] = array(
    'name' => 'edit own member_opportunity content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own petition content.
  $permissions['edit own petition content'] = array(
    'name' => 'edit own petition content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own project content.
  $permissions['edit own project content'] = array(
    'name' => 'edit own project content',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own webform submissions.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'webform',
  );

  // Exported permission: edit terms in 26.
  $permissions['edit terms in 26'] = array(
    'name' => 'edit terms in 26',
    'roles' => array(
      0 => 'ds staff',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: flush caches.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: manipulate all queues.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds product team',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: manipulate queues.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds product team',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: schedule (un)publishing of nodes.
  $permissions['schedule (un)publishing of nodes'] = array(
    'name' => 'schedule (un)publishing of nodes',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: use text format 1.
  $permissions['use text format 1'] = array(
    'name' => 'use text format 1',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'ds staff',
      4 => 'grant reviewer',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format 3.
  $permissions['use text format 3'] = array(
    'name' => 'use text format 3',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format 5.
  $permissions['use text format 5'] = array(
    'name' => 'use text format 5',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format editor_html.
  $permissions['use text format editor_html'] = array(
    'name' => 'use text format editor_html',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'filter',
  );

  // Exported permission: view any campaign_contact_form webform submissions.
  $permissions['view any campaign_contact_form webform submissions'] = array(
    'name' => 'view any campaign_contact_form webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any campaign_report_back webform submissions.
  $permissions['view any campaign_report_back webform submissions'] = array(
    'name' => 'view any campaign_report_back webform submissions',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any campaign_sign_up webform submissions.
  $permissions['view any campaign_sign_up webform submissions'] = array(
    'name' => 'view any campaign_sign_up webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any grant_application webform submissions.
  $permissions['view any grant_application webform submissions'] = array(
    'name' => 'view any grant_application webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any grant_judge webform submissions.
  $permissions['view any grant_judge webform submissions'] = array(
    'name' => 'view any grant_judge webform submissions',
    'roles' => array(),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any main profile.
  $permissions['view any main profile'] = array(
    'name' => 'view any main profile',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'profile2',
  );

  // Exported permission: view any petition webform submissions.
  $permissions['view any petition webform submissions'] = array(
    'name' => 'view any petition webform submissions',
    'roles' => array(),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any program_short_form webform submissions.
  $permissions['view any program_short_form webform submissions'] = array(
    'name' => 'view any program_short_form webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any project_report webform submissions.
  $permissions['view any project_report webform submissions'] = array(
    'name' => 'view any project_report webform submissions',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any scholarship_application webform submissions.
  $permissions['view any scholarship_application webform submissions'] = array(
    'name' => 'view any scholarship_application webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any scholarship_application_with_rec webform submissions.
  $permissions['view any scholarship_application_with_rec webform submissions'] = array(
    'name' => 'view any scholarship_application_with_rec webform submissions',
    'roles' => array(),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any scholarship_recommendation webform submissions.
  $permissions['view any scholarship_recommendation webform submissions'] = array(
    'name' => 'view any scholarship_recommendation webform submissions',
    'roles' => array(),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any scholarship_recommendation_reque webform submissions.
  $permissions['view any scholarship_recommendation_reque webform submissions'] = array(
    'name' => 'view any scholarship_recommendation_reque webform submissions',
    'roles' => array(),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any social_scholarship webform submissions.
  $permissions['view any social_scholarship webform submissions'] = array(
    'name' => 'view any social_scholarship webform submissions',
    'roles' => array(),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any team_challenge webform submissions.
  $permissions['view any team_challenge webform submissions'] = array(
    'name' => 'view any team_challenge webform submissions',
    'roles' => array(),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view any webform webform submissions.
  $permissions['view any webform webform submissions'] = array(
    'name' => 'view any webform webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'ds staff',
    ),
    'module' => 'node',
  );

  // Exported permission: view own webform submissions.
  $permissions['view own webform submissions'] = array(
    'name' => 'view own webform submissions',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'webform_entity_pages',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      0 => 'administrator',
      1 => 'ds staff',
    ),
    'module' => 'system',
  );

  return $permissions;
}