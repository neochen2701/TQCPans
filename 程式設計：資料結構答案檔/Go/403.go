package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n, v, threshold int
	fmt.Scan(&n, &v, &threshold)

	visited := make([]bool, n+1)
	node := make(map[int][][2]int)

	var v0, v1, w int
	for i := 0; i < n-1; i++ {
		fmt.Scan(&v0, &v1, &w)
		node[v0] = append(node[v0], [2]int{v1, w})
		node[v1] = append(node[v1], [2]int{v0, w})
	}

	type pair struct {
		node, weight int
	}
	queue := []pair{{v, 1<<31 - 1}}
	visited[v] = true

	ans := 0
	for len(queue) > 0 {
		t := queue[0]
		queue = queue[1:]

		for _, p := range node[t.node] {
			if visited[p[0]] {
				continue
			}

			visited[p[0]] = true
			currentWeight := min(t.weight, p[1])
			if currentWeight >= threshold {
				ans++
				queue = append(queue, pair{p[0], currentWeight})
			}
		}
	}

	fmt.Println(ans)
}
