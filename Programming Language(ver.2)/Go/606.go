package main
import "fmt"

func main(){
	var array = make([]string, 3)
	for i := 0; i < 3; i++ {
		fmt.Scan(&array[i])
	}
	for i := 0; i < 3; i++ {
		total := ((array[i][0] - '0') + (array[i][2] - '0') + (array[i][4] - '0') + ((array[i][1] - '0') + (array[i][3] - '0')) * 5) % 26
		if (total - 1) == array[i][5] - 'A' {
			fmt.Println("Pass")
		}else{
			fmt.Println("Fail")
		}
	}
}
