<?php
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    $c = intval(fgets(STDIN));
    printf("%d\n", $a > 60 && $a < 100 ? 1 : 0);
    printf("%.2f\n", ($b + 1)/10);
    printf("%d\n", $a > $c ? $a : $c);
?>