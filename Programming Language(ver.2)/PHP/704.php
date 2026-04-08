<?php
    $n = intval(fgets(STDIN));
    $array = array();

    for($i = 0; $i < 100; $i++){
        array_push($array, 0);
    }
    
    $data = array_map('intval', explode(' ', fgets(STDIN)));
    for($i = 0; $i < count($data); $i++){
        $array[$data[$i]]++;
    }

    for($i = 0; $i < 100; $i++){
        if($array[$i] > $n/2){
            printf("%d\n", $i);
            return;
        }
    }
    printf("error\n");
?>