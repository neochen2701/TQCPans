package main
import (
	"fmt"
	"sort"
)

func main(){
	var n int
	fmt.Scan(&n)
	
	result := map[int]string{}
	result_key := make([]int, n)

	for i := 0; i < n; i++{
		var a, b int
		fmt.Scan(&a)
		fmt.Scan(&b)
		result[a*b] = fmt.Sprintf("%dx%d", a, b)
		result_key[i] = a*b
	}

	sort.Ints(result_key)

	for i := 0; i < n; i++ {
		fmt.Printf("%s=%d\n", result[result_key[i]], result_key[i])
	}
}
