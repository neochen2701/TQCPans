<?php
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    $operator = rtrim(fgets(STDIN), "\r\n");
    if($operator != "+" && $operator != "-" && $operator != "*"){ printf("error\n"); return; }
    $result = $operator == "+" ? ($a + $b) : ($operator == "-" ? $a - $b : $a * $b);
    printf("%d%s%d=%d\n", $a, $operator, $b, $result);
?>