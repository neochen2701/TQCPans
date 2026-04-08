<?php
    $a = intval(fgets(STDIN));
    $prime = new SplFixedArray(10000);
    for($i = 2; $i < 10000; $i++){
        if($prime[$i]){
            continue;
        }
        for($j = $i + $i; $j < 10000; $j += $i){
            $prime[$j] = true;
        }
    }
    printf("%d %s a prime number\n", $a, ($prime[$a] ? "is not" : "is"))
?>