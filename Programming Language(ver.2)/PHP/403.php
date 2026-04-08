<?php
    $str = trim(fgets(STDIN));
    $result = "";
    for($i = 0; $i < strlen($str); $i++){
        $result .= strval('a' < $str[$i] && $str[$i] < 'z' ? strtoupper($str[$i]) : strtolower($str[$i]));
    }
    printf("%s\n", $result);
?>