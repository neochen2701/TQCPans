<?php
    function validate($data){
        $val = ((intval($data[0]) + intval($data[2]) + intval($data[4])) + (intval($data[1]) + intval($data[3])) * 5) % 26;
        $ch = chr($val - 1 + ord('A'));
        return $ch == $data[5];
    }
    for($i = 0; $i < 3; $i++){
        $text = trim(fgets(STDIN));
        printf("%s\n", validate($text) ? "Pass" : "Fail");
    }
?>