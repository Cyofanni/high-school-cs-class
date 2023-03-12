<?php
$computer_scientists[0] = 'alan turing';
$computer_scientists[1] = 'john von neumann';
$computer_scientists[2] = 'donald knuth';

echo "$computer_scientists[0]\n";
echo "$computer_scientists[1]\n";
echo "$computer_scientists[2]\n\n";

$physics_field['einstein'] = 'relativity';
$physics_field['bohr'] = 'quantum mechanics';
$physics_field['newton'] = 'mechanics';
echo "$physics_field[einstein]\n";
echo "$physics_field[bohr]\n";
echo "$physics_field[newton]\n\n";

$composers = array('bach', 'mozart', 'beethoven');
for ($i = 0; $i < 3; $i += 1) {
    echo "$composers[$i]\n";
}
echo "\n";
$composers_works = array(
                      'bach' => 'goldberg variations',
                      'mozart' => 'clarinet concerto',
                      'beethoven' => 'triple concerto'
                   );
echo "$composers_works[bach]\n"
?>
