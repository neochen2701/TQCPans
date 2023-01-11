package main
import (
	"fmt"
)

func main(){
	var a int
	var b int
	fmt.Scan(&a)
	fmt.Scan(&b)

	array := make([][]int, a)
	result := make([][]int, a)
	for i := 0; i < a; i++{
		array[i] = make([]int, b)
		result[i] = make([]int, b)
	}

	for i := 0; i < a; i++ {
		for j := 0; j < b; j++{
			fmt.Scan(&array[i][j])
			result[i][j] = array[i][j]
		}
	}

	for i := 1; i < a - 1; i++ {
		for j := 1; j < b - 1; j++ {
			if array[i][j] == 1 {
				if array[i-1][j] == 1 && array[i+1][j] == 1 && array[i][j-1] == 1 && array[i][j+1] == 1 {
					result[i][j] = 0		
				}
			}
		}
	}

	for i := 0; i < a; i++ {
		for j := 0; j < b; j++ {
			if result[i][j] == 1 {
				fmt.Print("*")
			}else{
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}
