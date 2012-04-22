<?php
/**
 * @file
 * dosomething_blog.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dosomething_blog_field_default_fields() {
  $fields = array();

  // Exported field: 'node-blog-body'
  $fields['node-blog-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'blog',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => '200',
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => 0,
      'settings' => array(
        'display_summary' => 1,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-blog-field_blog_type'
  $fields['node-blog-field_blog_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_blog_type',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'blog_type',
            'parent' => '0',
          ),
        ),
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'blog',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_blog_type',
      'label' => 'Blog type',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-blog-field_embedded_video'
  $fields['node-blog-field_embedded_video'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_embedded_video',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'mediafield',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'media',
      'type_name' => 'sixflags_scholarships_app',
    ),
    'field_instance' => array(
      'bundle' => 'blog',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'mediafield',
          'settings' => array(
            'file_view_mode' => 'media_large',
          ),
          'type' => 'media',
          'weight' => '-1',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'mediafield',
          'settings' => array(
            'file_view_mode' => 'media_large',
          ),
          'type' => 'media',
          'weight' => '-1',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'mediafield',
          'settings' => array(
            'file_view_mode' => 'media_large',
          ),
          'type' => 'media',
          'weight' => '-1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_embedded_video',
      'label' => 'Video',
      'required' => 0,
      'settings' => array(
        'file_extensions' => 'jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp mp3 mov m4v mp4 mpeg avi ogg wmv ico',
        'user_register_form' => FALSE,
      ),
      'weight' => '-1',
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'public' => 'public',
            'vimeo' => 'vimeo',
            'youtube' => 'youtube',
          ),
          'allowed_types' => array(
            'audio' => 0,
            'default' => 0,
            'image' => 0,
            'video' => 'video',
          ),
          'browser_plugins' => array(
            'library' => 0,
            'media_default--media_browser_1' => 0,
            'media_internet' => 0,
            'upload' => 0,
          ),
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-blog-field_picture'
  $fields['node-blog-field_picture'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_picture',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'description_field' => '0',
        'list_default' => 1,
        'list_field' => '0',
        'profile2_private' => FALSE,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
      'type_name' => 'tips_and_tools',
    ),
    'field_instance' => array(
      'bundle' => 'blog',
      'default_value' => '',
      'deleted' => '0',
      'description' => 'The first picture will show up on the Blog Center page.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'imagecache_proportions',
          'settings' => array(
            'enable_link' => 'none',
            'horizontal_preset' => 'blog_landscape',
            'looseness' => '0',
            'modal_style' => '',
            'squared_preset' => 'blog_square',
            'style' => '',
            'vertical_preset' => 'blog_portrait',
          ),
          'type' => 'vertical_horizontal',
          'weight' => '-2',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '-2',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'content',
            'image_style' => 'blog_large_thumbnail',
          ),
          'type' => 'image',
          'weight' => '-2',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_picture',
      'label' => 'Picture(s)',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'file_directory' => 'pictures/blog',
        'file_extensions' => 'jpg jpeg png gif',
        'max_filesize' => '0',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'weight' => '-2',
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => 'image_blog_landscape',
          'insert_styles' => array(
            'auto' => 0,
            'image' => 0,
            'image_action_results_thumbnail' => 0,
            'image_blog_landscape' => 0,
            'image_blog_large_image' => 0,
            'image_blog_large_thumbnail' => 0,
            'image_blog_portrait' => 0,
            'image_blog_square' => 0,
            'image_campaign_microsite_logo' => 0,
            'image_campaign_report_back_style' => 0,
            'image_campaigns_image' => 0,
            'image_campaigns_logo' => 0,
            'image_cause_main' => 0,
            'image_cause_vertical' => 0,
            'image_club_profile' => 0,
            'image_content_main' => 0,
            'image_explore_action_guides' => 0,
            'image_front_slider' => 0,
            'image_grants_landing' => 0,
            'image_issue_main' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_member_photo_gallery' => 0,
            'image_my_somethings' => 0,
            'image_nav_page_bottom' => 0,
            'image_project_gallery_thumb' => 0,
            'image_project_related_thumb' => 0,
            'image_related-posts' => 0,
            'image_rotoslider_homepage_main' => 0,
            'image_rotoslider_nav' => 0,
            'image_rotoslider_start_something_main' => 0,
            'image_sponsor_logo' => 0,
            'image_square_thumbnail' => 0,
            'image_thumbnail' => 0,
            'image_tips_tools_node' => 0,
            'image_upcoming_somethings_thumb' => 0,
            'image_whats_happening_now_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '4',
      ),
      'widget_type' => 'imagefield_widget',
    ),
  );

  // Exported field: 'node-blog-field_subtitle'
  $fields['node-blog-field_subtitle'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_subtitle',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'blog',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'A subtitle for use on the News & Stuff homepage section.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_subtitle',
      'label' => 'Subtitle',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-blog-taxonomy_vocabulary_11'
  $fields['node-blog-taxonomy_vocabulary_11'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'taxonomy_vocabulary_11',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'vocabulary_11',
            'parent' => 0,
          ),
        ),
        'required' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'blog',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '10',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'taxonomy_vocabulary_11',
      'label' => 'Charity',
      'required' => '0',
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-blog-taxonomy_vocabulary_5'
  $fields['node-blog-taxonomy_vocabulary_5'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'taxonomy_vocabulary_5',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'vocabulary_5',
            'parent' => '0',
          ),
        ),
        'profile2_private' => 1,
        'required' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'blog',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'hold down ctrl button to select more than one',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '10',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'taxonomy_vocabulary_5',
      'label' => 'Issues',
      'required' => '0',
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-blog-taxonomy_vocabulary_6'
  $fields['node-blog-taxonomy_vocabulary_6'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'taxonomy_vocabulary_6',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'vocabulary_6',
            'parent' => 0,
          ),
        ),
        'required' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'blog',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '10',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'taxonomy_vocabulary_6',
      'label' => 'Celebrity Name Tags',
      'required' => '0',
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-blog-upload'
  $fields['node-blog-upload'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'upload',
      'field_permissions' => array(
        'type' => '0',
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'file',
      'settings' => array(
        'default_file' => 0,
        'display_default' => '1',
        'display_field' => 1,
        'profile2_private' => FALSE,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'blog',
      'deleted' => '0',
      'description' => 'These images or files can be optionally inserted into the body text. Be sure to uncheck \'Display\' for images you insert into the text.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_table',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_table',
          'weight' => 0,
        ),
        'rss' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_table',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'upload',
      'label' => 'File attachments',
      'required' => 0,
      'settings' => array(
        'description_field' => 1,
        'file_directory' => 'pictures/blog',
        'file_extensions' => 'jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp mp4 mov mp3 php3',
        'max_filesize' => '8 MB',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'file',
        'settings' => array(
          'insert' => 1,
          'insert_class' => '',
          'insert_default' => 'image_blog_landscape',
          'insert_styles' => array(
            'auto' => 0,
            'image' => 'image',
            'image_action_results_thumbnail' => 0,
            'image_blog_landscape' => 'image_blog_landscape',
            'image_blog_large_image' => 0,
            'image_blog_large_thumbnail' => 0,
            'image_blog_portrait' => 'image_blog_portrait',
            'image_blog_square' => 'image_blog_square',
            'image_campaign_microsite_logo' => 0,
            'image_campaign_report_back_style' => 0,
            'image_campaigns_image' => 0,
            'image_campaigns_logo' => 0,
            'image_cause_main' => 0,
            'image_cause_vertical' => 0,
            'image_club_profile' => 0,
            'image_content_main' => 0,
            'image_explore_action_guides' => 0,
            'image_front_slider' => 0,
            'image_grants_landing' => 0,
            'image_issue_main' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_member_photo_gallery' => 0,
            'image_my_somethings' => 0,
            'image_nav_page_bottom' => 0,
            'image_project_gallery_thumb' => 0,
            'image_project_related_thumb' => 0,
            'image_related-posts' => 0,
            'image_rotoslider_homepage_main' => 0,
            'image_rotoslider_nav' => 0,
            'image_rotoslider_start_something_main' => 0,
            'image_sponsor_logo' => 0,
            'image_square_thumbnail' => 0,
            'image_thumbnail' => 0,
            'image_tips_tools_node' => 0,
            'image_upcoming_somethings_thumb' => 0,
            'image_whats_happening_now_thumbnail' => 0,
            'link' => 'link',
          ),
          'insert_width' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-blog_type-field_blog_icon'
  $fields['taxonomy_term-blog_type-field_blog_icon'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_blog_icon',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'profile2_private' => FALSE,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'blog_type',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'token' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_blog_icon',
      'label' => 'Blog Icon',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'file_directory' => 'blog/icons',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => array(
            0 => 'auto',
          ),
          'insert_styles' => array(
            0 => 'auto',
          ),
          'insert_width' => '',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '1',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A subtitle for use on the News & Stuff homepage section.');
  t('Blog Icon');
  t('Blog type');
  t('Body');
  t('Celebrity Name Tags');
  t('Charity');
  t('File attachments');
  t('Issues');
  t('Picture(s)');
  t('Subtitle');
  t('The first picture will show up on the Blog Center page.');
  t('These images or files can be optionally inserted into the body text. Be sure to uncheck \'Display\' for images you insert into the text.');
  t('Video');
  t('hold down ctrl button to select more than one');

  return $fields;
}
