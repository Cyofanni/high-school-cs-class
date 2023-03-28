<?php
function shift_char($c, $k) {
    return chr((ord($c) - 97 + $k) % 26 + 97);
}

function encrypt($pt, $k) {
    $ct = '';
    for ($i = 0; $i < strlen($pt); $i++) {
        $ct .= shift_char($pt[$i], $k);
    }
    return $ct;
}

$c1 = 'johannsebastianbach';
$k1 = 4;
echo encrypt($c1, $k1) . "\n";
?>
