<?php
class Person {
    private $name = "mario";
    private $surname = "rossi";

    //return name by value (copy)
    public function getName() {
        return $this -> name;
    }
    //return surname by reference (alias)
    public function &getSurname() {
        return $this -> surname;
    }
}

$p = new Person;
$na = $p -> getName();
$na = "giovanni";
echo $p -> getName();
echo "\n";
echo $p -> getName();
echo "\n";
$suref = &$p -> getSurname();
$suref = "verdi";
echo $p -> getSurname();
echo "\n";
?>
