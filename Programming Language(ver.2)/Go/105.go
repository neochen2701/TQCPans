package main
import (
	"fmt"
	"math"
)

func main(){
	var a float64
	var b float64
	fmt.Scanln(&a)
	fmt.Scanln(&b)
	fmt.Printf("result=%.2f", math.Sqrt(a+b))
}