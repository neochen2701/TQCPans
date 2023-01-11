package main
import "fmt"

func main(){
	var str string
	value := 1
	fmt.Scanln(&str)
	for i := 0; i < len(str); i++ {
		fmt.Print(string(str[i]))
		value *= int(str[i] - '0')
		if i != len(str) - 1{
			fmt.Print("*")
		}
	}
	fmt.Print("=")
	fmt.Print(value)
}
