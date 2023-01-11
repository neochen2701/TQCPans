package main
import "fmt"

func fab_conv(year int) int {
	if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)){
		return 29
	}else{
		return 28
	}
}

func main(){
	var year, month, day int
	
	fmt.Scan(&year)
	fmt.Scan(&month)
	fmt.Scan(&day)
	
	dict := map[int]int{
		1: 31, 
		2: fab_conv(year), 
		3: 31, 
		4: 30, 
		5: 31, 
		6: 30, 
		7: 31,
		8: 31,
		9: 30,
		10: 31,
		11: 30,
		12: 31}

	if (month < 1 || month > 12 ) || (day < 1 || day > dict[month]) {
		fmt.Println("error")
		return
	}

	var total int = 0
	for i := 1; i < month; i++ {
		total += dict[i]
	}
	total += day
	fmt.Println(total)
}
