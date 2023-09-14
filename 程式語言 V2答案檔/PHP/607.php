<?php 
    function compareSuits($data1, $data2){
        $mapping = "SHDC";
        $d1pos = strpos($mapping, $data1[0]);
        $d2pos = strpos($mapping, $data2[0]);
        return ($d1pos > $d2pos ? -1 : ($d1pos == $d2pos ? 0 : 1));
    }
    function compareNumber($data1, $data2){
        $d1num = intval(substr($data1, 1));
        $d2num = intval(substr($data2, 1));
        return ($d1num < $d2num ? -1 : ($d1num == $d2num ? 0 : 1));
    }
    $data = explode(" ", fgets(STDIN));
    if(compareSuits($data[0], $data[1]) == 0){
        if(compareNumber($data[0], $data[1]) == -1){
            printf("%s < %s\n", $data[0], $data[1]);
        }else if(compareNumber($data[0], $data[1]) == 1){
            printf("%s > %s\n", $data[0], $data[1]);
        }else{
            printf("%s = %s\n", $data[0], $data[1]);
        }
    }else if(compareSuits($data[0], $data[1]) < 0){
        printf("%s < %s\n", $data[0], $data[1]);
    }else{
        printf("%s > %s\n", $data[0], $data[1]);
    }
?>