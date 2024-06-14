package main

import "fmt"

const ROW = 4
const COL = 4

func getNum(board [ROW][COL]int, row int, col int, result *int) bool {
	if board[row][col] != 0 {
		return false
	}

	data := [4]int{1, 2, 3, 4}

	for i := 0; i < COL; i++ {
		if board[row][i] != 0 {
			for j := 0; j < 4; j++ {
				if data[j] == board[row][i] {
					data[j] = 0
					break
				}
			}
		}
	}

	for i := 0; i < ROW; i++ {
		if board[i][col] != 0 {
			for j := 0; j < 4; j++ {
				if data[j] == board[i][col] {
					data[j] = 0
					break
				}
			}
		}
	}

	startRow := 2 * (row / 2)
	startCol := 2 * (col / 2)

	for i := startRow; i < startRow+2; i++ {
		for j := startCol; j < startCol+2; j++ {
			if board[i][j] != 0 {
				for k := 0; k < 4; k++ {
					if data[k] == board[i][j] {
						data[k] = 0
						break
					}
				}
			}
		}
	}

	count := 0
	for i := 0; i < 4; i++ {
		if data[i] != 0 {
			*result = data[i]
			count++
		}
	}

	return count == 1
}

func modifyBoard(board [ROW][COL]int) ([ROW][COL]int, bool) {
	change := false
	for row := 0; row < ROW; row++ {
		for col := 0; col < COL; col++ {
			num := 0
			if getNum(board, row, col, &num) {
				board[row][col] = num
				change = true
			}
		}
	}
	return board, change
}

func printBoard(board [ROW][COL]int) {
	for row := 0; row < ROW; row++ {
		for col := 0; col < COL; col++ {
			if col < COL-1 {
				fmt.Printf("%d ", board[row][col])
			} else {
				fmt.Printf("%d", board[row][col])
			}
		}
		fmt.Println()
	}
}

func getData() [ROW][COL]int {
	var board [ROW][COL]int
	for row := 0; row < ROW; row++ {
		for col := 0; col < COL; col++ {
			fmt.Scan(&board[row][col])
		}
	}
	return board
}

func processOnce() {
	board := getData()
	changed := true
	for changed {
		board, changed = modifyBoard(board)
	}
	printBoard(board)
}

func main() {
	processOnce()
}
