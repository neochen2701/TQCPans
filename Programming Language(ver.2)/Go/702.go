package main
import (
	"fmt"
	"strconv"
)

func main(){
	var str string
	fmt.Scan(&str)
	val, _ := strconv.ParseInt(str, 2, 64)
	fmt.Println(val)
}
