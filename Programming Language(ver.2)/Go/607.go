package main
import (
	"fmt"
	"strconv"
)

func point(c string) int {
	if c == "S"{
		return 4
	}else if c == "H"{
		return 3
	}else if c == "D"{
		return 2
	}else if c == "C"{
		return 1
	}
	return 0
}

func main(){
	var a string
	var b string
	fmt.Scan(&a)
	fmt.Scan(&b)
	if point(string(a[0])) > point(string(b[0])){
		fmt.Printf("%s > %s\n", a, b)
	}else if point(string(a[0])) < point(string(b[0])){
		fmt.Printf("%s < %s\n", a, b)
	}else{
		point_a, _ := strconv.ParseInt(a[1:], 10, 64)
		point_b, _ := strconv.ParseInt(b[1:], 10, 64)
		if point_a < point_b {
			fmt.Printf("%s < %s\n", a, b)
		}else if point_a > point_b{
			fmt.Printf("%s > %s\n", a, b)
		}else{
			fmt.Printf("%s = %s\n", a, b)
		}
	}
}
