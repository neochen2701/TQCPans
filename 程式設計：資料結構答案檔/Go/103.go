package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Monster struct {
	Value int
	Next  *Monster
}

type BattleSimulator struct {
	head *Monster
}

func NewBattleSimulator() *BattleSimulator {
	return &BattleSimulator{}
}

func (bs *BattleSimulator) CreateMonsters(input string) {
	values := strings.Split(input, ",")
	for _, value := range values {
		if monsterAttack, err := strconv.Atoi(value); err == nil {
			bs.AddMonster(monsterAttack)
		} else {
			fmt.Println("input error")
		}
	}
}

func (bs *BattleSimulator) AddMonster(value int) {
	newNode := &Monster{Value: value}
	if bs.head == nil {
		bs.head = newNode
	} else {
		current := bs.head
		for current.Next != nil {
			current = current.Next
		}
		current.Next = newNode
	}
}

func (bs *BattleSimulator) SimulateBattle(playerHP int) bool {
	current := bs.head
	level := 1

	for current != nil {
		playerHP -= current.Value

		if playerHP <= 0 {
			fmt.Printf("game over! dead at level %d\n", level)
			return false
		}

		level++
		current = current.Next
	}

	fmt.Printf("game clear! hp left %d\n", playerHP)
	return true
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		input := scanner.Text()

		battle := NewBattleSimulator()
		battle.CreateMonsters(input)

		playerHP := 100
		battle.SimulateBattle(playerHP)
	}
}
