package main
import (
	"fmt"
	"strconv"
)

func main(){
	var str string
	fmt.Scanln(&str)
	converted, _ := strconv.ParseFloat(str, 64)
	fmt.Printf("%s change to %d\n", str, int(converted))
}
