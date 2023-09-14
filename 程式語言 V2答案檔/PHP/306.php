<?php
    function compute($n){
        if($n == 0){
            return 1;
        }
        return $n * compute($n - 1);
    }
    $n = intval(fgets(STDIN));
    printf("%d!=%d\n", $n, compute($n));
?>