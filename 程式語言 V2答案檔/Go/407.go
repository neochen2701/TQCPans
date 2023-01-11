package main
import (
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
	lines := ""
	for sc.Scan() {
		lines += sc.Text()
    }
	converted_line := ""
	for i := 0; i < len(lines); i++{
		if string(lines[i]) == "*"{
			continue
		}
		converted_line += string(lines[i])
	}
	f := create_file("write.txt")
	output_text_to_file(f, converted_line)
}
