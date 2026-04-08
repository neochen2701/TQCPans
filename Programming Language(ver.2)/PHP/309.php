<?php
    function compute($array){
        $min_value = 4499;
        for($i = 0; $i < 3; $i++){
            $min_value = min($min_value, $array[$i]/$array[3+$i]);
        }
        return $min_value;
    }
    $array = new SplFixedArray(6);
    for($i = 0; $i < 6; $i++){
        $array[$i] = intval(fgets(STDIN));
    }
    $min_value = compute($array);
    printf("%.3f\n", $min_value);
?>