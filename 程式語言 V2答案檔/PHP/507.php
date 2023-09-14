<?php
    function result($answer, $compare){
        $a = 0;
        $b = 0;
        for($i = 0; $i < strlen($answer); $i++){
            if($answer[$i] == $compare[$i]){
                $a++;
            }
        }
        for($i = 0; $i < strlen($answer); $i++){
            for($j = 0; $j < strlen($answer); $j++){
                if($i == $j){
                    continue;
                }
                if($answer[$i] == $compare[$j]){
                    $b++;
                }
            }
        }
        return sprintf("%dA%dB", $a, $b);
    }
    $ans = trim(fgets(STDIN));
    for($i = 0; $i < 3; $i++){
        $compare = trim(fgets(STDIN));
        printf("%s\n", result($ans, $compare));
    }
?>