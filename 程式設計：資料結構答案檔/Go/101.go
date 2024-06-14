package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func calculateSumAvg(inputs [][]string) {
	for i, studentScores := range inputs {
		var sum int
		for _, score := range studentScores[1:] {
			n, err := strconv.Atoi(score)
			if err != nil {
				fmt.Println("Error converting score to integer:", err)
				return
			}
			sum += n
		}
		avg := float64(sum) / float64(len(studentScores)-1)
		inputs[i] = append(inputs[i], strconv.Itoa(sum))
		inputs[i] = append(inputs[i], fmt.Sprintf("%.2f", avg))
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var inputs [][]string

	for scanner.Scan() {
		inputStr := scanner.Text()
		if inputStr == "END" {
			break
		}
		inputScores := strings.Split(inputStr, " ")
		inputs = append(inputs, inputScores)
	}

	calculateSumAvg(inputs)

	sort.Slice(inputs, func(i, j int) bool {
		a, errA := strconv.ParseFloat(inputs[i][len(inputs[i])-2], 64)
		b, errB := strconv.ParseFloat(inputs[j][len(inputs[j])-2], 64)
		if errA != nil || errB != nil {
			return false
		}
		return a > b
	})

	for _, studentScores := range inputs {
		fmt.Println(strings.Join(studentScores, " "))
	}
}
