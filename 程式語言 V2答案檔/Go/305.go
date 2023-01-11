package main
import "fmt"

func compute(array [3]int) int {
	if array[1] == 1{
		return array[0] + array[2]
	}else{
		return array[0] * array[2]
	}
}

func main(){
	var array [3]int
	for i := 0; i < 3; i++{
		fmt.Scanln(&array[i])
	}
	fmt.Println(compute(array))
}
