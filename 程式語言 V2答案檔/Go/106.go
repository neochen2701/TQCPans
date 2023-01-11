package main
import (
	"fmt"
	"math"
)

func main(){
	var a, b, c, d float64
	fmt.Scanln(&a)
	fmt.Scanln(&b)
	fmt.Scanln(&c)
	fmt.Scanln(&d)
	fmt.Printf("%.2f", math.Sqrt((a-c)*(a-c)+(b-d)*(b-d)))
}