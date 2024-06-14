package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Graph struct {
	edges map[int][]int
}

func NewGraph() *Graph {
	return &Graph{
		edges: make(map[int][]int),
	}
}

func (g *Graph) AddEdge(u, v int) {
	g.edges[u] = append(g.edges[u], v)
	g.edges[v] = append(g.edges[v], u)
}

func (g *Graph) FindAllPaths(start, end int, visited map[int]bool, path []int, allPaths *[][]int) {
	visited[start] = true
	path = append(path, start)

	if start == end {
		newPath := make([]int, len(path))
		copy(newPath, path)
		*allPaths = append(*allPaths, newPath)
	} else {
		for _, next := range g.edges[start] {
			if !visited[next] {
				g.FindAllPaths(next, end, visited, path, allPaths)
			}
		}
	}

	path = path[:len(path)-1]
	visited[start] = false
}

func getMaxPath(allPaths [][]int) []int {
	maxPath := []int{}
	maxLen := 0
	maxSum := 0

	for _, path := range allPaths {
		pathSum := 0
		for _, v := range path {
			pathSum += v
		}
		if len(path) > maxLen || (len(path) == maxLen && pathSum > maxSum) {
			maxLen = len(path)
			maxSum = pathSum
			maxPath = path
		}
	}

	return maxPath
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	firstLine := strings.Fields(scanner.Text())
	n, _ := strconv.Atoi(firstLine[0])
	m, _ := strconv.Atoi(firstLine[1])

	graph := NewGraph()

	for i := 0; i < m; i++ {
		scanner.Scan()
		edge := strings.Fields(scanner.Text())
		u, _ := strconv.Atoi(edge[0])
		v, _ := strconv.Atoi(edge[1])
		graph.AddEdge(u, v)
	}

	scanner.Scan()
	lastLine := strings.Fields(scanner.Text())
	start, _ := strconv.Atoi(lastLine[0])
	end, _ := strconv.Atoi(lastLine[1])

	var allPaths [][]int
	visited := make(map[int]bool, n)
	graph.FindAllPaths(start, end, visited, []int{}, &allPaths)

	maxPath := getMaxPath(allPaths)

	for i, v := range maxPath {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	fmt.Println()
}
