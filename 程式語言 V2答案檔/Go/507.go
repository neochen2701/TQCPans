package main
import "fmt"

func do_task(temp string, answer string) string {
	var visited [4]bool
	a := 0
	b := 0
	for i := 0; i < 4; i++{
		if answer[i] == temp[i] {
			visited[i] = true
			a += 1
		}
	}
	for i := 0; i < 4; i++{
		if visited[i] == true{
			continue;
		}
		for j := 0; j < 4; j++{
			if answer[i] == temp[j] {
				b += 1
			}
		}
	}
	return string(a + '0') + "A" + string(b + '0') + "B"
}

func main(){
	var ans string
	fmt.Scanln(&ans)
	for i := 0; i < 3; i++ {
		var temp string
		fmt.Scanln(&temp)
		fmt.Println(do_task(temp, ans))
	}
}
