<?php
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    for($i = 1; $i < $a; $i++){
        if(intval(sqrt($i)) != sqrt($i)){
            continue;
        }
        printf("%d\n", pow(sqrt($i), $b));
    }
?>