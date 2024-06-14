package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func swap(arr []int, i, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}

func bubbleSort(arr []int) {
	for i, val := range arr {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(val)
	}
	fmt.Println()

	for i := 0; i < len(arr); i++ {
		swapped := false
		for j := 0; j < len(arr)-i-1; j++ {
			if arr[j] > arr[j+1] {
				swap(arr, j, j+1)
				swapped = true
			}
		}
		if !swapped {
			break
		}
		for k, val := range arr {
			if k > 0 {
				fmt.Print(" ")
			}
			fmt.Print(val)
		}
		fmt.Println()
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	numsStr := strings.Split(scanner.Text(), " ")

	arr := make([]int, n)
	for i, str := range numsStr {
		arr[i], _ = strconv.Atoi(str)
	}

	bubbleSort(arr)
}
