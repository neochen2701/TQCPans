package main
import "fmt"

func main(){
	var input int
	fmt.Scanln(&input)
	fmt.Printf("%.2f\n", float32(input) * 23.34)
}
