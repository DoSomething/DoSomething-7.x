/**
* Provide the HTML to create a modal dialog.
*
*/
Drupal.theme.prototype.DosomethingModalBase = function () {
  var html = '';
  html += '<div id="ctools-modal" class="popups-box">';
  html += '  <div class="ctools-modal-content dosomething-modal-content">';
  html += '    <span class="popups-close"><a class="close" href="#">' + Drupal.CTools.Modal.currentSettings.closeText + '</a></span>';
  html += '    <div class="modal-scroll">';
  html += '      <div id="modal-content" class="modal-content popups-body"></div>';
  html += '    </div>';
  html += '  </div>';
  html += '</div>';
  return html;
}
