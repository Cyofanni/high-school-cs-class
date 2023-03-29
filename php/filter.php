<?php
$bet1_10_callback = function ($x) {
    return $x >= 1 and $x <= 10;
};

$numbers = array(6, 12, 76, 56, 1, 5, 2, 8);
$bet1_10 = array_filter($numbers, $bet1_10_callback);
foreach ($bet1_10 as $b) {
    echo $b . " ";
}
echo "\n";
?>
