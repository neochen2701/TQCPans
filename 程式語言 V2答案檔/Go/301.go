package main
import "fmt"

func compute(data [2]int){
	for i := 0; i < data[1]; i++{
		for j := 0; j < data[0]; j++{
			fmt.Printf("*")
		}
		fmt.Println()
	}
	fmt.Println(data[1] * data[0])
}

func main(){
	var a, b int
	fmt.Scanln(&a)
	fmt.Scanln(&b)
	data := [2]int{a, b}
	compute(data)
}
