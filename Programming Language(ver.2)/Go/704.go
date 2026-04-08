package main
import (
	"fmt"
	"sort"
)

func main(){
	var n int
	fmt.Scan(&n)
	array := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&array[i])
	}
	sort.Ints(array)
	dict := map[int]int{}
	for i := 0; i < n; i++ {
		if _, ok := dict[array[i]]; ok {
			dict[array[i]] += 1;
		}else{
			dict[array[i]] = 1
		}
	}
	var find bool = false
	var value int = 0
	for i := 0; i < n; i++ {
		if dict[array[i]] > n/2 {
			find = true
			value = array[i]
			break;
		}
	}

	if find == false {
		fmt.Println("error")
	}else{
		fmt.Println(value)
	}
}
