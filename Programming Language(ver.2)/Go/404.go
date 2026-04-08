package main
import "fmt"

func main(){
	var array [26]int
	var str string
	fmt.Scanln(&str)
	max := 0
	for i := 0; i < len(str); i++{
		array[str[i]-'a'] += 1
		if array[str[i]-'a'] > max{
			max = array[str[i]-'a']
		}
	}
	for i := 0; i < 26; i++{
		if array[i] == max{
			fmt.Println(string('a'+i))
			fmt.Println(max)
		}
	}
}
