<?php
    $str = trim(fgets(STDIN));
    $split = str_split($str);
    $total = 1;
    for($i = 0; $i < count($split); $i++){
        $total *= $split[$i];
    }
    printf("%s=%d\n", join("*", $split), $total);
?>