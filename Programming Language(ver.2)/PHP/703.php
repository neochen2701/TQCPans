<?php
    $val = intval(fgets(STDIN));
    $array = array(50, 10, 5, 1);
    $count = array(0, 0, 0, 0);
    for($i = 0; $i < 4; $i++){
        while($val >= $array[$i]){
            $count[$i]++;
            $val -= $array[$i];
        }
    }
    $result = "";
    for($i = 0; $i < 4; $i++){
        if($count[$i] == 0) continue;
        $result .= sprintf("%d*$%d ", $count[$i], $array[$i]);
    }
    printf("%s\n", trim($result));
?>