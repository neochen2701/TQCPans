<?php
    function compute($array){
        $a = $array[0];
        $b = $array[1];
        for($i = 0; $i < $b; $i++){
            for($j = 0; $j < $a; $j++){
                printf("*");
            }
            printf("\n");
        }
        return $a * $b;
    }

    $array = new SplFixedArray(2);
    $array[0] = intval(fgets(STDIN));
    $array[1] = intval(fgets(STDIN));
    
    printf("%d\n", compute($array));
?>