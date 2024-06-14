package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func maxSubarraySum(arr []int) (maxSum, start, end int) {
	maxSum = arr[0]
	currentSum := arr[0]
	start = 0
	tempStart := 0
	end = 0

	for i := 1; i < len(arr); i++ {
		if currentSum+arr[i] > arr[i] {
			currentSum += arr[i]
		} else {
			currentSum = arr[i]
			tempStart = i
		}

		if currentSum > maxSum {
			maxSum = currentSum
			start = tempStart
			end = i
		}
	}

	return maxSum, start, end
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()

	inputStrings := strings.Fields(input)

	arr := make([]int, len(inputStrings))
	for i, s := range inputStrings {
		arr[i], _ = strconv.Atoi(s)
	}

	maxSum, start, end := maxSubarraySum(arr)
	fmt.Println(maxSum)
	fmt.Println(start)
	fmt.Println(end)
}
