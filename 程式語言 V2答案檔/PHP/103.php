<?php
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    $c = intval(fgets(STDIN));
    $sum = $a + $b + $c;
    printf("%d+%d+%d=%d\n", $a, $b, $c, $sum);
    printf("%.2f\n", $sum / 3.0);
?>