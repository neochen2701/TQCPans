<?php
    $array = array(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);
    
    $data = array_map('intval', explode(' ', fgets(STDIN)));
    $year = $data[0];
    $month = $data[1];
    $day = $data[2];
    
    if($year % 400 == 0 || ($year % 100 != 0 && $year % 4 == 0)){
        $array[1] = 29;
    }

    if($month > 12 || $month < 1){
        printf("error\n");
        return;
    }

    if($day < 0 || $day > $array[$month-1]){
        printf("error\n");
        return;
    }

    printf("%d\n", array_sum(array_slice($array, 0, $month-1)) + $day);
?>