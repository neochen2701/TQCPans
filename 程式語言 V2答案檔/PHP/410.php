<?php
    $n = intval(fgets(STDIN));
    $file = fopen("read.txt", "r") or die("Unable to open the file");
    $array = new SplFixedArray($n);
    for($i = 0; $i < $n; $i++){
        $array[$i] = trim(fgets($file));
    }
    $result_array = new SplFixedArray($n);
    for($i = 0; $i < $n; $i++){
        $result = strtoupper($array[$i][0]);
        for($j = 1; $j < strlen($array[$i]); $j++){
            if($array[$i][$j-1] == ' '){
                $result .= strtoupper($array[$i][$j]);
            }else{
                $result .= $array[$i][$j];
            }
        }
        $result_array[$i] = $result;
    }
    $result_file = fopen("write.txt", "a") or die("Unable to create the file");
    for($i = 0; $i < $n; $i++){
        printf("%s\n", $result_array[$i]);
        fwrite($result_file, sprintf("%s\n", $result_array[$i]));
    }
?>