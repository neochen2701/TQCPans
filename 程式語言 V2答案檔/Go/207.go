package main
import "fmt"

func main(){
	var a int
	fmt.Scanln(&a)
	find := false 
	for i := 2; i < a; i++{
		if a % i == 0{
			find = true
		}
	}
	if find {
		fmt.Printf("%d is not a prime number\n", a)
	}else{
		fmt.Printf("%d is a prime number\n", a)
	}
}