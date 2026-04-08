<?php
    $a = intval(fgets(STDIN));
    if($a != 0 && $a != 1){
        printf("error\n");
        return;
    }
    for($i = 1; $i <= 5; $i++){
        for($j = 1; $j <= 5; $j++){
            if(!$a){
                printf("%d x %d = %d\t", $i, $j, $i*$j);
            }else{
                printf("%d x %d = %d\t", $j, $i, $i*$j);
            }
        }
        printf("\n");
    }
?>