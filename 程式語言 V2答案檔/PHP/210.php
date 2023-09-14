<?php
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    $val_max = 1;
    for($i = 1; $i < min($a, $b); $i++){
        if($a % $i == 0 && $b % $i == 0){
            $val_max = $i;
        }
    }
    printf("%d\n", $val_max);
    printf("%d\n", ($a*$b)/$val_max);
?>