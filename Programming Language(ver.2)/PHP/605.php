<?php
    $array = array();
    for($i = 0; $i < 6; $i++){
        array_push($array, intval(fgets(STDIN)));
    }
    sort($array);
    $min_sum = array_sum(array_slice($array, 0, 3));
    $max_sum = array_sum(array_slice($array, 3));
    printf("%d\n", $max_sum - $min_sum);
?>