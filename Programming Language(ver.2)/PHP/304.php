<?php 
    function compute($arr){
        $count = 0;
        for($i = 0; $i < 6; $i++){
            if($arr[$i] % 3 == 0){
                $count += 1;
            }
        }
        return $count;
    }

    $arr = new SplFixedArray(6);
    for($i = 0; $i < 6; $i++){
        $arr[$i] = intval(fgets(STDIN));
    }
    printf("%d\n", compute($arr));
?>