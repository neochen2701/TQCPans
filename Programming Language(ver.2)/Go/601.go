package main
import "fmt"

func main(){
	var str string
	var index int
	var result = ""
	fmt.Scan(&str)
	fmt.Scan(&index)
	for i := 0; i < len(str); i++ {
		if i == index {
			if 'a' <= str[i] && str[i] <= 'z' {
				result += string(str[i] - 'a' + 'A')
			}else{
				result += string(str[i] - 'A' + 'a')
			}
		}else{
			result += string(str[i])
		}
	}
	fmt.Printf("The letter that was selected is: %s\n", string(result[index]))
	fmt.Println(result)
}
