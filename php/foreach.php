<?php
$strs = array('qwe', 'sdf', 'qweqwe', 'dfgdfs');
foreach ($strs as $item) {
    echo $item;
    echo "\n";
}

$phone_book = array(
                 'john' => '3331230912',
                 'jack' => '3390984512',
                 'tony' => '3380983142'
              );
foreach ($phone_book as $name => $phone_number) {
    echo "$name's number is: $phone_number\n";
}
?>
