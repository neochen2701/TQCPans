<?php
    $matrix1 = array();
    $data1 = array_map('intval', explode(' ', fgets(STDIN)));
    $n1 = $data1[0];
    $m1 = $data1[1];
    for($i = 0; $i < $n1; $i++){
        array_push($matrix1, array_map('intval', explode(' ', fgets(STDIN))));
    }
    $matrix2 = array();
    $data2 = array_map('intval', explode(' ', fgets(STDIN)));
    $n2 = $data2[0];
    $m2 = $data2[1];
    for($i = 0; $i < $n2; $i++){
        array_push($matrix2, array_map('intval', explode(' ', fgets(STDIN))));
    }

    if($m1 != $n2){
        printf("error\n");
        return;
    }

    $matrix_result = array();
    for($i = 0; $i < $n1; $i++){
        array_push($matrix_result, array());
        for($j = 0; $j < $m2; $j++){
            $total = 0;
            for($k = 0; $k < $n2; $k++){
                $total += $matrix1[$i][$k] * $matrix2[$k][$j];
            }
            array_push($matrix_result[$i], $total);
        }
    }
    for($i = 0; $i < count($matrix_result); $i++){
        printf("%s\n", join(" ", $matrix_result[$i]));
    }
?>