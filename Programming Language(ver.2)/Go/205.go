package main
import "fmt"

func main(){
	var a [10]int
	var record [7]int
	for i := 0; i < 10; i++{
		fmt.Scanln(&a[i])
		if a[i] <= 0 || a[i] > 6{
			record[6] += 1
		}else{
			record[a[i] - 1] += 1
		}
	}
	for i := 0; i < 6; i++{
		fmt.Printf("number%d:%d\n", i+1, record[i])
	}
	fmt.Printf("error:%d", record[6])
}
