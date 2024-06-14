package main

import (
	"fmt"
)

func main() {
	var m, n int
	fmt.Scan(&m)
	fmt.Scan(&n)

	matrix := make([][]int, m)
	for i := range matrix {
		matrix[i] = make([]int, n)
		for j := range matrix[i] {
			fmt.Scan(&matrix[i][j])
		}
	}

	fmt.Println("Original:")
	for _, row := range matrix {
		fmt.Print("[")
		for j, value := range row {
			if j > 0 {
				fmt.Print(" ")
			}
			fmt.Print(value)
		}
		fmt.Println("]")
	}

	transposeMatrix := make([][]int, n)
	for i := range transposeMatrix {
		transposeMatrix[i] = make([]int, m)
		for j := range transposeMatrix[i] {
			transposeMatrix[i][j] = matrix[j][i]
		}
	}

	fmt.Println("Transpose:")
	for _, row := range transposeMatrix {
		fmt.Print("[")
		for j, value := range row {
			if j > 0 {
				fmt.Print(" ")
			}
			fmt.Print(value)
		}
		fmt.Println("]")
	}
}
