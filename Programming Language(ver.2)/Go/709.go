package main
import "fmt"

func main(){
	var n int
	var total float64 = 0
	max := [4]float64{0, 0, 0, 0}
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var x, y, r float64
		fmt.Scan(&x)
		fmt.Scan(&y)
		fmt.Scan(&r)
		area := float64(r) * float64(r) * 3.14159
		total += area
		if r > max[3] {
			max = [4]float64{area, x, y, r}
		}
	}
	fmt.Printf("Sum = %.2f\n", total)
	fmt.Printf("x: %d, y: %d\n", int(max[1]), int(max[2]))
	fmt.Printf("radius: %d", int(max[3]))
}
