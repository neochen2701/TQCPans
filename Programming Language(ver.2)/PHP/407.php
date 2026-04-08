<?php
    $file = fopen("read.txt", "r") or die("Unable to open file");
    $str = trim(fgets($file));
    $result = "";
    for($i = 0; $i < strlen($str); $i++){
        if($str[$i] == '*') continue;
        $result .= $str[$i];
    }
    $result_file = fopen("write.txt", "w") or die("Unable to create file");
    $result_file = fwrite($result_file, $result);
    fclose($result_file);
?>