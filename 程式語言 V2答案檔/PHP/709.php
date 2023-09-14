<?php
    class Circle {
        public $x;
        public $y;
        public $r;
        public function __construct($x, $y, $r){
            $this->x = $x;
            $this->y = $y;
            $this->r = $r;
        }
        public function get_x(){
            return $this->x;
        }
        public function get_y(){
            return $this->y;
        }
        public function get_r(){
            return $this->r;
        }
        public function area(){
            return $this->r * $this->r * 3.14159;
        }
    }
    $n = intval(fgets(STDIN));
    $array = array();
    $total = 0;
    for($i = 0; $i < $n; $i++){
        $data = array_map('floatval', explode(" ", fgets(STDIN)));
        array_push($array, new Circle($data[0], $data[1], $data[2]));
        $total += $array[$i]->area();
    }
    usort($array, function ($a, $b) {
        return ($a->area() > $b->area() ? -1 : ($a->area() == $b->area() ? 0 : 1));
    });
    $max_circle = $array[0];
    printf("Sum = %.2f\nx: %d, y: %d\nradius: %d\n", $total, $max_circle->x, $max_circle->y, $max_circle->r);
?>