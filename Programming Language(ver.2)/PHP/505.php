<?php
    $a = doubleval(fgets(STDIN));
    $b = doubleval(fgets(STDIN));
    $c = doubleval(fgets(STDIN));
    $d = doubleval(fgets(STDIN));
    $e = doubleval(fgets(STDIN));
    $f = doubleval(fgets(STDIN));
    printf("%.2f\n", abs($a) * floor($b) + pow($c, $d) * sqrt($e) + log10($f));
?>