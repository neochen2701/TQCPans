<?php
    $str = trim(fgets(STDIN));
    $n = intval(fgets(STDIN));

    $str[$n] = ('a' < $str[$n] && $str[$n] < 'z') ? strtoupper($str[$n]) : strtolower($str[$n]);
    printf("The letter that was selected is: %s\n", $str[$n]);
    printf("%s\n", $str);
?>