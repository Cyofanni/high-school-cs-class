<?php
function display_32_bits($n) {
    $counter = 1;
    $bits = array();
    while ($counter <= 32) {
        $bit = $n & 1 == 1 ? '1' : '0';
        $bits[32 - $counter] = $bit;
        $n = $n >> 1;
        $counter++;
        $var = 2;
    }
    for ($i = 0; $i <= 31; $i++) {
        echo $bits[$i];
        if ($i < 31 && ($i + 1) % 4 == 0) {
            echo '_';
        }
    }
    echo "\n";
}

function twos_complement(&$n) {
    return ~$n + 1;
}

for ($n = -16; $n <= 15; $n++) {
    display_32_bits($n);
}
?>
