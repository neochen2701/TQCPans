package main
import (
	"fmt"
	"sort"
)

func main(){
	var array = make([]int, 9)
	for i := 0; i < 9; i++ {
		fmt.Scan(&array[i])
	}
	sort.Ints(array)
	var total = 0
	for i := 0; i < 9; i++ {
		fmt.Println(array[i])
		total += array[i]
	}
	fmt.Printf("sum = %d\n", total)
}
