package main
import "fmt"

func main(){
	var count int = 0;
	for i := 0; i < 3; i++{
		var hour, minutes int
		fmt.Scan(&hour)
		fmt.Scan(&minutes)
		var conv_hour int = hour
		var conv_minutes int = minutes
		if hour == 0{
			conv_hour = 12
		} else if hour > 12 {
			conv_hour = hour - 12
		}
		if hour < 12 {
			fmt.Printf("AM %d:%d\n", conv_hour, conv_minutes)
			count += 1
		}else{
			fmt.Printf("PM %d:%d\n", conv_hour, conv_minutes)
		}
	}
	fmt.Println(count)
}
