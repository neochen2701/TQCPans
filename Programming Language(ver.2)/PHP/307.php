<?php 
    function compute($array){
        $max_value = 0;
        for($i = 0; $i < 5; $i++){
            $max_value = max($max_value, $array[$i]);
        }
        return $max_value;
    }
    $array = new SplFixedArray(5);
    for($i = 0; $i < 5; $i++){
        $array[$i] = intval(fgets(STDIN));
    }
    $max_value = compute($array);
    printf("%d\n", $max_value);
?>