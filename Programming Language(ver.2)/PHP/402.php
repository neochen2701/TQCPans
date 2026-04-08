<?php
    $str1 = trim(fgets(STDIN));
    $str2 = trim(fgets(STDIN));
    $n = intval(fgets(STDIN));
    if($n > strlen($str1)){
        printf("error\n");
        return;
    }
    if(substr($str1, 0, $n) == substr($str2, 0, $n)){
        printf("%s = %s\n", $str1, $str2);
    }else if(substr($str1, 0, $n) < substr($str2, 0, $n)){
        printf("%s < %s\n", $str1, $str2);
    }else{
        printf("%s > %s\n", $str1, $str2);
    }
?>