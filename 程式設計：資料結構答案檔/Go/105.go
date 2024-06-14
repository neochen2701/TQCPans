package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Term struct {
	Coefficient, XExp, YExp int
	Next                    *Term
}

type Polynomial struct {
	Head *Term
}

func NewPolynomial() *Polynomial {
	return &Polynomial{nil}
}

func (p *Polynomial) AddTerm(coefficient, xExp, yExp int) {
	if coefficient == 0 {
		return
	}
	newTerm := &Term{Coefficient: coefficient, XExp: xExp, YExp: yExp}
	if p.Head == nil || p.Head.XExp < xExp || (p.Head.XExp == xExp && p.Head.YExp < yExp) {
		newTerm.Next = p.Head
		p.Head = newTerm
		return
	}
	var prev *Term
	current := p.Head
	for current != nil && (current.XExp > xExp || (current.XExp == xExp && current.YExp > yExp)) {
		prev = current
		current = current.Next
	}
	if current != nil && current.XExp == xExp && current.YExp == yExp {
		current.Coefficient += coefficient
		if current.Coefficient == 0 {
			if prev != nil {
				prev.Next = current.Next
			} else {
				p.Head = current.Next
			}
		}
	} else {
		newTerm.Next = current
		if prev != nil {
			prev.Next = newTerm
		} else {
			p.Head = newTerm
		}
	}
}

func (p *Polynomial) String() string {
	var result strings.Builder
	current := p.Head
	for current != nil {
		sign := ""
		if current.Coefficient > 0 && current != p.Head {
			sign = "+"
		}
		result.WriteString(fmt.Sprintf("%s%dx^%dy^%d", sign, current.Coefficient, current.XExp, current.YExp))
		current = current.Next
	}
	if result.Len() == 0 {
		return "0"
	}
	return result.String()
}

func addPolynomials(p1, p2 *Polynomial) *Polynomial {
	result := NewPolynomial()
	current := p1.Head
	for current != nil {
		result.AddTerm(current.Coefficient, current.XExp, current.YExp)
		current = current.Next
	}
	current = p2.Head
	for current != nil {
		result.AddTerm(current.Coefficient, current.XExp, current.YExp)
		current = current.Next
	}
	return result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	polynomials := make([]*Polynomial, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		input := scanner.Text()
		terms := strings.Fields(input)
		poly := NewPolynomial()
		for j := 0; j < len(terms); j += 3 {
			coefficient, _ := strconv.Atoi(terms[j])
			xExp, _ := strconv.Atoi(terms[j+1])
			yExp, _ := strconv.Atoi(terms[j+2])
			poly.AddTerm(coefficient, xExp, yExp)
		}
		polynomials[i] = poly
	}

	for _, poly := range polynomials {
		fmt.Println(poly)
	}

	sumPoly := polynomials[0]
	for i := 1; i < len(polynomials); i++ {
		sumPoly = addPolynomials(sumPoly, polynomials[i])
	}

	fmt.Println("Sum:" + sumPoly.String())
}
