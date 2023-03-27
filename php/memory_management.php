<?php
//copy-on-write
$mathematicians1 = array("Galois", "Abel", "Tartaglia", "Euler");
$mathematicians2 = $mathematicians1;

//copy happens after this instruction
$mathematicians2[0] = "Poisson";

foreach ($mathematicians1 as $math) {
    echo "$math\n";
}

echo "\n";
foreach ($mathematicians2 as $math) {
    echo "$math\n";
}
?>
