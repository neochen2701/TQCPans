class Term:
    def __init__(self, coefficient, x_exp, y_exp):
        self.coefficient = coefficient
        self.x_exp = x_exp
        self.y_exp = y_exp
        self.next = None

class Polynomial:
    def __init__(self):
        self.head = None

    def add_term(self, coefficient, x_exp, y_exp):
        if coefficient == 0:
            return
        new_term = Term(coefficient, x_exp, y_exp)
        if not self.head or (self.head.x_exp < x_exp or (self.head.x_exp == x_exp and self.head.y_exp < y_exp)):
            new_term.next = self.head
            self.head = new_term
            return
        prev = None
        current = self.head
        while current and (current.x_exp > x_exp or (current.x_exp == x_exp and current.y_exp > y_exp)):
            prev = current
            current = current.next
        if current and current.x_exp == x_exp and current.y_exp == y_exp:
            current.coefficient += coefficient
            if current.coefficient == 0:
                if prev:
                    prev.next = current.next
                else:
                    self.head = current.next
        else:
            new_term.next = current
            if prev:
                prev.next = new_term
            else:
                self.head = new_term

    def __str__(self):
        terms = []
        current = self.head
        while current:
            coeff_str = f"{current.coefficient}" if current.coefficient < 0 else f"+{current.coefficient}"
            terms.append(f"{coeff_str}x^{current.x_exp}y^{current.y_exp}")
            current = current.next
        return "".join(terms).lstrip('+')

    def add_polynomial(self, other):
        result = Polynomial()
        p = self.head
        while p:
            result.add_term(p.coefficient, p.x_exp, p.y_exp)
            p = p.next
        p = other.head
        while p:
            result.add_term(p.coefficient, p.x_exp, p.y_exp)
            p = p.next
        return result

input_polynomial_data = []
n = int(input())
for _ in range(n):
    input_polynomial_data.append(input())

polynomials = []
for poly_input in input_polynomial_data:
    poly = Polynomial()
    terms = poly_input.split()
    for i in range(0, len(terms), 3):
        coefficient, x_exp, y_exp = int(terms[i]), int(terms[i + 1]), int(terms[i + 2])
        poly.add_term(coefficient, x_exp, y_exp)
    polynomials.append(poly)

for i, poly_data in enumerate(input_polynomial_data):
    print(polynomials[i])

sum_poly = polynomials[0]
for poly in polynomials[1:]:
    sum_poly = sum_poly.add_polynomial(poly)

print(f"Sum:{sum_poly}")
