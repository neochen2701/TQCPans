<?php
    $str = trim(fgets(STDIN));
    $array = new SplFixedArray(26);
    for($i = 0; $i < 26; $i++){
        $array[$i] = 0;
    }
    for($i = 0; $i < strlen($str); $i++){
        $array[ord($str[$i]) - ord('a')] += 1;
    }
    $result = "";
    $result_count = 0;
    for($i = 0; $i < 26; $i++){
        if($array[$i] > $result_count){
            $result_count = $array[$i];
            $result = chr($i + ord('a'));
        }
    }
    printf("%s\n", $result);
    printf("%d\n", $result_count);
?>