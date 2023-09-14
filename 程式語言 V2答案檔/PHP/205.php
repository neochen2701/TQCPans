<?php
    $count = new SplFixedArray(7);
    $error = 0;
    for($i = 0; $i < 10; $i++){
        $val = intval(fgets(STDIN));
        if($val >= 1 && $val <= 6){
            $count[$val] += 1;
        }else{
            $error += 1;
        }
    }
    for($i = 1; $i <= 6; $i++){
        printf("number%d:%d\n", $i, $count[$i]);
    }
    printf("error:%d\n", $error);
?>