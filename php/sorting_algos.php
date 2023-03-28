<?php
//pass-by-value
function insertion_sort($a) {
   $size_a = count($a);
   for ($i = 1; $i < $size_a; $i++) {
       $item = $a[$i];
       $j = $i - 1;
       while ($j >= 0 && $item < $a[$j]) {
           $a[$j + 1] = $a[$j];
           $j--;
       }
       $a[$j + 1] = $item;
   }
   return $a;
}

function swap(&$a, &$b) {
    $t = $a;
    $a = $b;
    $b = $t;
}

//pass-by-reference
function bubble_sort(&$a) {
    $size_a = count($a);
    for ($i = $size_a - 1; $i > 0; $i--) {
        for ($j = 0; $j < $i; $j++) {
            if ($a[$j] > $a[$j + 1]) {
                swap($a[$j], $a[$j + 1]);
            }
        }
    }
}

//insertion sort
$nums = array(1, 6, 0, 6, 5, 4, 3, 1, 7, 56, 12);
echo "initial array:\n";
foreach ($nums as $num) {
    echo $num . ' ';
}
echo "\n";
$nums_sorted = insertion_sort($nums);
echo "sorted array (insertion sort):\n";
foreach ($nums_sorted as $num) {
    echo $num . ' ';
}
echo "\n\n";

//bubble sort
$nums = array(1, 6, 0, 6, 5, 4, 3, 1, 7, 56, 12);
echo "initial array:\n";
foreach ($nums as $num) {
    echo $num . ' ';
}
echo "\n";
bubble_sort($nums);
echo "sorted array (bubble sort):\n";
foreach ($nums as $num) {
    echo $num . ' ';
}
echo "\n\n";
?>
