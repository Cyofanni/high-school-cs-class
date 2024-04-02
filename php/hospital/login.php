<?php
  $db = new mysqli("localhost", "root", "brocchi", "hospital");

  $q = "SELECT * FROM doctors WHERE id = " . $_GET['id'] . " AND password = '" . $_GET['password'] . "'";

  $res = $db -> query($q);
  echo "<html><body>";
  if (mysqli_num_rows($res) == 0) {
    die("login failed");
  }
  $res = $db -> query($q);
  while ($rec = $res -> fetch_assoc()) {
    echo $rec['name'] . "  " . $rec['surname'] . "  " . $rec['birthdate'] . "  "
         . $rec['password'] . "\n";
    echo "</br>";
  }
  echo "</body></html>";
?>
