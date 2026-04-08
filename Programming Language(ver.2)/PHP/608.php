<?php
    $array = array();
    for($i = 0; $i < 5; $i++){
        array_push($array, 0);
    }
    $score = 0;
    for($i = 0; $i < 10; $i++){
        $task = intval(fgets(STDIN));
        if($task == 0){
            continue;
        }
        $array[0] = 1;
        for($j = 3; $j >= 0; $j--){
            $array[min($j+$task, 4)] += $array[$j];
            $array[$j] = 0;
        }
        if($array[4] > 0){
            $score += $array[4];
            $array[4] = 0;
        }
    }
    printf("score = %d\n", $score);
?>