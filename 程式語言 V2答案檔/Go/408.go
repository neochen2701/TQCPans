package main
import (
	"fmt"
)

func reverse(str string) string {
	result := ""
	for i := len(str) - 1; i >= 0; i--{
		result += string(str[i])
	}
	return result
}

func main(){
	var a string
	var b string
	fmt.Scanln(&a)
	fmt.Scanln(&b)
	if len(a) < 3 || len(a) > 20 || len(b) < 3 || len(b) > 20 {
		fmt.Println("error")
		return
	}
	
	fmt.Println(len(a))
	fmt.Println(len(b))
	fmt.Println(reverse(b) + reverse(a))
}
