<?php
    $count = 0;
    for($i = 0; $i < 3; $i++){
        $data = array_map('intval', explode(' ', fgets(STDIN)));
        $hour = $data[0];
        $minutes = $data[1];
        $time = "AM";
        if($hour >= 13){
            $hour -= 12;
            $time = "PM";
        }
        if($hour == 12){
            $time = "PM";
        }
        if($hour == 0){
            $hour = 12;
        }
        $count += ($time == "AM" ? 1 : 0);
        printf("%s %d:%d\n", $time, $hour, $minutes);
    }
    printf("%d\n", $count);
?>