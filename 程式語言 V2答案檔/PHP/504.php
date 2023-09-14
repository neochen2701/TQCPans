<?php
    $str = trim(fgets(STDIN));
    printf("%s\n", $str == strrev($str) ? "Yes" : "No");
?>