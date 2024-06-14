#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coefficient, x_exp, y_exp;
    struct Term *next;
} Term;

typedef struct {
    Term *head;
} Polynomial;

Polynomial createPolynomial() {
    Polynomial poly;
    poly.head = NULL;
    return poly;
}

void addTerm(Polynomial *poly, int coefficient, int x_exp, int y_exp) {
    Term *newTerm = (Term *)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->x_exp = x_exp;
    newTerm->y_exp = y_exp;
    newTerm->next = NULL;

    Term **ptr = &poly->head;
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

void printPolynomial(Polynomial poly) {
    Term *current = poly.head;
    if (!current) printf("0");
    int isFirst = 1;
    while (current) {
        if (current->coefficient == 0) {
            current = current->next;
            continue;
        }
        if (!isFirst) printf("%+d", current->coefficient);
        else printf("%d", current->coefficient);

        printf("x^%d", current->x_exp);
        printf("y^%d", current->y_exp);
        current = current->next;
        isFirst = 0;
    }
    if (isFirst) printf("0");
    printf("\n");
}

Polynomial addPolynomials(Polynomial *p1, Polynomial *p2) {
    Polynomial result = createPolynomial();
    Term *current = p1->head;
    while (current) {
        addTerm(&result, current->coefficient, current->x_exp, current->y_exp);
        current = current->next;
    }
    current = p2->head;
    while (current) {
        addTerm(&result, current->coefficient, current->x_exp, current->y_exp);
        current = current->next;
    }
    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    Polynomial polys[N];
    for (int i = 0; i < N; ++i) {
        polys[i] = createPolynomial();
        int a, b, c;
        while (scanf("%d %d %d", &a, &b, &c) == 3) {
            addTerm(&polys[i], a, b, c);
            char nextChar = getchar();
            if (nextChar == '\n' || nextChar == EOF) break;
        }
    }

    for (int i = 0; i < N; ++i) {
        printPolynomial(polys[i]);
    }

    Polynomial sum = createPolynomial();
    for (int i = 0; i < N; ++i) {
        sum = addPolynomials(&sum, &polys[i]);
    }

    printf("Sum:");
    printPolynomial(sum);
    return 0;
}
