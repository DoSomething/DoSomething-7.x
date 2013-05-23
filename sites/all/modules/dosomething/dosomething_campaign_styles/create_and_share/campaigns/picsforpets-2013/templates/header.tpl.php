<header>
  <div class="header_inner">
    <img class="header_logo_text" src="//files.dosomething.org/files/campaigns/crazy13/logo_text.png" alt="Craziest Thing type logo" />
    <img class="header_background" src="//files.dosomething.org/files/campaigns/crazy13/header_small.jpg" alt="People" />
    <img class="header_sponsor" src="//files.dosomething.org/files/campaigns/crazy13/sponsor.png" alt="HR Block logo" />
    <img class="header_ds_logo" src="//www.dosomething.org/sites/all/themes/doit/css/images/ds-logo.png" alt="DoSomething.org logo" />
    <img class="header_logo" src="//files.dosomething.org/files/campaigns/crazy13/logo.png" alt="Craziest Thing icon logo" />
  </div>
</header>

<section class="header-cta">
  <div class="header-cta-container">
    <?php if ($settings['user']['post_count'] < 1): ?>
      <p>Help save an animal's life: <a href="/<?php echo $settings['campaign_root']; ?>/submit">Submit your picture</a></p>
    <?php else: ?>
      <a href="/<?php echo $settings['campaign_root']; ?>">Back to Gallery</a> <a href="/<?php echo $settings['campaign_root']; ?>/submit">Submit Another Pic</a>
    <?php endif; ?>
  </div>
</section>

<?php
  $filters = explode('-', basename(request_path()));

  $types = array('all' => '');
  $done = false;
  foreach ($filters AS $filter) {
    if (in_array($filter, array('cat', 'cats', 'dog', 'dogs', 'other', 'others'))) {
      $types[$filter] = ' selected="selected"';
      $done = true;
    }
    else {
      $types[$filter] = '';
    }
  }

  if (!$done) {
    $types['all'] = ' selected="selected"';
  }
?>

<nav class="header-nav">
  <div class="nav-container">

    <?php /* First nav filter - animal type */ ?>
    <ul class="filter-type filter-list" id="filter-type">
      <li data-id="all" id="type-selection" class="filter-selection" <?php echo $types['all']; ?>>All Animals</li>
      <li>
        <ul class="filter-options">
          <li data-id="all" class="filter-option" <?php echo $types['all']; ?>>All Animals</li>
          <li data-id="cats" class="filter-option" <?php echo $types['cats']; ?>>Cats</li>
          <li data-id="dogs" class="filter-option" <?php echo $types['dogs']; ?>>Dogs</li>
          <li data-id="other" class="filter-option" <?php echo $types['other']; ?>>Other</li>
        </ul>
      </li>
    </ul>

    <?php /* Second nav filter - state */ ?>
    <ul class="filter-state filter-list" id="filter-state">
      <li data-id="all" data-id="all" id="state-selection" class="filter-selection" href="#">All States</li>
      <li>
        <ul class="filter-options">
          <?php
            // Load the default US states array.
            module_load_include('inc', 'webform', 'includes/webform.options');
            $states = webform_options_united_states(null, null, null, null);

            // Fills an array with basic null values.  This prevents a notice that would otherwise appear.
            $selected = array_fill_keys(array_keys($states), '');

            // Mark the selected state.
            if (preg_match('#[A-Z]{2}#', request_path(), $state)) {
              $selected_state = $state[0];
              $selected[$selected_state] = ' selected="selected"';
            }

            $path = request_path();
            foreach ($states as $key => $state) {
              echo '<li class="filter-option" data-id="' . $key . '"' . $selected[$key] . '>' . $state . '</li>';
            }
          ?>
        </ul>
      </li>
    </ul>

    <?php /* Submit nav filter selections */ ?>
    <button id="filter-submit">filter</button>

  </div>
</nav>
