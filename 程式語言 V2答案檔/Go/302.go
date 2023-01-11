package main
import "fmt"

func compute(score int) int {
	if score < 0 || score > 100{
		return -1
	} 
	if score >= 60{
		score += 5
	}else{
		score += 10
	}
	return score
}

func main(){
	var score int
	fmt.Scanln(&score)
	fmt.Println(compute(score))
}
