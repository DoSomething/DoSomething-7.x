<?php
 
/**
 * @file
 * Default simple view template to display a list of rows in columns.
 *
 * @ingroup views_templates
 */

if (!empty($title)) {
  print '<h3>' . $title . '</h3>';
}
// Render columns if needed.
if ($columns) {
  print '<div class="view-columns view-columns-' . count($columns) . '">';
  foreach ($columns as $column_id => $rows) {
    print '<div' . ($columns_classes[$column_id] ? ' class="' . $columns_classes[$column_id] .'"' : '') . '>';
    foreach ($rows as $row_id => $row) {
      print '<div' . ($classes_array[$row_id] ? ' class="' . $classes_array[$row_id] .'"' : '') . '>' . $row . '</div>';
    }
    print '</div>';
  }
  print '</div>';
}
// Render normal view.
else {
  $d = array();
  foreach ($rows AS $key => $junk) {

    #echo '<div class="gallery-row row-' . $key . '">';
    foreach ($junk AS $key => $data) {
      #echo $data;
      $d[] = $data;
    }
    #echo '</div>';
  }

  $nd = array();
  $i = 0;
  foreach ($d AS $key => $info) {
    if ($i == 4) {
      $i = 0;
    }

    $nd[$i][] = $info;
    $i++;
  }

  foreach ($nd AS $col => $rows) {
    echo '<div class="gallery-col col-' . $col . '">';
    foreach ($rows AS $key => $row) {
      echo $row;
    }
    echo '</div>';
  }

  #foreach ($rows as $id => $row) {
  #  print '<div' . ($classes_array[$id] ? ' class="' . $classes_array[$id] .'"' : '') . '>' . $row . '</div>';
  #}
}