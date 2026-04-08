package main
import "fmt"

func main(){
	dict := map[string]int{}
	for i := 0; i < 3; i++{
		var str string
		var val int
		fmt.Scan(&str)
		fmt.Scan(&val)
		dict[str] = val
	}
	var total = 0
	for i := 0; i < 5; i++{
		var str string
		fmt.Scan(&str)
		if val, ok := dict[str]; ok {
			total += val
		}
	}
	fmt.Println(total)
}
