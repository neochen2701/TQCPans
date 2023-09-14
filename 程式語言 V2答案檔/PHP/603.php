<?php
    $data = array_map('intval', explode(' ', fgets(STDIN)));
    $a = $data[0];
    $b = $data[1];
    for($i = 0; $i < $a; $i++){
        $val = explode(' ', fgets(STDIN));
        printf("%s", join(",", $val));
    }
?>