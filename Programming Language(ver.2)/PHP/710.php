<?php
    $array = array(0, 0, 0, 0);
    $sector = 0;
    for($i = 0; $i < 10; $i++){
        $value = intval(fgets(STDIN));
        $index = array_search($value, $array);
        if($index === false){
            $array[$sector] = $value;
            $sector += 1;
            $sector %= 4;
        }
        for($j = 0; $j < 4; $j++){
            printf("%d ", $array[$j]);
        }
        printf("\n");
    }
?>