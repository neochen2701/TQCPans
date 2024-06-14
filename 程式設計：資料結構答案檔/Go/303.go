package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

type FruitCombo struct {
	First  string
	Second string
	Count  int
}

func generateCombinations(items []string) []FruitCombo {
	var combinations []FruitCombo
	for i := 0; i < len(items); i++ {
		for j := i + 1; j < len(items); j++ {
			if items[i] < items[j] {
				combinations = append(combinations, FruitCombo{items[i], items[j], 0})
			} else {
				combinations = append(combinations, FruitCombo{items[j], items[i], 0})
			}
		}
	}
	return combinations
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	var n int
	fmt.Sscanf(scanner.Text(), "%d", &n)

	combinationsMap := make(map[string]int)

	for i := 0; i < n; i++ {
		scanner.Scan()
		fruits := strings.Fields(scanner.Text())
		sort.Strings(fruits)
		combinations := generateCombinations(fruits)
		for _, combo := range combinations {
			key := combo.First + " " + combo.Second
			combinationsMap[key]++
		}
	}

	var combos []FruitCombo
	for key, count := range combinationsMap {
		split := strings.Split(key, " ")
		combos = append(combos, FruitCombo{split[0], split[1], count})
	}

	sort.Slice(combos, func(i, j int) bool {
		if combos[i].Count == combos[j].Count {
			return combos[i].First+combos[i].Second > combos[j].First+combos[j].Second
		}
		return combos[i].Count > combos[j].Count
	})

	for i := 0; i < 3 && i < len(combos); i++ {
		fmt.Printf("%s %s %d\n", combos[i].First, combos[i].Second, combos[i].Count)
	}
}
