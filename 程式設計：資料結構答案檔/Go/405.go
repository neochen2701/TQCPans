package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	firstLine := strings.Split(scanner.Text(), " ")
	m, _ := strconv.Atoi(firstLine[0])
	n, _ := strconv.Atoi(firstLine[1])

	scanner.Scan()
	secondLine := strings.Split(scanner.Text(), " ")
	s, _ := strconv.Atoi(secondLine[0])
	t, _ := strconv.Atoi(secondLine[1])

	adjArrayOfGraph := make([][]float64, m+1)
	for i := range adjArrayOfGraph {
		adjArrayOfGraph[i] = make([]float64, m+1)
		for j := range adjArrayOfGraph[i] {
			adjArrayOfGraph[i][j] = math.Inf(1)
		}
	}

	for i := 0; i < n; i++ {
		scanner.Scan()
		line := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(line[0])
		b, _ := strconv.Atoi(line[1])
		d, _ := strconv.ParseFloat(line[2], 64)
		adjArrayOfGraph[a][b] = d
		adjArrayOfGraph[b][a] = d
	}

	distance := make([]float64, m+1)
	for i := range distance {
		distance[i] = math.Inf(1)
	}
	distance[s] = 0

	visited := make([]bool, m+1)

	for i := 0; i < m; i++ {
		minIndex := -1
		minDistance := math.Inf(1)
		for j := 1; j <= m; j++ {
			if !visited[j] && distance[j] < minDistance {
				minIndex = j
				minDistance = distance[j]
			}
		}

		if minIndex == -1 {
			break
		}

		visited[minIndex] = true

		for j := 1; j <= m; j++ {
			if !visited[j] && adjArrayOfGraph[minIndex][j] != math.Inf(1) {
				if distance[minIndex]+adjArrayOfGraph[minIndex][j] < distance[j] {
					distance[j] = distance[minIndex] + adjArrayOfGraph[minIndex][j]
				}
			}
		}
	}

	fmt.Printf("%.1f\n", distance[t])
}
