<?php
$str1 = 'mozart\'s';
$str2 = ' operas: ';
$str3 = '\\don giovanni, \\le nozze di figaro';

echo "$str1$str2$str3\n";

$str_hex = "\x70\x68\x70\xa";
$str_chrs = "php\n";
if (is_string($str_hex) && is_string($str_chrs) &&
    $str_hex == $str_chrs) {
    echo $str_hex;
}
?>
