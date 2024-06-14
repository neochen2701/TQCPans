package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func requestQuests(input string) ([]int, error) {
	tasks := []int{}
	for _, part := range strings.Split(input, ",") {
		taskReward, err := strconv.Atoi(part)
		if err != nil {
			return nil, fmt.Errorf("error")
		}
		if taskReward < 0 {
			return nil, fmt.Errorf("error")
		}
		tasks = append(tasks, taskReward)
	}
	return tasks, nil
}

func calculateTotalReward(tasks []int) int {
	totalReward := 0
	morningTasks := 3
	noonTasks := 2
	nightTasks := 1

	i := 0
	for i < len(tasks) {
		for j := 0; j < morningTasks && i < len(tasks); j++ {
			totalReward += tasks[i] * 3
			i++
		}
		for j := 0; j < noonTasks && i < len(tasks); j++ {
			totalReward += tasks[i] * 2
			i++
		}
		for j := 0; j < nightTasks && i < len(tasks); j++ {
			totalReward += tasks[i]
			i++
		}
	}
	return totalReward
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	tasks, err := requestQuests(input)
	if err != nil {
		fmt.Println(err)
		return
	}

	totalReward := calculateTotalReward(tasks)
	fmt.Println(totalReward)
}
