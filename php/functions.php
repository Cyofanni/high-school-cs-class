<?php
$counter = 10;

function inc_counter($k) {
    //global counter not visible. $counter is local
    $counter += $k;
}

function inc_counter_global($k) {
    //global counter not visible. $counter is local
    global $counter;
    $counter += $k;
}

function inc_counter_global_r(&$k) {
    //global counter not visible. $counter is local
    global $counter;
    $counter += $k;
}

function cnt() {
    static $c = 0;
    $c++;
    echo "c value is: $c\n";
}

inc_counter(2);
echo "$counter\n";
inc_counter_global(2);
echo "$counter\n";

$k = 2;
inc_counter_global_r($k);
echo "$counter\n";

cnt();
cnt();
cnt();
cnt();
?>
