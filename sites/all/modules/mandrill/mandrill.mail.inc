<?php

/**
 * @file
 * Implements Mandrill as a Drupal MailSystemInterface
 */

/**
 * Modify the drupal mail system to use Mandrill when sending emails.
 */
class MandrillMailSystem implements MailSystemInterface {

  /**
   * Concatenate and wrap the email body for either
   * plain-text or HTML emails.
   *
   * @param $message
   *   A message array, as described in hook_mail_alter().
   *
   * @return
   *   The formatted $message.
   */
  public function format(array $message) {
    // Join the body array into one string.
    if (is_array($message['body'])) {
      $message['body'] = implode("\n\n", $message['body']);
    }
    return $message;
  }

  /**
   * Send the email message.
   *
   * @see drupal_mail()
   *
   * @param $message
   *   A message array, as described in hook_mail_alter(). There are several
   *   optional values that can be passed in to change the way Mandrill handles
   *   the email:
   *   * 'attachments' - Array of file names to include in the message as
   *     attachments.
   *   * 'mandrill_global_merge_vars' - An array of global merge vars keyed by
   *     variable name.
   *   * 'mandrill_merge_vars' - Array of merge vars keyed by recipient's email
   *     address with a sub array keyed by variable name.
   *   * 'mandrill_template' - The name of an HTML template to use to send the
   *     message. If this is not provided the site default will be used.
   *   * 'mandrill_template_content' - Array of content keyed by the name of
   *     the mc:edit region. The message's HTML body will be put into the 'main'
   *     region by default.
   *
   * @return
   *   TRUE if the mail was successfully accepted, otherwise FALSE.
   */
  public function mail(array $message) {
    if (!$from = variable_get('mandrill_from', '')) {
      drupal_set_message(t('Mandrill can\'t send email. Please !link.',
        array(
          '!link' => l('add a verified from address',
            'admin/config/services/mandrill'
          )
        )
      ), 'error');
      return FALSE;
    }

    $mailer = mandrill_get_api_object();

    // Apply input format to body.
    $html = $message['body'];
    $format = variable_get('mandrill_filter_format', '');
    if (!empty($format)) {
      $html = check_markup($message['body'], $format);
    }

    // Plug some default values into the message so we can avoid a bunch of
    // isset()'s later.
    $message += array(
      'attachments' => array(),
      'mandrill_global_merge_vars' => array(),
      'mandrill_merge_vars' => array(),
      'mandrill_template' => variable_get('mandrill_template', ''),
      'mandrill_template_content' => array(),
    );
    $message['mandrill_merge_vars'] += array(
      'subject' => $message['subject'],
    );
    $message['mandrill_template_content'] += array(
      'main' => $html,
    );

    $attachments = array();
    foreach ($message['attachments'] as $attachment) {
      if (is_file($attachment)) {
        $attachments[] = $mailer->getAttachmentStruct($attachment);
      }
    }

    // Flip the merge values into the appropriate format.
    $global_merge_vars = array();
    foreach ($message['mandrill_global_merge_vars'] as $name => $content) {
      $global_merge_vars[] = array('name' => $name, 'content' => $content);
    }
    $merge_vars = array();
    if (!empty($message['mandrill_merge_vars'])) {
      foreach ($message['mandrill_merge_vars'] as $rcpt => $v) {
        $vars = array();
        foreach ($v as $name => $content) {
          $vars[] = array('name' => $name, 'content' => $content);
        }
        $merge_vars[] = array('rcpt' => $rcpt, 'vars' => $vars);
      }
    }

    $mandrill_message = array(
      'html' => $html,
      'text' => drupal_html_to_text($message['body']),
      'subject' => $message['subject'],
      'from_name' => variable_get('mandrill_from_name', ''),
      'from_email' => $from,
      'to' => mandrill_get_to($message['to']),
      'global_merge_vars' => $global_merge_vars,
      'merge_vars' => $merge_vars,
      // optional extra headers to add to the message (currently only Reply-To and X-* headers are allowed)
      'headers' => $message['headers'],
      'track_opens' => variable_get('mandrill_track_opens', TRUE),
      'track_clicks' => variable_get('mandrill_track_clicks', TRUE),
      // we're handling this with drupal_html_to_text().
      'auto_text' => FALSE,
      'url_strip_qs' => variable_get('mandrill_url_strip_qs', FALSE),
      'bcc_address' => isset($message['bcc_email']) ? $message['bcc_email'] : NULL,
      // send the email passing the message id as the tag for use in reporting.
      'tags' => array($message['id']),
      'google_analytics_domains' => (variable_get('mandrill_analytics_domains', NULL)) ? explode(',', variable_get('mandrill_analytics_domains')) : array(),
      'google_analytics_campaign' => variable_get('mandrill_analytics_campaign', ''),
      'attachments' => $attachments
    );

    drupal_alter('mandrill_mail', $mandrill_message, $message);

    try {
      // Allow the message override the default template and content.
      $template_name = $message['mandrill_template'];
      $template_content = array();
      foreach ($message['mandrill_template_content'] as $name => $content) {
        $template_content[] = array('name' => $name, 'content' => $content);
      }

      // If we've got a template and content use it.
      if ($template_name && $template_content) {
        $result = $mailer->messages_send_template($template_name, $template_content, $mandrill_message);
      }
      else {
        $result = $mailer->messages_send($mandrill_message);
      }

      // @todo: look for rejected messages and log
      return TRUE;
    }
    catch (Mandrill_Exception $e) {
      watchdog('mandrill', 'Error sending email from %from to %to. @code: @message',
        array(
          '%from' => $from,
          '%to' => $message['to'],
          '@code' => $e->getCode(),
          '@message' => $e->getMessage(),
        ),
        WATCHDOG_ERROR
      );

      return FALSE;
    }
  }

}

/**
 * A mail sending implementation that captures sent messages to watchdog.
 *
 * This class is for running tests or for development.
 */
class TestingMandrillMailSystem extends MandrillMailSystem implements MailSystemInterface {

  /**
   * Accept an e-mail message and store it in a variable.
   *
   * @param $message
   *   An e-mail message.
   */
  public function mail(array $message) {
    if (!$from = variable_get('mandrill_from', '')) {
      drupal_set_message(t('Mandrill can\'t send email. Please !link.',
        array(
          '!link' => l('add a verified from address',
            'admin/config/services/mailchimp/sts'
          )
        )
      ), 'error');
      return FALSE;
    }
    $to = mandrill_get_to($message['to']);

    watchdog('mandrill', 'Mandrill test email sent from %from to %to. Message: <pre>@message</pre>',
      array(
        '%from' => $from, '%to' => $to[0]['email'],
	      '@message' => print_r($message, TRUE),
      ),
      WATCHDOG_NOTICE
    );

    drupal_set_message(t('Mandrill test email sent from %from to %to.',
      array('%from' => $from, '%to' => $to[0]['email'])
    ), 'notice');
    return TRUE;
  }
}

/**
 * Helper to generate an array of recipients.
 *
 * @param mixed $to
 *
 * @return array
 */
function mandrill_get_to($to) {
  //@todo: extract name and add to associative array.

  $recipients = array();
  if ($to_array = explode(',', $to)) {
    foreach ($to_array as $email) {
      $recipients[] = array('email' => $email);
    }
  }
  else {
    $recipients[] = array('email' => $to);
  }
  return $recipients;
}

