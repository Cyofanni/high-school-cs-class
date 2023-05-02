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
?>
