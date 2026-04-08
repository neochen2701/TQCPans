package main
import "fmt"

func main(){
	var a float32
	var b float32
	fmt.Scanln(&a)
	fmt.Scanln(&b)
	fmt.Printf("total=%.2f", (a+b))
}