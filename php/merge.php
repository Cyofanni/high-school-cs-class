<?php
  function merge(&$a, $l, $m, $h) {
      $left_size = $m - $l + 1 + 1;
      $left = array_slice($a, $l, $m + 1);

      $right_size = $h - ($m + 1) + 1 + 1;

      $right = array_slice($a, $m + 1, $h + 1);

      $left[] = PHP_INT_MAX;
      $right[] = PHP_INT_MAX;

      $left_i = 0;
      $right_i = 0;

      for ($k = $l; $k <= $h; $k++) {
          if ($left[$left_i] <= $right[$right_i]) {
              $a[$k] = $left[$left_i];
              $left_i++;
          }
          else {
              $a[$k] = $right[$right_i];
              $right_i++;
          }
      }
  }

  $nums = array(1, 8, 10, 12, 1, 5, 9);
  echo count($nums);
  echo "\n";
  merge($nums, 0, floor((count($nums) - 1) / 2), count($nums) - 1);
  foreach ($nums as $item) {
      echo "$item ";
  }
  echo "\n";
?>
