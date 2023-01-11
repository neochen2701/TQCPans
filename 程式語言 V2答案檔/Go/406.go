package main
import "fmt"

func main(){
	  array := [26]string{"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Z", "X", "C", "V", "B", "N", "M"}
	convert := [26]string{"W", "E", "R", "T", "Y", "U", "I", "O", "P", "P", "S", "D", "F", "G", "H", "J", "K", "L", "L", "X", "C", "V", "B", "N", "M", "M"}
	var str string
	result := ""
	fmt.Scanln(&str)
	for i := 0; i < len(str); i++{
		target := ""
		for j := 0; j < 26; j++{
			if string(array[j]) == string(str[i]) {
				target = convert[j]
			}
			if string(array[j]) == string(str[i] - 'a' + 'A') {
				target = string(convert[j][0] - 'A' + 'a')
			}
		}
		result += target
	}
	fmt.Println(result)
}
