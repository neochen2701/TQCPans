<?php
    function compute($val){
        if($val < 0 || $val > 100){
            return -1;
        }
        if($val > 60){
            return $val + 5;
        }else{
            return $val + 10;
        }
    }

    $a = intval(fgets(STDIN));
    printf("%d\n", compute($a));
?>