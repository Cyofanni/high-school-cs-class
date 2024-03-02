<?php
function merge(&$v, $l, $m, $h) {
  $sz_left = $m - $l + 1;
  $sz_right = $h - $m;
  $left = array_slice($v, $l, $sz_left);
  $right = array_slice($v, $m + 1, $sz_right);
  array_push($left, PHP_INT_MAX);
  array_push($right, PHP_INT_MAX);

  $li = 0;
  $ri = 0;

  for ($i = $l; $i <= $h; $i++) {
    if ($left[$li] <= $right[$ri]) {
      $v[$i] = $left[$li];
      $li++;
    }
    else {
      $v[$i] = $right[$ri];
      $ri++;
    }
  }
}

function merge_sort(&$v, $l, $h) {
  if ($l < $h) {
    $m = intdiv($l + $h, 2);
    merge_sort($v, $l, $m);
    merge_sort($v, $m + 1, $h);
    merge($v, $l, $m, $h);
  }
}

$ar = array(70, 8, 30, 40, 2, 2, 3, 9, 100, 2, 4, -123);
$sz_ar = count($ar);
print_r($ar);
merge_sort($ar, 0, $sz_ar - 1);
print_r($ar);
?>
