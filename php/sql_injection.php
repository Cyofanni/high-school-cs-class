<?php
    $db = new mysqli("localhost", "root", "brocchi", "hospital");

    if ($db->connect_error) {
        die("Db connection error ({$db->connect_error})");
    }

    echo "enter an id: ";
    $id_input = 0;
    $id_input = fgets(STDIN);
    $sql_query = "SELECT * FROM doctors WHERE id = " . $id_input;
    $results = $db->query($sql_query);

    while ($row = $results->fetch_assoc()) {
       echo $row['name'] . " " . $row['surname'] . "\n";
    }
?>
