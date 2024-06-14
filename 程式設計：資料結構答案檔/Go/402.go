package main

import (
	"fmt"
)

func main() {
	var m, n int
	fmt.Scan(&m, &n)

	adjMatrix := make([][]int, m+1)
	for i := range adjMatrix {
		adjMatrix[i] = make([]int, m+1)
	}

	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		adjMatrix[a][b] = 1
		adjMatrix[b][a] = 1
	}

	degree := make([]int, m+1)
	for i := 1; i <= m; i++ {
		for j := 1; j <= m; j++ {
			if adjMatrix[i][j] == 1 {
				degree[i]++
			}
		}
	}

	numOfOddDegree := 0
	for i := 1; i <= m; i++ {
		if degree[i]%2 == 1 {
			numOfOddDegree++
		}
	}

	if numOfOddDegree == 0 || numOfOddDegree == 2 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}

	for i := 1; i <= m; i++ {
		for j := 1; j < m; j++ {
			fmt.Printf("%d ", adjMatrix[i][j])
		}
		fmt.Println(adjMatrix[i][m])
	}
}
