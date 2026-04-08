<?php
    $val = intval(fgets(STDIN));
    $array = array("", "one", "two", "three", "four");
    if($val <= 0 || $val > 4){
        printf("error\n");
    }else{
        printf("%s\n", $array[$val]);
    }
?>