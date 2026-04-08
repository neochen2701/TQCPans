package main
import "fmt"

func main(){
	var a int
	var b int
	var c int
	fmt.Scanln(&a)
	fmt.Scanln(&b)
	fmt.Scanln(&c)
	fmt.Printf("%d+%d+%d=%d\n", a, b, c, a+b+c)
	fmt.Printf("%.2f", float32(a+b+c)/3.0)
}