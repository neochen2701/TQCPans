package main
import "fmt"

func compute(array [5]int) int {
	max := 0
	for i := 0; i < 5; i++{
		if array[i] >= max{
			max = array[i]
		}
	}
	return max
}

func main(){
	var array [5]int
	for i := 0; i < 5; i++{
		fmt.Scanln(&array[i])
	}
	fmt.Println(compute(array))
}
