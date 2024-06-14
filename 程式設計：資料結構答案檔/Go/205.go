package main

import (
	"fmt"
)

type Rectangle struct {
	area, top, left, bottom, right int
}

func largestRectangleArea(heights []int, row int) Rectangle {
	n := len(heights)
	left := make([]int, n)
	right := make([]int, n)
	for i := range right {
		right[i] = n
	}
	var stk []int
	maxRect := Rectangle{0, row, 0, row, 0}

	for i := 0; i < n; i++ {
		for len(stk) > 0 && heights[stk[len(stk)-1]] >= heights[i] {
			right[stk[len(stk)-1]] = i
			stk = stk[:len(stk)-1]
		}
		if len(stk) == 0 {
			left[i] = 0
		} else {
			left[i] = stk[len(stk)-1] + 1
		}
		stk = append(stk, i)
	}

	for i := 0; i < n; i++ {
		area := heights[i] * (right[i] - left[i])
		if area > maxRect.area {
			maxRect = Rectangle{area, row - heights[i] + 1, left[i], row, right[i] - 1}
		}
	}

	return maxRect
}

func findLargestRectangleArea(matrix [][]int) Rectangle {
	n := len(matrix)
	if n == 0 {
		return Rectangle{0, 0, 0, 0, 0}
	}
	m := len(matrix[0])
	if m == 0 {
		return Rectangle{0, 0, 0, 0, 0}
	}

	heights := make([]int, m)
	maxRect := Rectangle{0, 0, 0, 0, 0}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if matrix[i][j] == 1 {
				heights[j]++
			} else {
				heights[j] = 0
			}
		}
		rect := largestRectangleArea(heights, i)
		if rect.area > maxRect.area {
			maxRect = rect
		}
	}

	return maxRect
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	matrix := make([][]int, n)
	for i := range matrix {
		matrix[i] = make([]int, m)
		for j := range matrix[i] {
			fmt.Scan(&matrix[i][j])
		}
	}

	maxRect := findLargestRectangleArea(matrix)
	fmt.Println(maxRect.area)
	fmt.Printf("(%d, %d)\n", maxRect.top, maxRect.left)
	fmt.Printf("(%d, %d)\n", maxRect.bottom, maxRect.right)
}
