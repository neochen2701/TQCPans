package main
import "fmt"

func main(){
	var num int
	fmt.Scanln(&num)
	var prime []int
	temp := num
	for i := 2; i < num; i++{
		for j := 0; temp % i == 0; j++{
			prime = append(prime, i)
			temp /= i;
		}
	}
	if len(prime) > 0 {
		for i := 0; i < len(prime); i++{
			fmt.Print(prime[i])
			if i != len(prime) - 1 {
				fmt.Print("*")
			}
		}
		fmt.Println()
	}else{
		fmt.Println("-1")
	}
}
