<?php
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    $sum = 0;
    $a_odd = ($a % 2 == 0 ? $a + 1 : $a);
    for($i = $a_odd; $i <= $b; $i += 2){
        $sum += $i;
    }
    printf("%d\n", $sum);
?>