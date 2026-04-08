<?php
    $array = array();
    $file = fopen("read.txt", "r") or die("Unable to open the file");
    for($i = 0; $i < 4; $i++){
        array_push($array, intval(fgets(STDIN)));
    }
    while(!feof($file)){
        array_push($array, intval(fgets($file)));
    }
    sort($array);
    $result_file = fopen("write.txt", "w") or die("Unable to create the file");
    for($i = 0; $i < count($array); $i++){
        printf("%d\n", $array[$i]);
    }
    fwrite($result_file, sprintf("%s", join("\n", $array)));
?>