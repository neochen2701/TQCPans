package main

import (
	"encoding/csv"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type Player struct {
	Id    int
	Name  string
	Level int
	Score int
}

func readCsv(filePath string) ([]Player, error) {
	file, err := os.Open(filePath)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	csvReader := csv.NewReader(file)
	records, err := csvReader.ReadAll()
	if err != nil {
		return nil, err
	}

	var players []Player
	for _, record := range records[1:] {
		id, _ := strconv.Atoi(record[0])
		level, _ := strconv.Atoi(record[2])
		score, _ := strconv.Atoi(record[3])
		players = append(players, Player{Id: id, Name: record[1], Level: level, Score: score})
	}

	return players, nil
}

func main() {
	filePath := "read.csv"
	players, err := readCsv(filePath)
	if err != nil {
		fmt.Println("Error reading CSV file:", err)
		return
	}

	var n int
	_, err = fmt.Scanf("%d", &n)
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	sort.Slice(players, func(i, j int) bool {
		if players[i].Score == players[j].Score {
			return players[i].Id > players[j].Id
		}
		return players[i].Score > players[j].Score
	})

	if n > len(players) {
		fmt.Println("Exceeds data upper limit")
	} else {
		for i := 0; i < n; i++ {
			fmt.Printf("%d | %d | %s | %d | %d\n", i+1, players[i].Id, players[i].Name, players[i].Level, players[i].Score)
		}
	}
}
