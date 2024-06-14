package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Activity struct {
	Start, End int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	activities := make([]Activity, 0, n)

	for i := 0; i < n && scanner.Scan(); i++ {
		line := scanner.Text()
		parts := strings.Split(line, ",")
		if len(parts) < 2 {
			fmt.Fprintf(os.Stderr, "Invalid input format: %s\n", line)
			return
		}
		start, _ := strconv.Atoi(parts[0])
		end, _ := strconv.Atoi(parts[1])
		activities = append(activities, Activity{Start: start, End: end})
	}

	sort.Slice(activities, func(i, j int) bool {
		return activities[i].End < activities[j].End
	})

	selectCount := 1
	current := activities[0]
	for i := 1; i < n; i++ {
		if current.End <= activities[i].Start {
			current = activities[i]
			selectCount++
		}
	}

	fmt.Println(selectCount)
}
