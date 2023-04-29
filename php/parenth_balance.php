<?php
$expr = "()()(())((()))";
$expr_l = explode(" ", $expr);
$stack = array();
$is_balanced = true;

foreach ($expr_l as $c) {
    if ($c == '(') {
        array_push($stack, '(');
    }
    else if ($c == ')') {
        if (count($stack) > 0) {
            array_pop($stack);
        }
        else {
            $is_balanced = false;
            break;
        }
    }
}

if (count($stack) == 0 && $is_balanced) {
    echo "$expr is balanced\n";
}
else {
    echo  "$expr is not balanced\n";
}
?>
