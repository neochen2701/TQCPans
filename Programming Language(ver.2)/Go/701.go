package main
import (
	"fmt"
	"math"
)

func main(){
	var a, b, c float64
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Scan(&c)
	s := float64(a+b+c)/2.0
	result := math.Sqrt(s * (s-a) * (s-b) * (s-c))
	fmt.Printf("%.2f\n", result)
}
