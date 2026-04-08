package main
import "fmt"

func main(){
	var n1, m1, n2, m2 int

	fmt.Scan(&n1)
	fmt.Scan(&m1)
	
	var matrix1 = make([][]int, n1)
	for i := 0; i < n1; i++{
		matrix1[i] = make([]int, m1)
		for j := 0; j < m1; j++ {
			fmt.Scan(&matrix1[i][j])
		}
	}

	fmt.Scan(&n2)
	fmt.Scan(&m2)

	var matrix2 = make([][]int, n2)
	for i := 0; i < n2; i++{
		matrix2[i] = make([]int, m2)
		for j := 0; j < m2; j++ {
			fmt.Scan(&matrix2[i][j])
		}
	}

	if m1 != n2 {
		fmt.Println("error")
		return
	}

	var result = make([][]int, n1)

	for i := 0; i < n1; i++ {
		result[i] = make([]int, m2)
		for j := 0; j < m2; j++ {
			result[i][j] = 0
			for k := 0; k < n2; k++ {
				result[i][j] += matrix1[i][k] * matrix2[k][j]
			}
		}
	}

	for i := 0; i < n1; i++ {
		for j := 0; j < m2; j++ {
			fmt.Printf("%d", result[i][j])
			if j != m2 - 1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}
