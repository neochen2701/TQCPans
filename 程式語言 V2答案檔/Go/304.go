package main
import "fmt"

func compute(array [6]int) int {
	count := 0
	for i := 0; i < 6; i++{
		if array[i] % 3 == 0{
			count += 1
		}
	}
	return count
}

func main(){
	var array [6]int
	for i := 0; i < 6; i++{
		fmt.Scanln(&array[i])
	}
	fmt.Println(compute(array))
}
