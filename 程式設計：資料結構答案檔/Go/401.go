package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readGraphFromFile(filename string) ([][]int, int, error) {
	file, err := os.Open(filename)
	if err != nil {
		return nil, 0, err
	}
	defer file.Close()

	var graph [][]int
	scanner := bufio.NewScanner(file)
	numVertices := 0

	for scanner.Scan() {
		line := scanner.Text()
		tokens := strings.Split(line, ",")
		if numVertices == 0 {
			numVertices = len(tokens)
		}
		row := make([]int, numVertices)
		for i, token := range tokens {
			value, err := strconv.Atoi(token)
			if err != nil {
				return nil, 0, err
			}
			row[i] = value
		}
		graph = append(graph, row)
	}
	return graph, numVertices, nil
}

func main() {
	graph, numVertices, err := readGraphFromFile("read.txt")
	if err != nil {
		fmt.Println("Error reading graph from file:", err)
		return
	}

	degrees := make([]int, numVertices)
	var maxWeight, minWeight int = 0, 1<<31 - 1

	for i := 0; i < numVertices; i++ {
		weightSum := 0
		for j := 0; j < numVertices; j++ {
			if graph[i][j] > 0 {
				degrees[i]++
				weightSum += graph[i][j]
			}
		}
		if weightSum > maxWeight {
			maxWeight = weightSum
		}
		if weightSum < minWeight {
			minWeight = weightSum
		}
	}

	fmt.Print("Degree:")
	for i, deg := range degrees {
		fmt.Print(deg)
		if i < numVertices-1 {
			fmt.Print(",")
		}
	}
	fmt.Println()
	fmt.Println(maxWeight - minWeight)
}
