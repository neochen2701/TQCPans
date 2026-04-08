<?php
    $array_index = new SplFixedArray(3);
    $array_sentence = new SplFixedArray(3);
    $file = fopen("read.txt", "r") or die("Unable to open file");
    for($i = 0; $i < 3; $i++){
        $array_index[$i] = intval(fgets(STDIN));
    }
    for($i = 0; $i < 3; $i++){
        $array_sentence[$i] = trim(fgets($file));
    }
    for($i = 0; $i < 3; $i++){
        $result = "";
        for($j = 0; $j < $array_index[$i]; $j++){
            $result .= strval($array_index[$i]);
        }
        for($j = $array_index[$i]; $j < strlen($array_sentence[$i]); $j++){
            $result .= $array_sentence[$i][$j]; 
        }
        printf("%s\n", $result);
    }
?>