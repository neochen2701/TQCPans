package main
import (
	"fmt"
	"os"
	"bufio"
	"strings"
	"strconv"
)

func main(){
	reader := bufio.NewReader(os.Stdin)
	s1b, _ := reader.ReadString('\n')
	s2b, _ := reader.ReadString('\n')
	nb, _ := reader.ReadString('\n')
	s1 := strings.ReplaceAll(strings.TrimSuffix(string(s1b), "\n"), "\r", "")
	s2 := strings.ReplaceAll(strings.TrimSuffix(string(s2b), "\n"), "\r", "")
	n, _ := strconv.Atoi(strings.ReplaceAll(strings.TrimSuffix(string(nb), "\n"), "\r", ""))

	if n > len(s1) || n > len(s2){
		fmt.Printf("error")
		return;
	}

	if strings.Compare(s1[:n], s2[:n]) == -1{
		fmt.Printf("%s < %s\n", s1, s2)
	}else if strings.Compare(s1[:n], s2[:n]) == 1 {
		fmt.Printf("%s > %s\n", s1, s2)
	}else{
		fmt.Printf("%s = %s\n", s1, s2)
	}
}
