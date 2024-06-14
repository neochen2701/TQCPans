package main

import (
	"fmt"
	"sort"
)

type Employee struct {
	eID, eName string
	salary     int
	dID        string
}

type Department struct {
	dID, dName, mID string
}

type Project struct {
	pID, pName, location string
}

type HourLog struct {
	eID, pID string
	pHours   int
}

type ANS struct {
	pName  string
	pHours int
}

func main() {
	var eNum, dNum, pNum, hNum int
	fmt.Scan(&eNum, &dNum, &pNum, &hNum)

	employees := make([]Employee, eNum)
	departments := make([]Department, dNum)
	projects := make([]Project, pNum)
	hourLogs := make([]HourLog, hNum)

	for i := range employees {
		fmt.Scan(&employees[i].eID, &employees[i].eName, &employees[i].salary, &employees[i].dID)
	}
	for i := range departments {
		fmt.Scan(&departments[i].dID, &departments[i].dName, &departments[i].mID)
	}
	for i := range projects {
		fmt.Scan(&projects[i].pID, &projects[i].pName, &projects[i].location)
	}
	for i := range hourLogs {
		fmt.Scan(&hourLogs[i].eID, &hourLogs[i].pID, &hourLogs[i].pHours)
	}

	var sName string
	fmt.Scan(&sName)

	var ans []ANS
	var totalHours int

	for _, e := range employees {
		if e.eName == sName {
			for _, hl := range hourLogs {
				if hl.eID == e.eID {
					for _, p := range projects {
						if hl.pID == p.pID {
							ans = append(ans, ANS{pName: p.pName, pHours: hl.pHours})
							totalHours += hl.pHours
						}
					}
				}
			}
			break
		}
	}

	sort.Slice(ans, func(i, j int) bool {
		return ans[i].pName < ans[j].pName
	})

	for _, a := range ans {
		fmt.Printf("%s %d\n", a.pName, a.pHours)
	}
	fmt.Println(totalHours)
}
