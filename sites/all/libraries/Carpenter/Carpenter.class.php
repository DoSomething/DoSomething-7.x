<?php

/**
 * @file
 * Carpenter is a recursive scanning and copying tool for "scaffolds".
 * What are scaffolds? Scaffolds are groups or files and/or directories
 * that are often used in multiple locations.  Examples: module structures,
 * or file directory structures.  Carpenter allows custom settings, routes,
 * and an unlimited number of individual scaffolds.
 *
 * To create a new scaffold, add a directory of your preferred name, all lowercase
 * and without punctuation, to the "scaffolds" directory found within this library.
 * Add as many files or directories as you wish.  You may use the {scaffold} placeholder
 * within files, and they will be replaced with the name of the directory that is created.
 *
 * ALL scaffold directories must include a "scaffold.inc" file. Within that file there must be
 * an array named $settings:
 * @code
 *   $settings = array(
 *     'dir' => '/path/to/desired/dir', // The path to the directory where the scaffold will be created.
 *     'defaults' => array(
 *       'name' => 'testing_campaign', // The default name, if no name is otherwise set, that the directory will take when created.
 *     ),
 *   );
 * @endcode
 *
 * To run the Carpenter class, use code similar to the following:
 * @code
 *   $builder = new Carpenter('scaffold_name'); // Initiates the Carpenter class.
 *   $builder->set('name', 'testing'); // Sets the name of the directory that will be created.
 *   $builder->build(); // Builds the scaffold.
 * @endcode
 *
 * You can also set replaceable tokens, like so:
 * @code
 *   $builder = new Carpenter('scaffold_name');
 *   $builder->set('name', 'testing');
 *   $builder->setToken('name', 'Mike');
 *   $builder->build();
 * @endcode
 *
 * Given the code above, Carpenter will search for a scaffold named "scaffold_name" within
 * the "scaffolds" directory.  If it finds the scaffold, it loads the scaffold.inc file as
 * described above.  $builder->set('name', 'testing'); overrides the name that the directory
 * will take upon creation.  $builder->build(); actually copies over the files and directories,
 * then searches for the {scaffold} token and, where appropriate, replaces it with the name "testing".
 *
 * @author Michael Chittenden (mchittenden@dosomething.org)
 * @date 4/23/13
 */

class Carpenter {
  // The directory where this class lives.
  private $root_dir = __DIR__;

  // The name of the directory, within $root_dir above, that has the scaffolds.
  private $scaffolds_dir = 'scaffolds';

  // Settings array to store settings from the scaffold.
  private $settings = array();

  // The name of the scaffold we're currently looking at.
  private $scaffold = '';

  // Tokens that should be replaced.
  private $tokens = array('scaffold' => '');

  /**
   * Constructs the Carpenter class.  Loads the settings file and stores
   * data in the $settings property.
   *
   * @param string $name
   *   The name of the scaffold that should be created.
   */
  public function __construct($name) {
    // Does the directory and settings.inc file exists?
    if (is_dir($this->root_dir . '/' . $this->scaffolds_dir . '/' . $name) && file_exists($this->root_dir . '/' . $this->scaffolds_dir . '/' . $name . '/scaffold.inc')) {
      // Yep? Load the settings file.
      require_once $this->root_dir . '/' . $this->scaffolds_dir . '/' . $name . '/scaffold.inc';

      // Remember this scaffold.
      $this->scaffold = $name;

      // Store the settings for later consumption.
      $this->settings = $settings;
      if (!isset($this->settings['name']) && isset($this->settings['defaults']['name'])) {
        $this->settings += array(
          'name' => $settings['defaults']['name'],
        );

        $this->tokens['scaffold'] = $settings['defaults']['name'];
      }
    }
  }

  /**
   * Sets a property, if it exists.
   *
   * @param string $property
   *   The name of the property to overwrite.  Available properties
   *   are chosen from the settings.inc file.
   *
   * @param string $value
   *   The value that the parameter should take.
   */
  public function set($property, $value) {
    if (isset($this->settings[$property])) {
      $this->settings[$property] = $value;
      if ($property == 'name') {
        $this->tokens['scaffold'] = $value;
      }
    }
  }

  /**
   *  Sets a replaceable token.  Tokens will be replaced inside the file.
   *
   *  @param string $token
   *    The token that should be replaced.  Will be wrapped in {} brackets
   *
   *  @param string $value
   *    The value that the token should be replaced with.
   */
  public function setToken($token, $value) {
    $this->tokens[$token] = $value;
  }

  /**
   * Actually copies over the scaffold.
   */
  public function build() {
    // Recursive iterator -- goes through the directory and copies
    // files over to the destination.
    $files = new RecursiveIteratorIterator(
      new RecursiveDirectoryIterator($this->root_dir . '/' . $this->scaffolds_dir . '/' . $this->scaffold, RecursiveDirectoryIterator::SKIP_DOTS),
      RecursiveIteratorIterator::SELF_FIRST
    );

    // Make the scaffold landing directory, if it doesn't exist.
    if (!is_dir($this->settings['dir'] . '/' . $this->settings['name'])) {
      mkdir($this->settings['dir'] . '/' . $this->settings['name']);
    }

    // Loop through all files to copy over to the new location.
    foreach ($files AS $file) {
      // If it's a directory, make that directory.
      if ($file->isDir()) {
        // Let's not overwrite a file that exists.
        if (!is_dir($this->settings['dir'] . '/' . $this->settings['name'] . '/' . $file->getFileName())) {
          mkdir($this->settings['dir'] . '/' . $this->settings['name'] . '/' . $file->getFileName());
        }
      }
      // Otherwise it's a file.  Copy over the file, unless it's a scaffold config file.
      elseif ($file->getFileName() != 'scaffold.inc' && $file->getFileName() != 'scaffold.conf') {
        // Don't overwrite a file that doesn't exist.
        if (!file_exists($this->settings['dir'] . '/' . $this->settings['name'] . '/' . $file->getFileName())) {
          copy($file, $this->settings['dir'] . '/' . $this->settings['name'] . '/' . $file->getFileName());
        }

        // Assuming the file is writeable...
        if (is_writeable($this->settings['dir'] . '/' . $this->settings['name'] . '/' . $file->getFileName())) {
          // Get the contents of the file.
          $contents = file_get_contents($this->settings['dir'] . '/' . $this->settings['name'] . '/' . $file->getFileName());
          // Look for the placeholder.
          preg_match_all('#\{(' . implode('|', array_keys($this->tokens)) . ')\}#i', $contents, $tokens);
          // We found tokens!
          if (!empty($tokens[1])) {
            $done = array();
            foreach ($tokens[1] as $token) {
              if (!isset($done[$token])) {
                $contents = str_replace('{' . $token . '}', $this->tokens[$token], $contents);
                $done[$token] = true;
              }
            }

            // Open the file and write the new data.
            $handle = fopen($this->settings['dir'] . '/' . $this->settings['name'] . '/' . $file->getFileName(), 'w');
            fwrite($handle, $contents);
            fclose($handle);
          }
        }
      }
    }
  }
}