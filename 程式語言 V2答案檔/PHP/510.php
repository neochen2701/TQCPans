<?php
    $data = array_map('intval', explode(" ", trim(fgets(STDIN))));
    $a = $data[0];
    $b = $data[1];
    $array = array();
    $copy_array = array();
    for($i = 0; $i < $a; $i++){
        $row = trim(fgets(STDIN));
        array_push($array, array_map('intval', explode(" ", $row)));
        array_push($copy_array, array_map('intval', explode(" ", $row)));
    }
    for($i = 1; $i < $a - 1; $i++){
        for($j = 1; $j < $b - 1; $j++){
            if($array[$i - 1][$j] == 0 || $array[$i][$j - 1] == 0 || $array[$i + 1][$j] == 0 || $array[$i][$j + 1] == 0){
                continue;
            }
            $copy_array[$i][$j] = 0;
        }
    }
    for($i = 0; $i < $a; $i++){
        for($j = 0; $j < $b; $j++){
            if($copy_array[$i][$j] == 0){
                printf(" ");
            }else{
                printf("*");
            }
        }
        printf("\n");
    }
?>