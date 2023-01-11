package main
import "fmt"

func main(){
	var str string
	var uppercase = ""
	var lowercase = ""
	fmt.Scan(&str)
	for i := 0; i < len(str); i++ {
		if 'a' <= str[i] && str[i] <= 'z' {
			lowercase += string(str[i])
		}else{
			uppercase += string(str[i])
		}
	}
	fmt.Println(uppercase)
	fmt.Println(lowercase)
	fmt.Println(len(uppercase))
}
