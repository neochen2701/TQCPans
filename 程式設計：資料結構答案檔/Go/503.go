package main

import (
	"fmt"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n1, n2 int
	fmt.Scan(&n1, &n2)

	A := make([]int, n1+1)
	B := make([]int, n2+1)

	for i := 1; i <= n1; i++ {
		fmt.Scan(&A[i])
	}
	for j := 1; j <= n2; j++ {
		fmt.Scan(&B[j])
	}

	DP := make([]int, n2+1)

	for i := 1; i <= n1; i++ {
		temp := make([]int, n2+1)
		for j := 1; j <= n2; j++ {
			if A[i] != B[j] {
				temp[j] = max(temp[j-1], DP[j])
			} else {
				temp[j] = DP[j-1] + 1
			}
		}
		DP = temp
	}

	fmt.Println(DP[n2])
}
