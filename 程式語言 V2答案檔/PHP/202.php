<?php
    $val = intval(fgets(STDIN));
    if($val + 10 > 100){
        printf("error\n");
        return;
    }
    if($val > 60){
        printf("%d\n", $val + 10);
    }else{
        printf("%d\n", $val + 5);
    }
?>