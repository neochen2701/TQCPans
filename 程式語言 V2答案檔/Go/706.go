package main
import (
	"fmt"
	os "os"
	"bufio"
	"strconv"
	"sort"
)

func create_file(filename string) *os.File{
	f, err := os.Create("write.txt")
	if err != nil{
		panic(err)
	}
	return f
}

func output_text_to_file(f *os.File, text string){
	w := bufio.NewWriter(f)
	_, err := w.WriteString(text)
	if err != nil{
		panic(err)
	}
	w.Flush()
}

func main(){
	file, _ := os.Open("read.txt")
	sc := bufio.NewScanner(file)
	sc.Split(bufio.ScanLines)
	var number []int
	for i := 0; i < 4; i++{
		var val int
		fmt.Scanln(&val)
		number = append(number, val)
	}
	for sc.Scan() {
		val, _ := strconv.ParseInt(sc.Text(), 10, 64)
		number = append(number, int(val))
	}
	sort.Ints(number)
	output := ""
	for i := 0; i < len(number); i++ {
		output += strconv.Itoa(number[i]) + "\n"
	}
	f := create_file("write.txt")
	output_text_to_file(f, output)
}
