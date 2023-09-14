<?php
    $x1 = intval(fgets(STDIN));
    $y1 = intval(fgets(STDIN));
    $x2 = intval(fgets(STDIN));
    $y2 = intval(fgets(STDIN));
    printf("%.2f\n", sqrt(pow(($x2-$x1), 2) + pow(($y2-$y1), 2)));
?>