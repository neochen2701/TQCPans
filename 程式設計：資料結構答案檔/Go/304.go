package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Print("")
	scanner.Scan()
	var m int
	fmt.Sscanf(scanner.Text(), "%d", &m)

	fabrics := make([]string, m)
	for i := 0; i < m; i++ {
		scanner.Scan()
		fabrics[i] = scanner.Text()
	}

	sort.Strings(fabrics)

	ans := 0
	for _, s1 := range fabrics {
		s1Len := len(s1)
		for i := 1; i <= s1Len/2; i++ {
			if s1[:i] == s1[s1Len-i:] {
				subStr := s1[i : s1Len-i]
				index := sort.SearchStrings(fabrics, subStr)
				if index < len(fabrics) && fabrics[index] == subStr {
					ans++
				}
			}
		}
	}

	fmt.Println(ans)
}
