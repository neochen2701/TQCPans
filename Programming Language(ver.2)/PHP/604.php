<?php
    $array = array();
    for($i = 0; $i < 9; $i++){
        array_push($array, intval(fgets(STDIN)));
    }
    sort($array);
    for($i = 0; $i < 9; $i++){
        printf("%d\n", $array[$i]);
    }
    printf("sum = %d\n", array_sum($array));
?>