package main
import "fmt"

func main(){
	var a int
	fmt.Scan(&a)
	
	if a > 100{
		fmt.Println("error")
		return
	}

	if a > 60{
		a += 10
	}else{
		a += 5
	}

	fmt.Println(a)
}
