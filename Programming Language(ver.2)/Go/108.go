package main
import (
	"fmt"
)

func main(){
	var num int
	fmt.Scanln(&num)
	radius := float64(num) / 2.0
	area := radius * radius * 3.1415
	fmt.Printf("%-10d\n", num)
	fmt.Printf("%-10.2f\n", radius)
	fmt.Printf("%-10.4f\n", area)
}
