<?php
    function sub_compute($n){
        // The function to compute the Armstrong number.
        $str = strval($n);
        $total = 0;
        for($i = 0; $i < strlen($str); $i++){
            $total += intval($str[$i]) ** strlen($str);
        }
        return $total;
    }
    function compute($n){
        $array = array();
        for($i = 1; $i <= $n; $i++){
            if($i == sub_compute($i)){
                array_push($array, $i);
            }
        }
        return $array;
    }
    $n = intval(fgets(STDIN));
    $array = compute($n);
    $sum = 0;
    for($i = 0; $i < count($array); $i++){
        $sum += $array[$i];
        printf("%d\n", $array[$i]);
    }
    printf("%d\n", $sum);
?>