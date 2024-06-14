#include <iostream>
using namespace std;

struct Term {
    int coefficient, x_exp, y_exp;
    Term *next;
};

class Polynomial {
public:
    Term *head;

    Polynomial() : head(nullptr) {}

    void addTerm(int coefficient, int x_exp, int y_exp) {
        Term *newTerm = new Term{coefficient, x_exp, y_exp, nullptr};
        
        Term **ptr = &head;
        while (*ptr && ((*ptr)->x_exp > x_exp || ((*ptr)->x_exp == x_exp && (*ptr)->y_exp > y_exp))) {
            ptr = &((*ptr)->next);
        }

        if (*ptr && (*ptr)->x_exp == x_exp && (*ptr)->y_exp == y_exp) {
            (*ptr)->coefficient += coefficient;
        } else {
            newTerm->next = *ptr;
            *ptr = newTerm;
        }
    }

    void printPolynomial() {
        Term *current = head;
        if (!current) cout << "0";
        bool isFirst = true;
        while (current) {
            if (current->coefficient == 0) {
                current = current->next;
                continue;
            }
            if (!isFirst) cout << showpos << current->coefficient << noshowpos;
            else cout << current->coefficient;

            cout << "x^" << current->x_exp;
            cout << "y^" << current->y_exp;
            current = current->next;
            isFirst = false;
        }
        if (isFirst) cout << "0";
        cout << endl;
    }
};

Polynomial addPolynomials(Polynomial *p1, Polynomial *p2) {
    Polynomial result;
    Term *current = p1->head;
    while (current) {
        result.addTerm(current->coefficient, current->x_exp, current->y_exp);
        current = current->next;
    }
    current = p2->head;
    while (current) {
        result.addTerm(current->coefficient, current->x_exp, current->y_exp);
        current = current->next;
    }
    return result;
}

int main() {
    int N;
    cin >> N;

    Polynomial *polys = new Polynomial[N];
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        while (cin >> a >> b >> c) {
            polys[i].addTerm(a, b, c);
            if (cin.peek() == '\n' || cin.peek() == EOF) break;
        }
    }

    for (int i = 0; i < N; ++i) {
        polys[i].printPolynomial();
    }

    Polynomial sum;
    for (int i = 0; i < N; ++i) {
        sum = addPolynomials(&sum, &polys[i]);
    }

    cout << "Sum:";
    sum.printPolynomial();

    delete[] polys;
    return 0;
}
