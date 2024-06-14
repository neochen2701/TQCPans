package main

import (
	"fmt"
	"sort"
)

type Order struct {
	orderNumber, time, value int
}

type Validate struct {
	orders     []Order
	totalValue int
}

func getOrdersFromFile(n int) ([]Order, int) {
	orders := make([]Order, n)
	var availableTime int
	for i := 0; i < n; i++ {
		fmt.Scan(&orders[i].orderNumber, &orders[i].time, &orders[i].value)
	}
	fmt.Scan(&availableTime)
	return orders, availableTime
}

func printAnswer(v Validate) {
	for i, order := range v.orders {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(order.orderNumber)
	}
	fmt.Printf("\n%d\n", v.totalValue)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func findSelectedOrders(orders []Order, availableTime int) Validate {
	n := len(orders)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, availableTime+1)
	}

	for i := 1; i <= n; i++ {
		for j := 0; j <= availableTime; j++ {
			if orders[i-1].time > j {
				dp[i][j] = dp[i-1][j]
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-orders[i-1].time]+orders[i-1].value)
			}
		}
	}

	var v Validate
	j := availableTime
	for i := n; i > 0; i-- {
		if dp[i][j] != dp[i-1][j] {
			v.orders = append(v.orders, orders[i-1])
			v.totalValue += orders[i-1].value
			j -= orders[i-1].time
		}
	}

	for i, j := 0, len(v.orders)-1; i < j; i, j = i+1, j-1 {
		v.orders[i], v.orders[j] = v.orders[j], v.orders[i]
	}

	return v
}

func dynamicProg(orders []Order, availableTime int) {
	v := findSelectedOrders(orders, availableTime)
	sort.Slice(v.orders, func(i, j int) bool {
		return v.orders[i].orderNumber < v.orders[j].orderNumber
	})
	printAnswer(v)
}

func main() {
	var n int
	fmt.Scan(&n)
	orders, availableTime := getOrdersFromFile(n)
	dynamicProg(orders, availableTime)
}
