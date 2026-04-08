package main
import "fmt"

func main(){
	var score int
	fmt.Scanln(&score)
	if score > 100 || score < 0 {
		fmt.Println("error")
		return
	}
	if score >= 60 {
		fmt.Println("pass")
	}else{
		fmt.Println("fail")
	}
	if score % 2 == 0 {
		fmt.Println("even")
	}else{
		fmt.Println("odd")
	}
}