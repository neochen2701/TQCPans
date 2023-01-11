package main
import (
	"fmt"
)

func min(x, y int) int {
	if x < y {
		return x
	}else{
		return y
	}
}

func main(){
	var array = make([]int, 5)
	var score = 0;
	for i := 0; i < 10; i++ {
		var temp int
		fmt.Scan(&temp)
		if temp == 0 {
			continue
		}
		array[0] = 1
		for j := 3; j >= 0; j-- {
			array[min(j+temp, 4)] += array[j]
			array[j] = 0
		}
		if array[4] > 0{
			score += array[4]
			array[4] = 0
		}
	}
	fmt.Printf("score = %d\n", score)
}
