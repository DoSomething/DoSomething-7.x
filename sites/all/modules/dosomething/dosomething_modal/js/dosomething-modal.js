/**
* Provide the HTML to create a modal dialog without a title or close button.
*
*/
Drupal.theme.prototype.DosomethingModalBase = function () {
  var html = '';
  html += '<div id="ctools-modal" class="popups-box">';
  html += '  <div class="ctools-modal-content dosomething-modal-content">';
  html += '    <div class="modal-scroll">';
  html += '      <div id="modal-content" class="modal-content popups-body"></div>';
  html += '    </div>';
  html += '  </div>';
  html += '</div>';
  return html;
}
