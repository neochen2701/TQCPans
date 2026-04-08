<?php
    $a = doubleval(fgets(STDIN));
    printf("%-10d\n", $a);
    printf("%-10.2f\n", $a/2);
    printf("%-10.4f\n", pow($a/2, 2) * 3.1415);
?>