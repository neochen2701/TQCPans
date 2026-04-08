package main
import "fmt"

func main(){
	var index int
	fmt.Scanln(&index)
	if index <= 0 || index > 4{
		fmt.Println("error")
		return
	}
	a := [4]string{"one", "two", "three", "four"}
	fmt.Println(a[index-1])
}