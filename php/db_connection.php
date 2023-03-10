<?php
    echo nl2br("Composers\n");
    $db = new mysqli("localhost", "username", "password", "db_name");

    if ($db->connect_error) {
        die("Db connection error ({$db->connect_error})");
    }
    $sql_query = "SELECT * FROM composers";
    $results = $db->query($sql_query);

    while ($row = $results->fetch_assoc()) {
       echo nl2br("{$row['surname']}\n");
    }
?>
