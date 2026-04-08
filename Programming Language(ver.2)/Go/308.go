package main
import "fmt"

func compute(n int) int {
	if n == 0{
		return 0
	}else if n == 1{
		return 1
	}else{
		return compute(n-1) + compute(n-2)
	}
}

func main(){
	var n int
	fmt.Scanln(&n)
	for i := n; i > 0; i--{
		fmt.Printf("fib(%d)=%d\n", i, compute(i))
	}
}
