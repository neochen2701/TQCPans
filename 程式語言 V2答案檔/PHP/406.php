<?php
    $mapping = "QWERTYUIOPPASDFGHJKLLZXCVBNMM";
    $str = trim(fgets(STDIN));

    $result = "";
    for($i = 0; $i < strlen($str); $i++){
        for($j = 0; $j < strlen($mapping); $j++){
            if(strtoupper($str[$i]) == $mapping[$j]){
                $result .= ('a' < $str[$i] && $str[$i] < 'z') ? strtolower($mapping[$j+1]) : $mapping[$j+1];
                break;
            }
        }
    }

    printf("%s\n", $result);

?>