package main
import (
	"fmt"
	os "os"
	"bufio"
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
	var lines []string
	for sc.Scan() {
		lines = append(lines, sc.Text())
    }
	number := 0
	fmt.Scanln(&number)
	output := ""
	for i := 0; i < number; i++{
		new_string := ""
		for j := 0; j < len(lines[i]); j++{
			if j == 0 || (j > 0 && lines[i][j-1] == ' '){
				new_string += string(lines[i][j] - 'a' + 'A')
			}else{
				new_string += string(lines[i][j])
			}
		}
		fmt.Println(new_string)
		output += new_string + "\n"
	}
	f := create_file("write.txt")
	output_text_to_file(f, output)
}
