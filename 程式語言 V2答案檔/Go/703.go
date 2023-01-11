package main
import "fmt"

func main(){
	var num int
	fmt.Scan(&num)
	array := [4]int{50, 10, 5, 1}
	count := [4]int{0, 0, 0, 0}
	for i := 0; i < len(array); i++ {
		for j := 0; num >= array[i]; j++ {
			count[i] += 1
			num -= array[i]
		}
	}
	for i := 0; i < len(array); i++{
		if count[i] == 0 {
			continue
		}
		fmt.Printf("%d*$%d", count[i], array[i])
		if i != len(array) - 1 {
			fmt.Printf(" ")
		}
	}
	fmt.Println()
}
