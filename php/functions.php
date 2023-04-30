<?php
$g = 10;

function f1() {
    $g = 6;
}

f1();
echo "value of global g: $g\n";

function f2() {
    global $g;
    $g = 6;
}

f2();
echo "value of global g: $g\n";
?>
