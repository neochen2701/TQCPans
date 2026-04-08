package main
import (
	"fmt"
	"strconv"
	"strings"
)

func main(){
	var data string
	fmt.Scanln(&data)
	split := strings.Split(data, "/")
	var total int64 = 0
	for i := 0; i < len(split); i++ {
		value, _ := strconv.ParseInt(split[i], 10, 64)
		fmt.Printf("%d", value)
		if i != len(split) -1 {
			fmt.Print(" ")
		}
		total += value
	}
	fmt.Println()
	fmt.Println(total)
}
