package main
import (
	"fmt"
	"math"
	"strconv"
)

func compute(n int) int {
	total := 0
	for i := 1; i < n; i++{
		s := strconv.Itoa(i)
		sum := 0
		for j := 0; j < len(s); j++{
			digit := float64(int(s[j] - '0'))
			length := float64(len(s))
			//fmt.Println(i, digit, length)
			sum += int(math.Pow(digit, length))
		}
		
		if sum == i{
			total += i
			fmt.Println(i)
		}
	}
	return total
}

func main(){
	var n int
	fmt.Scanln(&n)
	fmt.Println(compute(n))
}
