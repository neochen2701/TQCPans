package main
import (
	"fmt"
	"os"
	"bufio"
)

func main(){
	file, _ := os.Open("read.txt")
	sc := bufio.NewScanner(file)
	sc.Split(bufio.ScanLines)
	var lines []string
	var number [3]int
	for sc.Scan() {
		lines = append(lines, sc.Text())
    }
	for i := 0; i < 3; i++{
		fmt.Scanln(&number[i])
	}
	for i := 0; i < 3; i++{
		temp := ""
		for j := 0; j < number[i]; j++{
			temp += string(number[i] + '0')
		}
		for j := number[i]; j < len(lines[i]); j++{
			temp += string(lines[i][j])
		}
		fmt.Println(temp)
	}
}
