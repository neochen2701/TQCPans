package main
import "fmt"

func main(){
	var str string
	fmt.Scanln(&str)
	converted := ""
	for i := 0; i < len(str); i++{
		if str[i] >= 'A' && str[i] <= 'Z'{
			converted += string(str[i] - 'A' + 'a')
		}else{
			converted += string(str[i] - 'a' + 'A')
		}
	}
	fmt.Println(converted)
}
