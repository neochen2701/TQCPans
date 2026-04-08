package main
import "fmt"

func main(){
	var a, b int 
	fmt.Scanln(&a)
	fmt.Scanln(&b)
	sum := 0
	for i := a; i <= b; i++{
		if i % 2 == 1{
			sum += i
		}
	}
	fmt.Println(sum)
}