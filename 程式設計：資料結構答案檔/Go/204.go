package main

import (
	"fmt"
)

func main() {
	var n, x int
	fmt.Scanln(&n)
	fmt.Scanln(&x)

	allIds := make([]int, 0, n)
	for i := 1; i <= n; i++ {
		allIds = append(allIds, i)
	}

	for len(allIds) > 1 {
		for i := 1; i < x; i++ {
			t := allIds[0]
			allIds = allIds[1:]
			allIds = append(allIds, t)
		}
		allIds = allIds[1:]
	}

	fmt.Println(allIds[0])
}
