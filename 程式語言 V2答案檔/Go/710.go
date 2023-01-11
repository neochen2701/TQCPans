package main
import "fmt"

func exists(array [4]int, target int) bool {
	for i := 0; i < 4; i++ {
		if array[i] == target {
			return true
		}
	}
	return false
}

func print(array [4]int){
	for i := 0; i < 4; i++ {
		fmt.Printf("%d ", array[i])
	}
	fmt.Println()
}

func main(){
	arr := [4]int{0, 0, 0, 0}
	stack := 0
	for i := 0; i < 10; i++ {
		var temp int
		fmt.Scan(&temp)
		if !exists(arr, temp){
			arr[stack % 4] = temp
			stack++
		}
		print(arr)
	}
}
