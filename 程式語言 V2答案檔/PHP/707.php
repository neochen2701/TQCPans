<?php
    class Triangle {
        public $width;
        public $height;
        public function __construct($w, $h){
            $this->width = $w;
            $this->height = $h;
        }
        public function width(){
            return $this->width;
        }
        public function height(){
            return $this->height;
        }
        public function area(){
            return $this->width * $this->height;
        }
    };
    $n = intval(fgets(STDIN));
    $array = array();
    for($i = 0; $i < $n; $i++){
        $data = array_map('intval', explode(' ', fgets(STDIN)));
        array_push($array, new Triangle($data[0], $data[1]));
    }
    usort($array, function($a, $b) {
        return ($a->area() < $b->area() ? -1 : ($a->area() == $b->area() ? 0 : 1));
    });
    for($i = 0; $i < $n; $i++){
        printf("%dx%d=%d\n", $array[$i]->width(), $array[$i]->height(), $array[$i]->area());
    }
?>