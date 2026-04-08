package main
import "fmt"

func main(){
	var a int
	fmt.Scanln(&a)
	var visited = make([]bool,a+1)
	for i := 2; i < a; i++{
		if visited[i] == true{
			continue;
		}
		fmt.Printf("%d ", i)
		for j := i+i; j <= a; j += i{
			visited[j] = true;
		}
	}
}