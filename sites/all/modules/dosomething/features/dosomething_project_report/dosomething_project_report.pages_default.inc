<?php
/**
 * @file
 * dosomething_project_report.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dosomething_project_report_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'projects';
  $page->task = 'page';
  $page->admin_title = 'projects';
  $page->admin_description = '';
  $page->path = 'projects';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'weight' => 0,
    'name' => 'navigation',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_projects_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'projects';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => '0',
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'width_type' => 'px',
    'percent_width' => '505',
    'rows' => '4',
    'row_1' => array(
      'columns' => '1',
      'width_1' => '505',
      'names' => array(
        0 => 'Top',
      ),
    ),
    'row_2' => array(
      'columns' => '1',
      'width_1' => '505',
      'names' => array(
        0 => 'Middle 1',
      ),
    ),
    'row_3' => array(
      'columns' => '2',
      'width_1' => '245',
      'width_2' => '245',
      'names' => array(
        0 => 'Middle 2 left',
        1 => 'Middle 2 right',
      ),
    ),
    'row_4' => array(
      'columns' => '1',
      'width_1' => '505',
      'names' => array(
        0 => 'Bottom',
      ),
    ),
    'sidebars' => array(
      'left' => 0,
      'left_width' => 200,
      'right' => 0,
      'right_width' => 200,
      'width_type' => 'px',
    ),
  );
  $display->panel_settings = array(
    'style' => 'default',
    'style_settings' => array(
      'default' => NULL,
      'row_1_1' => NULL,
      'row_2_1' => NULL,
      'row_3_1' => NULL,
      'row_3_2' => NULL,
      'row_4_1' => NULL,
    ),
    'edit_style' => 'Edit style settings',
    'did' => '20',
    'row_1_1' => array(
      'style' => '',
      'edit_style' => 'Edit style settings',
    ),
    'row_2_1' => array(
      'style' => '',
      'edit_style' => 'Edit style settings',
    ),
    'row_3_1' => array(
      'style' => '',
      'edit_style' => 'Edit style settings',
    ),
    'row_3_2' => array(
      'style' => '',
      'edit_style' => 'Edit style settings',
    ),
    'row_4_1' => array(
      'style' => '',
      'edit_style' => 'Edit style settings',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'row_1_1';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Custom redirect if projects/*',
      'title' => '',
      'body' => '<?
$i = 1;
$baseUrl=\'projects-search/\';
$newUrl = $baseUrl;
while ($arg = arg($i)) {
   if (isset($arg)) {
      $newUrl .= $arg . \'/\';
   } else {
      break;
   }
   $i++;
}

if ($newUrl != $baseUrl) {
   drupal_goto($newUrl);
}
?>',
      'format' => '2',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['row_1_1'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'row_1_1';
    $pane->type = 'block';
    $pane->subtype = 'block-252';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'module' => 'block',
      'delta' => '252',
      'block_visibility' => 0,
      'block_settings' => array(
        'info' => 'projects_header_20101110',
        'body' => '<a href="/projects"><img src="/files/layout/projects.jpg" border="0px" alt="Volunteer projects" ></a>

<div style="float: right; padding: 10px;">
<a href="http://www.dosomething.org/node/add/project" onmouseout="MM_swapImgRestore()" onmouseover="MM_swapImage(\'Post Your Project\',\'\',\'http://www.dosomething.org/files/postproject_up.gif\',1)"><img src="http://www.dosomething.org/files/postproject_down.gif" alt="Post Your Project" name="Post Your Project" width="205" height="72" border="0" id="Post Your Project" /></a> 
</div>
<p id="projects-main-description">Welcome to the projects section,<br/>discover new ideas and share your<br/> best ones that make a difference. </p>
',
        'format' => '2',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['row_1_1'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'row_1_1';
    $pane->type = 'block';
    $pane->subtype = 'block-251';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'module' => 'block',
      'delta' => '251',
      'block_visibility' => 0,
      'block_settings' => array(
        'info' => 'Projects Search 2010/11/10',
        'body' => '<script type="text/JavaScript">
<!--
function MM_swapImgRestore() { //v3.0
  var i,x,a=document.MM_sr; for(i=0;a&&i<a.length&&(x=a[i])&&x.oSrc;i++) x.src=x.oSrc;
}

function MM_preloadImages() { //v3.0
  var d=document; if(d.images){ if(!d.MM_p) d.MM_p=new Array();
    var i,j=d.MM_p.length,a=MM_preloadImages.arguments; for(i=0; i<a.length; i++)
    if (a[i].indexOf("#")!=0){ d.MM_p[j]=new Image; d.MM_p[j++].src=a[i];}}
}

function MM_findObj(n, d) { //v4.01
  var p,i,x;  if(!d) d=document; if((p=n.indexOf("?"))>0&&parent.frames.length) {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);}
  if(!(x=d[n])&&d.all) x=d.all[n]; for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document);
  if(!x && d.getElementById) x=d.getElementById(n); return x;
}

function MM_swapImage() { //v3.0
  var i,j=0,x,a=MM_swapImage.arguments; document.MM_sr=new Array; for(i=0;i<(a.length-2);i+=3)
   if ((x=MM_findObj(a[i]))!=null){document.MM_sr[j++]=x; if(!x.oSrc) x.oSrc=x.src; x.src=a[i+2];}
}
//-->
</script>

<body onload="MM_preloadImages(\'http://www.dosomething.org/files/postproject_up.gif\')">

<div style="float: right; padding: 10px;">
<a href="http://www.dosomething.org/node/add/project" onmouseout="MM_swapImgRestore()" onmouseover="MM_swapImage(\'Post Your Project\',\'\',\'http://www.dosomething.org/files/postproject_up.gif\',1)"><img src="http://www.dosomething.org/files/postproject_down.gif" alt="Post Your Project" name="Post Your Project" width="205" height="72" border="0" id="Post Your Project" /></a> 
</div>
<p>Hey welcome to the  Projects Page! Check out some new ideas or post some of your own volunteer experiences or projects to the mix. </p>
<br style="clear:both;">



<div id="search-box" class="box blue gainlayout">

<h2>Search</h2>

<form id="proj-search">
<label for="search-keyword">Keyword</label>
<input type="text" id="search-keyword" name="search-keyword" />
<input type="image" id="start-search" value="search" src="/nd/buttons/search.png" />

<div class="clicktip_target" clicktip="search-filter-box">Advanced Search Options</div>

<div id="search-filter-box" class="clicktip">

<div id="filterSelects">

<span style="position:relative">
<input type="text" id="input-proximity" value="10" name="input-proximity" size="5" maxlength="5" style="text-align:right;">
<span style="position:absolute;padding-top:9px"><label for="postal-code">miles from Postal Code:</label></span>
<span style="padding-left:140px"><input type="text" id="postal-code" name="postal-code"></span>
</span>

<label for="filter-cause">Cause</label>
<select id="filter-cause">
<option value="*">&lt;All&gt;</option>
<option value="Animal Welfare">Animal Welfare</option>
<option value="Disaster Response And Relief">Disaster Response And Relief</option>
<option value="Discrimination">Discrimination</option>
<option value="Education">Education</option>
<option value="Environment">Environment</option>
<option value="Health And Fitness">Health And Fitness</option>
<option value="HIV And Sexuality">HIV And Sexuality</option>
<option value="International Human Rights">International Human Rights</option>
<option value="Poverty">Poverty</option>
<option value="Violence And Bullying">Violence And Bullying</option>
<option value="War%2C Peace And Politics">War, Peace And Politics</option>
</select>

<label for="filter-state">State</label>
<select id="filter-state" ><option value="*">&lt;All&gt;</option><option value="AK">AK</option><option value="AL">AL</option><option value="AR">AR</option><option value="AS">AS</option><option value="AZ">AZ</option><option value="CA">CA</option><option value="CO">CO</option><option value="CT">CT</option><option value="DC">DC</option><option value="DE">DE</option><option value="FL">FL</option><option value="FM">FM</option><option value="GA">GA</option><option value="GU">GU</option><option value="HI">HI</option><option value="IA">IA</option><option value="ID">ID</option><option value="IL">IL</option><option value="IN">IN</option><option value="KS">KS</option><option value="KY">KY</option><option value="LA">LA</option><option value="MA">MA</option><option value="MD">MD</option><option value="ME">ME</option><option value="MH">MH</option><option value="MI">MI</option><option value="MN">MN</option><option value="MO">MO</option><option value="MP">MP</option><option value="MS">MS</option><option value="MT">MT</option><option value="NC">NC</option><option value="ND">ND</option><option value="NE">NE</option><option value="NH">NH</option><option value="NJ">NJ</option><option value="NM">NM</option><option value="NV">NV</option><option value="NY">NY</option><option value="OH">OH</option><option value="OK">OK</option><option value="OR">OR</option><option value="PA">PA</option><option value="PR">PR</option><option value="PW">PW</option><option value="RI">RI</option><option value="SC">SC</option><option value="SD">SD</option><option value="TN">TN</option><option value="TX">TX</option><option value="UT">UT</option><option value="VA">VA</option><option value="VI">VI</option><option value="VT">VT</option><option value="WA">WA</option><option value="WI">WI</option><option value="WV">WV</option><option value="WY">WY</option><option value="Canada">Canada</option></select>

<label for="filter-type">Type of Project</label>
<select id="filter-type">
<option value="*">&lt;All&gt;</option>
<option value="volunteer experience">volunteer experience</option>
<option value="project idea">project idea</option>
<option value="ongoing project">ongoing project</option>
<option value="completed project">completed project</option>
</select>



</div>

<div id="withFilter">
<input type="checkbox" id="with-pictures" name="with" value="pictures" />
<label for="with-pictures">Pictures</label>
<input type="checkbox" id="with-video" name="with" value="video" />
<label for="with-video">Video</label>
<input type="checkbox" id="with-clubs" name="with" value="clubs" />
<label for="with-video">Clubs</label>
<input type="checkbox" id="with-grants" name="with" value="grants" />
<label for="with-video">Grant Winners</label>
</div>

<span style="position:relative">
<input style="margin: 0.5em 0;" type="image" id="start-advanced-search" value="search" src="/nd/buttons/advanced_search.png" />
<span style="position:absolute;padding:15px 0px 0px 10px;"><a href="#" onClick="$(\'#proj-search\')[0].reset(); return false;">reset</a></span>
</span>

</form>

</div>

</div>

<?php $base_arg = 1; ?>

<div id="search-order">
<span>Order by:</span> <?php if (arg($base_arg) == \'updated\' || arg($base_arg) == \'*\' || arg($base_arg) == \'\') : ?> Last Updated <?php else: ?> <a class="orderUpdated">Last Updated</a> <?php endif; ?> | <?php if (arg($base_arg) == \'comments\') : ?> Comments <?php else: ?> <a class="orderComments">Comments</a> <?php endif; ?> | <?php if (arg($base_arg) == \'hits\') : ?> Views <?php else: ?> <a class="orderViews">Views</a> <?php endif; ?>
</div>

<script type="text/javascript">

 $("div.node h2:eq(0)").hide();

if (\'<?= arg($base_arg); ?>\' == \'comments\' || \'<?= arg($base_arg); ?>\' == \'hits\') {
 $("input[name=\'order\']").removeAttr("checked");
 $("input[value=\'<?=arg($base_arg);?>\']").attr("checked", "checked");
}

 $("select#filter-cause option[value=\'<?=arg($base_arg + 1);?>\']").attr("selected", "selected");
 $("select#filter-state option[value=\'<?=arg($base_arg + 2);?>\']").attr("selected", "selected");
 $("select#filter-type option[value=\'<?=arg($base_arg + 3);?>\']").attr("selected", "selected");
 $("input#with-video[value=\'<?=arg($base_arg + 4);?>\']").attr("checked", "checked");

 $("input#with-pictures[value=\'<?=arg($base_arg + 5);?>\']").attr("checked", "checked");
if (\'<?=arg($base_arg + 5);?>\' == \'*\') {
 $("input#with-pictures[value=\'pictures\']").attr("checked", "checked");
}

 $("input#with-clubs[value=\'<?=arg($base_arg + 6);?>\']").attr("checked", "checked");
 $("input#with-grants[value=\'<?=arg($base_arg + 7);?>\']").attr("checked", "checked");


if (\'<?=arg($base_arg + 8);?>\' != \'*\') {
 $("input#search-keyword").attr("value", "<?=arg($base_arg + 8);?>");
}

if (\'<?=arg($base_arg + 9);?>\' != \'*\' && \'<?=arg($base_arg + 9);?>\' != \'\') {
 $("input#input-proximity").attr("value", "<?=arg($base_arg + 9);?>");
}

if (\'<?=arg($base_arg + 10);?>\' != \'*\') {
 $("input#postal-code").attr("value", "<?=arg($base_arg + 10);?>");
}

function buildUrl() {
var args = new Array();
args.push($("select#filter-cause").val());
args.push($("select#filter-state").val());
args.push($("select#filter-type").val());
args.push($("input#with-video:checked").val() ? \'video\' : \'*\');
args.push($("input#with-pictures:checked").val() ? \'pictures\' : \'all\');
args.push($("input#with-clubs:checked").val() ? \'clubs\' : \'*\');
args.push($("input#with-grants:checked").val() ? \'grants\' : \'*\');
args.push($("input#search-keyword").val() ? $("input#search-keyword").val() : \'*\');
args.push($("input#input-proximity").val() ? $("input#input-proximity").val() : \'*\');
args.push($("input#postal-code").val() ? $("input#postal-code").val() : \'*\');


return args.join(\'/\');

}

 $(\'input#start-search\').click(function(){ 
location.href = \'/projects/*/\' + buildUrl(); 
return false; });
 $(\'input#start-advanced-search\').click(function(){ 
location.href = \'/projects/*/\' + buildUrl(); 
return false; });
 $(\'a.orderUpdated\').click(function(){ 
location.href = \'/projects/updated/\' + buildUrl(); 
return false; }); 
 $(\'a.orderComments\').click(function(){ 
location.href = \'/projects/comments/\' + buildUrl(); 
return false; }); 
 $(\'a.orderViews\').click(function(){ 
location.href = \'/projects/hits/\' + buildUrl(); 
return false; });

</script>
',
        'format' => '2',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-3'] = $pane;
    $display->panels['row_1_1'][2] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'row_1_1';
    $pane->type = 'block';
    $pane->subtype = 'block-249';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'module' => 'block',
      'delta' => '249',
      'block_visibility' => 0,
      'block_settings' => array(
        'info' => 'Projects Word Cloud',
        'body' => '<div class="big-blue-caps">PROJECTS BY INTEREST</div>

<div id="project-wordcloud" style="background-color:#fff;">    <script type="text/javascript" src="http://www.google.com/jsapi"></script>
    <script type="text/javascript" src="/sites/all/themes/zen/dosomething/wordcumulus.js"></script>
    <script type="text/javascript" src="http://word-cumulus-goog-vis.googlecode.com/svn/trunk/swfobject.js"></script>
    <script type="text/javascript">
      google.load("visualization", "1");





      // Set callback to run when API is loaded
      google.setOnLoadCallback(drawVisualization);

      // Called when the Visualization API is loaded.
      function drawVisualization() {

        // Create and populate a data table.
        var data = new google.visualization.DataTable();

        data.addColumn(\'string\', \'Tag\');
        data.addColumn(\'string\', \'URL\');
        data.addColumn(\'string\', \'font_size\');

        data.addRows(25);

        data.setCell(0, 0, \'recipe\');
        data.setCell(0, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/recipe\');
        data.setCell(0, 2, \'15\');
        
        data.setCell(1, 0, \'football\');
        data.setCell(1, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/football\');
        data.setCell(1, 2, \'25\');
        
        data.setCell(2, 0, \'bullying\');
        data.setCell(2, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/bullying\');
        data.setCell(2, 2, \'20\');

        data.setCell(3, 0, \'puppies\');
        data.setCell(3, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/puppies\');
        data.setCell(3, 2, \'28\');

        data.setCell(4, 0, \'shelter\');
        data.setCell(4, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/shelter\');
        data.setCell(4, 2, \'25\');

        data.setCell(5, 0, \'music\');
        data.setCell(5, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/music\');
        data.setCell(5, 2, \'24\');

        data.setCell(6, 0, \'art\');
        data.setCell(6, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/art\');
        data.setCell(6, 2, \'13\');

        data.setCell(7, 0, \'driving\');
        data.setCell(7, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/driving\');
        data.setCell(7, 2, \'21\');

        data.setCell(8, 0, \'dance\');
        data.setCell(8, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/dance\');
        data.setCell(8, 2, \'20\');

        data.setCell(9, 0, \'team\');
        data.setCell(9, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/team\');
        data.setCell(9, 2, \'18\');

        data.setCell(10, 0, \'school\');
        data.setCell(10, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/school\');
        data.setCell(10, 2, \'27\');

        data.setCell(11, 0, \'recycling\');
        data.setCell(11, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/recycling\');
        data.setCell(11, 2, \'23\');

        data.setCell(12, 0, \'food\');
        data.setCell(12, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/food\');
        data.setCell(12, 2, \'23\');

        data.setCell(13, 0, \'substance abuse\');
        data.setCell(13, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/substance%20abuse\');
        data.setCell(13, 2, \'23\');

        data.setCell(14, 0, \'literacy\');
        data.setCell(14, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/literacy\');
        data.setCell(14, 2, \'23\');

        data.setCell(15, 0, \'child labor\');
        data.setCell(15, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/child%20labor\');
        data.setCell(15, 2, \'23\');

        data.setCell(16, 0, \'gay rights\');
        data.setCell(16, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/gay%20rights\');
        data.setCell(16, 2, \'23\');

        data.setCell(17, 0, \'soldiers\');
        data.setCell(17, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/soldiers\');
        data.setCell(17, 2, \'23\');

        data.setCell(18, 0, \'sports\');
        data.setCell(18, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/sports\');
        data.setCell(18, 2, \'23\');

        data.setCell(19, 0, \'club\');
        data.setCell(19, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/club\');
        data.setCell(19, 2, \'23\');

        data.setCell(20, 0, \'voting\');
        data.setCell(20, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/voting\');
        data.setCell(20, 2, \'23\');

        data.setCell(21, 0, \'games\');
        data.setCell(21, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/games\');
        data.setCell(21, 2, \'23\');

        data.setCell(22, 0, \'friends\');
        data.setCell(22, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/friends\');
        data.setCell(22, 2, \'23\');

        data.setCell(23, 0, \'Facebook\');
        data.setCell(23, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/Facebook\');
        data.setCell(23, 2, \'23\');

        data.setCell(24, 0, \'animals\');
        data.setCell(24, 1, \'http://www.dosomething.org/projects/*/*/*/*/*/pictures/*/*/animals\');
        data.setCell(24, 2, \'23\');


         
        
        // Instantiate our table object.
        var vis = new gviz_word_cumulus.WordCumulus(document.getElementById(\'mydiv\'));

        // Draw our table with the data we created locally.
        vis.draw(data, {text_color: \'#055494\', text_color2: \'#20c0e0\', speed: 650, width: 500, height: 350});
       }
   </script>


        <div id="mydiv"></div></div>',
        'format' => '2',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-4'] = $pane;
    $display->panels['row_1_1'][3] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'row_2_1';
    $pane->type = 'views_panes';
    $pane->subtype = 'projects_search-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-5'] = $pane;
    $display->panels['row_2_1'][0] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'row_3_1';
    $pane->type = 'views_panes';
    $pane->subtype = 'projects_boxes-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-6'] = $pane;
    $display->panels['row_3_1'][0] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'row_3_2';
    $pane->type = 'views_panes';
    $pane->subtype = 'projects_boxes-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-7'] = $pane;
    $display->panels['row_3_2'][0] = 'new-7';
    $pane = new stdClass;
    $pane->pid = 'new-8';
    $pane->panel = 'row_4_1';
    $pane->type = 'block';
    $pane->subtype = 'block-255';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'module' => 'block',
      'delta' => '255',
      'block_visibility' => 0,
      'block_settings' => array(
        'info' => 'Projects Map Form',
        'body' => '<div class="big-blue-caps">PROJECTS BY LOCATION</div>
<form id="map-search">
<div style="position:relative">

<span style="position:absolute;margin-top:100px;margin-left:163px;">

<input type="text" id="postal-code-map" name="postal-code" class="styled short" value="zip code" size="8" style="font-size:30px;height:33px;border:1px solid #48BCDC" onClick="if (this.value == \'zip code\') { this.value=\'\'; }">

<input type="image" style="margin-top: 1px;" class="start-search-map" value="go" mce_src="/nd/projects/go4.png" src="/nd/projects/go4.png">
</span>

<span style="position:absolute;margin-top:158px;margin-left:161px;">


<select id="filter-state-map" style="height:41px;font-weight:bold;font-size:30px;color:#48BCDC;border:1px solid #48BCDC;font-family: \'Trebuchet MS\', Arial, Helvetica, sans-serif;"><option value="*">STATE</option><option value="AK">AK</option><option value="AL">AL</option><option value="AR">AR</option><option value="AS">AS</option><option value="AZ">AZ</option><option value="CA">CA</option><option value="CO">CO</option><option value="CT">CT</option><option value="DC">DC</option><option value="DE">DE</option><option value="FL">FL</option><option value="FM">FM</option><option value="GA">GA</option><option value="GU">GU</option><option value="HI">HI</option><option value="IA">IA</option><option value="ID">ID</option><option value="IL">IL</option><option value="IN">IN</option><option value="KS">KS</option><option value="KY">KY</option><option value="LA">LA</option><option value="MA">MA</option><option value="MD">MD</option><option value="ME">ME</option><option value="MH">MH</option><option value="MI">MI</option><option value="MN">MN</option><option value="MO">MO</option><option value="MP">MP</option><option value="MS">MS</option><option value="MT">MT</option><option value="NC">NC</option><option value="ND">ND</option><option value="NE">NE</option><option value="NH">NH</option><option value="NJ">NJ</option><option value="NM">NM</option><option value="NV">NV</option><option value="NY">NY</option><option value="OH">OH</option><option value="OK">OK</option><option value="OR">OR</option><option value="PA">PA</option><option value="PR">PR</option><option value="PW">PW</option><option value="RI">RI</option><option value="SC">SC</option><option value="SD">SD</option><option value="TN">TN</option><option value="TX">TX</option><option value="UT">UT</option><option value="VA">VA</option><option value="VI">VI</option><option value="VT">VT</option><option value="WA">WA</option><option value="WI">WI</option><option value="WV">WV</option><option value="WY">WY</option><option value="Canada">Canada</option></select>
<input type="image" style="margin-left: 20px;" class="start-search-map" value="go" mce_src="/nd/projects/go4.png" src="/nd/projects/go4.png">
</select>
</span>
<img src="/nd/projects/map_usa_40.png"></img>
</div>
</form>


<script type="text/javascript">

function buildUrlMap() {
var args = new Array();
args.push(\'*\');
args.push($("select#filter-state-map").val());
args.push(\'*\');
args.push(\'*\');
args.push(\'pictures\');
args.push(\'*\');
args.push(\'*\');
args.push(\'*\');
args.push(\'10\');
if ($("input#postal-code").val()) {
   args.push($("input#postal-code").val());
} else if ($("input#postal-code-map").val()) {
   args.push($("input#postal-code-map").val());
} else {
   args.push(\'*\');
}

return args.join(\'/\');

}


 $(\'input.start-search-map\').click(function(){
 location.href = \'/projects-search/*/\' + buildUrlMap();
return false; });
</script>',
        'format' => '2',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-8'] = $pane;
    $display->panels['row_4_1'][0] = 'new-8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['projects'] = $page;

 return $pages;

}
