package main
import "fmt"

func main(){
	var a int
	fmt.Scanln(&a)
	if a % 2 == 0{
		fmt.Println("even")
	}else{
		fmt.Println("odd")
	}
}