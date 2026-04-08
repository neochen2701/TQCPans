package main
import "fmt"

func compute(test int) int {
	for i := 2; i < test; i++{
		if test % i == 0{
			return 0
		}
	}
	return 1
}

func main(){
	var test int
	fmt.Scanln(&test)
	if compute(test) == 0{
		fmt.Printf("%d is not a prime number", test)
	}else{
		fmt.Printf("%d is a prime number", test)
	}
}
