package main
import (
	"fmt"
	"math"
)

func main(){
	var a, b, c, d, e, f float64
	fmt.Scanln(&a)
	fmt.Scanln(&b)
	fmt.Scanln(&c)
	fmt.Scanln(&d)
	fmt.Scanln(&e)
	fmt.Scanln(&f)
	formula := math.Abs(a) * math.Floor(b) + math.Pow(c, d) * math.Sqrt(e) + math.Log10(f)
	fmt.Printf("%.2f\n", formula)
}
