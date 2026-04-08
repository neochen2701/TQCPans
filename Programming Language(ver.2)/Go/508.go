package main
import (
	"fmt"
	"strconv"
)

func convert(a string) int64 {
	if i, err := strconv.ParseInt(a, 2, 64); err == nil {
		return i;
	}
	return -1;
}

func add(a string, b string) string {
	if convert(a) + convert(b) >= 255 {
		return "11111111"
	}else{
		return strconv.FormatInt(convert(a) + convert(b), 2)
	}
}

func main(){
	var a string
	var b string
	fmt.Scanln(&a)
	fmt.Scanln(&b)
	fmt.Printf("%d + %d = %d\n", convert(a), convert(b), convert(a) + convert(b))
	fmt.Printf("%08s", add(a, b))
}
