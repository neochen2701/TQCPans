<?php
    $a_bin = trim(fgets(STDIN));
    $b_bin = trim(fgets(STDIN));
    $a = bindec($a_bin);
    $b = bindec($b_bin);
    printf("%d + %d = %d\n", $a, $b, $a+$b);
    if($a + $b >= 255){
        printf("11111111\n");
        return;
    }
    printf("%s\n", str_pad(decbin($a+$b), 8, "0", STR_PAD_LEFT))
?>