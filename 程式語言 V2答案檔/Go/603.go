package main
import "fmt"

func main(){
	var n int
	var m int
	fmt.Scan(&n)
	fmt.Scan(&m)
	var array = make([][]int, n)
	for i := 0; i < n; i++ {
		array[i] = make([]int, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Scan(&array[i][j])
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Print(array[i][j])
			if j != m-1 {
				fmt.Print(",")
			}
		}
		fmt.Println()
	}
}
