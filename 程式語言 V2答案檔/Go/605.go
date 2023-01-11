package main
import (
	"fmt"
	"sort"
)

func main(){
	var array = make([]int, 6)
	for i := 0; i < 6; i++ {
		fmt.Scan(&array[i])
	}
	sort.Ints(array)
	var total = 0
	for i := 0; i < 3; i++{
		total += (array[5-i] - array[i])
	}
	fmt.Println(total)
}
