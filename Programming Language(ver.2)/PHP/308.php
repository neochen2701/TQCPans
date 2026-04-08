<?php
    function compute($n){
        if($n == 1){
            return 1;
        }
        if($n == 0){
            return 0;
        }
        return compute($n - 1) + compute($n - 2);
    }
    $n = intval(fgets(STDIN));
    for($i = $n; $i >= 1; $i--){
        printf("fib(%d)=%d\n", $i, compute($i));
    }
?>