package main
import "fmt"

func main(){
	var data string
	fmt.Scanln(&data)
	find := true
	for i := 0; i < len(data) / 2; i++ {
		if data[i] != data[len(data)-i-1] {
			find = false
		}
	}
	if find == true {
		fmt.Println("Yes")
	}else{
		fmt.Println("No")
	}
}
