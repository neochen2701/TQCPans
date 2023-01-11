package main
import "fmt"

func compute(array [6]int) float64 {
	min := 99999.99
	for i := 0; i < 3; i++{
		val := float64(array[i]) / float64(array[i+3])
		if min > val{
			min = val
		}
	}
	return min
}

func main(){
	var array [6]int
	for i := 0; i < 6; i++{
		fmt.Scanln(&array[i])
	}
	fmt.Printf("%.3f", compute(array))
}
