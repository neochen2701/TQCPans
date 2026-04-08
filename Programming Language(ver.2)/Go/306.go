package main
import "fmt"

func compute(n int) int {
	if n == 0{
		return 1;
	}else{
		return n * compute(n-1);
	}
}

func main(){
	var n int
	fmt.Scanln(&n)
	fmt.Printf("%d!=%d", n, compute(n))
}
