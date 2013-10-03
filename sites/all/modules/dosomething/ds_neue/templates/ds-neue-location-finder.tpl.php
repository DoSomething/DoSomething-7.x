<div class="js-location-finder-form">
	<div class="no-js-hide-feature">
	  <p><?php print $help_text; ?></p>
	  <input type="text" maxlength="5" class="short js-location-finder-input" placeholder="zip code">
	  <a class="btn primary medium js-location-finder-button">Search</a>
	</div>
	<div class="alert error no-js-feature-warning">
		The Location Finder requires JavaScript to be enabled in your browser.
	</div>
</div>

<div class="content-center narrow js-location-finder-results no-js-hide-feature">
  <p><?php print $results_text; ?> <span class="js-location-finder-results-zip"></span> (<a href="#" class="js-location-finder-reset">change</a>):</p>
  <ul class="location-list"></ul>
</div>