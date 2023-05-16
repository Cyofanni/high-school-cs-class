<?php
  function sum(&$add1, &$add2) {
    return $add1 + $add2;
  }
  $op1 = $_GET['op1'];
  $op2 = $_GET['op2'];
  echo "<html><body>";
  echo sum($op1, $op2);
  echo "</body></html>";
?>
