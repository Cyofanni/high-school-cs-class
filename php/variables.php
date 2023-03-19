<?php
//variable variables
$var1 = "var2";
$$var1 = "hello";

echo "$var1\n";
echo "$var2\n";

//references
$i1 = 5;
$i2 = &$i1;
echo "$i1\n";
echo "$i2\n";
$i2 = 6;
echo "$i1\n";
echo "$i2\n";

function f_byval($v) {
   $v = 7;
}

function f_byref(&$v) {
   $v = 7;
}

$var = 1;
f_byval($var);
echo "$var\n";
f_byref($var);
echo "$var\n";
?>