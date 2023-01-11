package main
import "fmt"

func main(){
	var operator int
	fmt.Scanln(&operator)
	if operator != 0 && operator != 1{
		fmt.Println("error")
		return
	}
	for i := 1; i <= 5; i++{
		for j := 1; j <= 5; j++{
			if operator == 0{
				fmt.Printf("%d x %d = %d\t", i, j, i*j)
			}else{
				fmt.Printf("%d x %d = %d\t", j, i, i*j)
			}
		}
		fmt.Println()
	}
}
