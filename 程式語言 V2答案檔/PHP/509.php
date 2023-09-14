<?php
    $str = trim(fgets(STDIN));
    $split_str = explode("/", $str);
    $total = 0;
    for($i = 0; $i < count($split_str); $i++){
        $total += intval($split_str[$i]);
    }
    printf("%s\n", join(" ", $split_str));
    printf("%d\n", $total);
?>