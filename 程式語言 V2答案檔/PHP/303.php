<?php 
    function compute($val){
        $prime = new SplFixedArray(10000);
        for($i = 2; $i < 10000; $i++){
            if($prime[$i]){
                continue;
            }
            for($j = $i + $i; $j < 10000; $j += $i){
                $prime[$j] = true;
            }
        }
        return $prime[$val] ? 0 : 1;
    }

    $a = intval(fgets(STDIN));
    $is_prime = compute($a);
    printf("%d %s a prime number\n", $a, ($is_prime ? "is" : "is not"));
?>