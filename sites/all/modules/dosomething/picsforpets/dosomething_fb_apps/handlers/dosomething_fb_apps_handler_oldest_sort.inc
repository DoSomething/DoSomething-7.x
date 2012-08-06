<?php
/**
 * @defgroup views_sort_handlers Views' sort handlers
 * @{
 * Handlers to tell Views how to sort queries
 */

/**
 * Base sort handler that has no options and performs a simple sort
 */
class dosomething_fb_apps_handler_oldest_sort extends views_handler_sort {

  /**
   * Called to add the sort to a query.
   */
  function query() {
    $this->ensure_my_table();
    // Add the field.
    $this->query->add_orderby($this->table_alias, $this->real_field, 'ASC');
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['exposed'] = array('default' => FALSE);
    $options['expose'] = array(
      'contains' => array(
        'label' => array('default' => '', 'translatable' => TRUE),
      ),
    );
    return $options;
  }
}




/**
 * @}
 */
