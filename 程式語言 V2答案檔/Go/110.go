package main
import "fmt"

func main(){
	var a, b, c int
	fmt.Scanln(&a)
	fmt.Scanln(&b)
	fmt.Scanln(&c)
	if a >= 60 && a < 100{
		fmt.Println(1)
	}else{
		fmt.Println(0)
	}
	fmt.Printf("%.2f\n", float32(b + 1) / 10.0)
	if a >= c{
		fmt.Println(a)
	}else{
		fmt.Println(c)
	}
}