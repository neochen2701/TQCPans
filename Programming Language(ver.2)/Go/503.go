package main
import (
	"fmt"
	"math"
)
func main(){
	var a, b int
	fmt.Scan(&a)
	fmt.Scan(&b)
	for i := 1; i < a; i++ {
		sqrt_a := math.Sqrt(float64(i))
		if sqrt_a != math.Trunc(sqrt_a) {
			continue;
		}
		fmt.Printf("%.0f\n", math.Pow(sqrt_a, float64(b)))
	}
}
