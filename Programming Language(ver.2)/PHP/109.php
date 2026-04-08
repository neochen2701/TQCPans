<?php
    $a = doubleval(fgets(STDIN));
    if($a > 100 || $a < 0){
        printf("error\n");
        return;
    }
    printf("%s\n", $a >= 60 ? "pass" : "fail");
    printf("%s\n", $a % 2 == 0 ? "even" : "odd");
?>