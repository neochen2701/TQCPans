<?php
    $key = array();
    $value = array();
    for($i = 0; $i < 3; $i++){
        $temp = explode(' ', fgets(STDIN));
        array_push($key, $temp[0]);
        array_push($value, intval($temp[1]));
    }
    $total = 0;
    for($i = 0; $i < 5; $i++){
        $temp = trim(fgets(STDIN));
        $index = array_search($temp, $key);
        if($index === false){
            continue;
        }
        $total += $value[$index];
    }
    printf("%d\n", $total);
?>