<?php
    function compute($a, $operator, $b){
        $result = 0;
        if($operator == 1){
            $result = $a + $b;
        }else{
            $result = $a * $b;
        }
        return $result;
    }
    $a = intval(fgets(STDIN));
    $operator = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    $result = compute($a, $operator, $b);
    printf("%d\n", $result)
?>