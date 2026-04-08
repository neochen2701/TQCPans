<?php
    $str1 = trim(fgets(STDIN));
    $str2 = trim(fgets(STDIN));
    printf("%d\n", strlen($str1));
    printf("%d\n", strlen($str2));
    printf("%s%s\n", $str1, $str2);
?>