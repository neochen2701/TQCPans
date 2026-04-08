<?php
    $file = fopen("read.txt", "r") or die("Can't open the file.");
    $str = fgets($file);
    $result = "";
    for($i = 0; $i < strlen($str); $i++){
        $result .= chr(ord($str[$i]) + 2);
    }
    $result_file = fopen("write.txt", "w") or die("Can't create the file");
    fwrite($result_file, $result);
    fclose($result_file);
?>