package main
import "fmt"

func main(){
	var s1, s2 string
	fmt.Scanln(&s1)
	fmt.Scanln(&s2)
	fmt.Println(len(s1))
	fmt.Println(len(s2))
	fmt.Println(s1 + s2)
}
