import java.util.Scanner;

class Term {
    int coefficient, xExp, yExp;
    Term next;

    public Term(int coefficient, int xExp, int yExp) {
        this.coefficient = coefficient;
        this.xExp = xExp;
        this.yExp = yExp;
        this.next = null;
    }
}

class Polynomial {
    Term head;

    public void addTerm(int coefficient, int xExp, int yExp) {
        if (coefficient == 0) return;
        Term newTerm = new Term(coefficient, xExp, yExp);
        if (head == null || head.xExp < xExp || (head.xExp == xExp && head.yExp < yExp)) {
            newTerm.next = head;
            head = newTerm;
            return;
        }
        Term prev = null;
        Term current = head;
        while (current != null && (current.xExp > xExp || (current.xExp == xExp && current.yExp > yExp))) {
            prev = current;
            current = current.next;
        }
        if (current != null && current.xExp == xExp && current.yExp == yExp) {
            current.coefficient += coefficient;
            if (current.coefficient == 0) {
                if (prev != null) {
                    prev.next = current.next;
                } else {
                    head = current.next;
                }
            }
        } else {
            newTerm.next = current;
            if (prev != null) {
                prev.next = newTerm;
            } else {
                head = newTerm;
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Term current = head;
        String sign;
        while (current != null) {
            if (current == head) {
                sign = "";
            } else {
                sign = current.coefficient > 0 ? "+" : "";
            }
            sb.append(sign).append(current.coefficient).append("x^").append(current.xExp).append("y^").append(current.yExp);
            current = current.next;
        }
        return sb.toString();
    }

    public Polynomial addPolynomial(Polynomial other) {
        Polynomial result = new Polynomial();
        Term p = this.head;
        while (p != null) {
            result.addTerm(p.coefficient, p.xExp, p.yExp);
            p = p.next;
        }
        p = other.head;
        while (p != null) {
            result.addTerm(p.coefficient, p.xExp, p.yExp);
            p = p.next;
        }
        return result;
    }
}

public class JPA105 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());

        Polynomial[] polynomials = new Polynomial[n];

        for (int i = 0; i < n; i++) {
            String input = scanner.nextLine();
            String[] terms = input.split(" ");
            Polynomial poly = new Polynomial();
            for (int j = 0; j < terms.length; j += 3) {
                int coefficient = Integer.parseInt(terms[j]);
                int xExp = Integer.parseInt(terms[j + 1]);
                int yExp = Integer.parseInt(terms[j + 2]);
                poly.addTerm(coefficient, xExp, yExp);
            }
            polynomials[i] = poly;
        }

        for (Polynomial poly : polynomials) {
            System.out.println(poly);
        }

        Polynomial sumPoly = polynomials[0];
        for (int i = 1; i < polynomials.length; i++) {
            sumPoly = sumPoly.addPolynomial(polynomials[i]);
        }

        System.out.println("Sum:" + sumPoly);
    }
}
