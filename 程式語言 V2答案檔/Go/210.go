package main
import (
	"fmt"
	"math"
)

func main(){
	var a, b int
	fmt.Scanln(&a)
	fmt.Scanln(&b)
	gcd := 1
	for i := 1; i <= int(math.Min(float64(a), float64(b))); i++{
		if a % i == 0 && b % i == 0 {
			gcd = i
		}
	}
	lcm := (a * b) / gcd
	fmt.Println(gcd)
	fmt.Println(lcm)
}