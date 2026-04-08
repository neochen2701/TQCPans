<?php
    $str1 = trim(fgets(STDIN));
    $str2 = trim(fgets(STDIN));
    if(strlen($str1) < 3 || strlen($str1) > 20){
        printf("error\n");
        return;
    }
    if(strlen($str2) < 3 || strlen($str2) > 20){
        printf("error\n");
        return;
    }
    printf("%d\n", strlen($str1));
    printf("%d\n", strlen($str2));
    printf("%s\n", strrev($str1.$str2))
?>