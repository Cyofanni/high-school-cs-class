<?php
    //exact match, anywhere in the text -> matches
    echo preg_match("/john/", "john ate the cake") . "\n";
    //exact match, anywhere in the text -> matches
    echo preg_match("/john/", "I saw john eating a cake") . "\n";
    //exact match, anywhere in the text -> matches
    echo preg_match("/john/", "I sawjohneating a cake") . "\n";

    //exact match, anchored to the beginning of the string -> matches
    echo preg_match("/^john/", "john is sleeping") . "\n";
    //exact match, anchored to the beginning of the string -> doesn't match
    echo preg_match("/^john/", "do you know john?") . "\n";

    //exact match, anchored to the end of the string -> matches
    echo preg_match("/john$/", "the best student is john") . "\n";
    //exact match, anchored to the end of the string -> doesn't match
    echo preg_match("/john$/", "the best student is john!") . "\n";
    echo preg_match("/john$/", "the best student isjohn") . "\n";

    //a period matches any single character
    echo preg_match("/b.t/", "bat") . "\t";
    echo preg_match("/b.t/", "bet") . "\t";
    echo preg_match("/b.t/", "bit") . "\t";
    echo preg_match("/b.t/", "bot") . "\t";
    echo preg_match("/b.t/", "but") . "\t";
    echo preg_match("/b.t/", "boot") . "\n";

    //pattern: italian mobile phone number, without quantifiers
    echo preg_match("/\+39 3[0-9][0-9] [0-9][0-9][0-9] [0-9][0-9][0-9][0-9]/", "+39 398 342 8741") . "\t";
    echo preg_match("/\+39 3[0-9][0-9] [0-9][0-9][0-9] [0-9][0-9][0-9][0-9]/", "+30 398 342 8741") . "\t";
    echo preg_match("/\+39 3[0-9][0-9] [0-9][0-9][0-9] [0-9][0-9][0-9][0-9]/", "+39 3980 342 8741") . "\t";
    echo preg_match("/\+39 3[0-9][0-9] [0-9][0-9][0-9] [0-9][0-9][0-9][0-9]/", "+39 398 342 8741") . "\t";
    echo preg_match("/\+39 3[0-9][0-9] [0-9][0-9][0-9] [0-9][0-9][0-9][0-9]/", "+39 398 542 3741") . "\n";

    //pattern: italian mobile phone number, with quantifiers
    echo preg_match("/\+39 3[0-9]{2} [0-9]{3} [0-9]{4}/", "+39 398 342 8741") . "\t";
    echo preg_match("/\+39 3[0-9]{2} [0-9]{3} [0-9]{4}/", "+30 398 342 8741") . "\t";
    echo preg_match("/\+39 3[0-9]{2} [0-9]{3} [0-9]{4}/", "+39 3980 342 8741") . "\t";
    echo preg_match("/\+39 3[0-9]{2} [0-9]{3} [0-9]{4}/", "+39 398 342 8741") . "\t";
    echo preg_match("/\+39 3[0-9]{2} [0-9]{3} [0-9]{4}/", "+39 398 542 3741") . "\n";

    //pattern: 1 or more occurrences of 'A'
    echo preg_match("/A+/", 'TCGCGCTTTTCTCGCGC') . "\t";
    echo preg_match("/A+/", 'TCGCGCTTTTCATCGCGC') . "\t";
    echo preg_match("/A+/", 'TCGCGCTTTTCAAATCGCGC') . "\n";

    //pattern: 'GC', repeated 1 or more times
    echo preg_match("/(GC)+/", "ATCCCCCGGGGG") . "\t";
    echo preg_match("/(GC)+/", "ATCCCCCGCGGGG") . "\t";
    echo preg_match("/(GC)+/", "ATCCCCCGCGCGGGG") . "\n";

    //pattern: start with 'a', end with 'o', any lower-case letter between
    echo preg_match("/a[a-z]*o/", "albero") . "\t";
    echo preg_match("/a[a-z]*o/", "ao") . "\t";
    echo preg_match("/a[a-z]*o/", "amaca") . "\t";
    echo preg_match("/a[a-z]*o/", "aka") . "\n";

    //pattern: italian "codice fiscale"
    $codice_fiscale_regex = "/^([A-Z]{6}[0-9]{2}[A-Z][0-9]{2}[A-Z][0-9]{3}[A-Z])$/";
    $codici_fiscali = array("MCZGGN98M09A703K", "MCZGGNN98R09A703K",
                            "ACZGGN90M09A7033K", "MZZGNN95F19A804K",
                            "ACZGGN90M09A7033K ", "  MZZGNN95F19A804K",
                            "ACZGGN90M09A7033K", "  MZZ GNN95F19A804K  ");
    foreach ($codici_fiscali as $c) {
        if (preg_match($codice_fiscale_regex, $c)) {
            echo $c . " could be valid italian codice fiscale (basic check);\n";
        }
        else {
            echo $c . " cannot be valid italian codice fiscale;\n";
        }
    }
    echo "\n";
    /*repeat the exercise using an associative array:
        array("giovanni mazzocchin" => "MZZ...", "mario rossi" => "RSSMR" etc...)
    */

    //pattern: any filename (at least 1 lower/upper case letter or decimal digit) ending in .php
    echo preg_match("/[a-zA-Z0-9]+\.php/", "tes!.php") . "\t";
    echo preg_match("/[a-zA-Z0-9]+\.php/", "tes!.txt example.php example..cpp example1.php") . "\n";

    //pattern: three characters, either 'A', or 'B', or 'C'
    echo preg_match("/[A|B|C]{3}/", "ABC") . "\t";
    echo preg_match("/[A|B|C]{3}/", "ACB") . "\t";
    echo preg_match("/[A|B|C]{3}/", "BCA") . "\t";
    echo preg_match("/[A|B|C]{3}/", "CBA") . "\t";
    echo preg_match("/[A|B|C]{3}/", "CBC") . "\t";
    echo preg_match("/[A|B|C]{3}/", "BBC") . "\t";
    echo preg_match("/[A|B|C]{3}/", "CBQ") . "\n";

    //pattern: 0 or 1 lowercase letter, followed by 4 digits. Anchored to the end of the text.
    echo preg_match("/([a-z]?[0-9]{4})$/", "?!cd!1234 ") . "\t";
    echo preg_match("/([a-z]?[0-9]{4})$/", "?!cd!1234") . "\t";
    echo preg_match("/([a-z]?[0-9]{4})$/", "a1234 hello") . "\t";
    echo preg_match("/([a-z]?[0-9]{4})$/", "?!cd! 1234") . "\t";
    echo preg_match("/([a-z]?[0-9]{4})$/", "?!cd! b6652") . "\n";

    //pattern: do not start with a lowercase vowel, at the beginning of the text
    echo preg_match("/^[^(aeiou)]/", "nel mezzo del cammin") . "\t";
    echo preg_match("/^[^(aeiou)]/", "chiare, fresche, dolci acque") . "\t";
    echo preg_match("/^[^(aeiou)]/", "ul sabato del villaggio") . "\t";
    echo preg_match("/^[^(aeiou)]/", "el sabato del villaggio") . "\t";
    echo preg_match("/^[^(aeiou)]/", "al sabato del villaggio") . "\t";
    echo preg_match("/^[^(aeiou)]/", "ol sabato del villaggio") . "\n";

    //pattern: start with a vowel (any case), at the beginning of the text
    echo preg_match("/^[(aeiou)|(AEIOU)]/", "albero") . "\t";
    echo preg_match("/^[(aeiou)|(AEIOU)]/", "Albero") . "\t";
    echo preg_match("/^[(aeiou)|(AEIOU)]/", " Olbero") . "\n";

    /*pattern: match isolated that start with a vowel (any case) - at least one
              lowercase letter - 1 decimal digit*/
    $pattern = "/ [(AEIOU)|(aeiou)][a-z]+[0-9] /";
    echo preg_match($pattern, "regex == nightmare") . "\t";
    echo preg_match($pattern, "aa alber1 qweqwe") . "\t";
    echo preg_match($pattern, "aa obcdef9 qweqwe") . "\n";

    /*pattern: text does not start with a decimal digit*/
    $pattern = "/^[^0-9]/";
    echo preg_match($pattern, "abcde") . "\t";
    echo preg_match($pattern, "1asd") . "\t";
    echo preg_match($pattern, " 123") . "\t";
    echo preg_match($pattern, "!qweoiuy") . "\t";
    echo preg_match($pattern, "90abqwe") . "\n";
?>
