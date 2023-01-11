package main
import "fmt"

func main(){
	var array [6]string
	for i := 0; i < 6; i++ {
		fmt.Scanln(&array[i])
	}
	for i := 0; i < 2; i++ {
		for j := 0; j < 3; j++ {
			fmt.Printf("%10s", array[3*i+j])
			if j != 2 {
				fmt.Print(" ");
			}
		}
		fmt.Println()
	}
	for i := 0; i < 2; i++ {
		for j := 0; j < 3; j++ {
			fmt.Printf("%-10s", array[3*i+j])
			if j != 2 {
				fmt.Print(" ");
			}
		}
		fmt.Println()
	}
}
