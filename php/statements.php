<?php
$a = 1;
$b = 1;

//if else
if ($a == $b) {
    echo "foo\n\n";
}
else {
    echo "bar\n\n";
}

//while loop
$i = 1;
while ($i <= 10) {
    echo $i;
    echo "\n";
    $i += 1;
}

//for loop
echo "\n\n";
for ($j = 1; $j <= 10; $j += 1) {
    echo $j;
    echo "\n";
}

echo "\n";
function factorial($num) {
    if ($num == 0) {
        return 1;
    }
    return $num * factorial($num - 1);
}
echo factorial(5);
echo "\n";

function infinite_recursion() {
    infinite_recursion();
}
infinite_recursion();
?>
