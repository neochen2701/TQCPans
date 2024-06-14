package main

import (
	"fmt"
	"sort"
	"strings"
)

func inorderTree(idx int, lst []string) {
	if idx < len(lst) && lst[idx] != "" {
		inorderTree(2*idx, lst)
		fmt.Print(lst[idx])
		inorderTree(2*idx+1, lst)
	}
}

func leafNode(lst []string) {
	var leaves []string

	for i := 1; i < len(lst); i++ {
		if (2*i >= len(lst) || lst[2*i] == "") && (2*i+1 >= len(lst) || lst[2*i+1] == "") {
			leaves = append(leaves, lst[i])
		}
	}

	sort.Strings(leaves)
	fmt.Println(strings.Join(leaves, ""))
}

func main() {
	var input string
	fmt.Scanln(&input)
	lst := append([]string{""}, strings.Split(input, ",")...)

	inorderTree(1, lst)
	fmt.Println()
	leafNode(lst)
}
