package main

import "fmt"

func findLowerArea(matrix [][]int, x, y, w, h int) int {
	if matrix[x][y] > 0 || matrix[x][y] == -2 || matrix[x][y] == -1 {
		return 0
	}
	matrix[x][y] = -1
	return 1 + findLowerArea(matrix, x-1, y, w, h) + findLowerArea(matrix, x+1, y, w, h) +
		findLowerArea(matrix, x, y-1, w, h) + findLowerArea(matrix, x, y+1, w, h)
}

func main() {
	var m, n int
	fmt.Scan(&m, &n)

	matrix := make([][]int, m+2)
	for i := range matrix {
		matrix[i] = make([]int, n+2)
		for j := range matrix[i] {
			matrix[i][j] = -2
		}
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			fmt.Scan(&matrix[i][j])
		}
	}

	maxSize := 0
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			size := findLowerArea(matrix, i, j, m, n)
			if size > maxSize {
				maxSize = size
			}
		}
	}

	fmt.Println(maxSize)
}
