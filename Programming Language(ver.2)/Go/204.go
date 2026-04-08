package main
import "fmt"

func main(){
	var a, b int
	var operator string
	fmt.Scanln(&a)
	fmt.Scanln(&b)
	fmt.Scanln(&operator)
	if operator == "+"{
		fmt.Printf("%d+%d=%d\n", a, b, a+b)
	}else if operator == "-"{
		fmt.Printf("%d-%d=%d\n", a, b, a-b)
	}else if operator == "*"{
		fmt.Printf("%d*%d=%d\n", a, b, a*b)
	}else{
		fmt.Println("error")
	}
}