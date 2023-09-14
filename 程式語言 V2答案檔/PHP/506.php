<?php
    $array = array();
    $val = intval(fgets(STDIN));
    $factor = 2;
    while($val != 1){
        while($val % $factor == 0){
            array_push($array, $factor);
            $val /= $factor;
        }
        $factor += 1;
    }
    if(count($array) == 1){
        printf("-1\n");
        return;
    }
    printf("%s\n", join("*", $array));
?>