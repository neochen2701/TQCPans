<?php
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    $c = intval(fgets(STDIN));
    $s = ($a+$b+$c)/2.0;
    $result = sqrt($s*($s-$a)*($s-$b)*($s-$c));
    printf("%.2f\n", $result);
?>