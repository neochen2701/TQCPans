<?php
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    $c = intval(fgets(STDIN));
    $d = intval(fgets(STDIN));
    $e = intval(fgets(STDIN));
    $f = intval(fgets(STDIN));
    printf("%10d %10d %10d\n", $a, $b, $c);
    printf("%10d %10d %10d\n", $d, $e, $f);
    printf("%-10d %-10d %-10d\n", $a, $b, $c);
    printf("%-10d %-10d %-10d\n", $d, $e, $f);
?>