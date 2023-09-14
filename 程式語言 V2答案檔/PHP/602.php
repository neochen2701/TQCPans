<?php
    $str = trim(fgets(STDIN));
    $upper = "";
    $lower = "";
    for($i = 0; $i < strlen($str); $i++){
        if('a' < $str[$i] && $str[$i] < 'z'){
            $lower .= $str[$i];
        }else{
            $upper .= $str[$i];
        }
    }
    printf("%s\n", $upper);
    printf("%s\n", $lower);
    printf("%d\n", strlen($upper));
?>