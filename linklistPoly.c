#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* link;
};

struct node *pptr = NULL, *qptr = NULL, *rptr = NULL;

struct node* create_node(int coeff, int exp) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->coeff = coeff;
    temp->exp = exp;
    temp->link = NULL;
    return temp;
}

void insert_term(struct node** head, int coeff, int exp) {
    struct node* temp = create_node(coeff, exp);
    if (*head == NULL) {
        *head = temp;
    } else {
        struct node* ptr = *head;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}

void display_poly(struct node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->link;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}


struct node* add_polynomials(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                insert_term(&result, sumCoeff, poly1->exp);
            }
            poly1 = poly1->link;
            poly2 = poly2->link;
        } else if (poly1->exp > poly2->exp) {
            insert_term(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->link;
        } else {
            insert_term(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->link;
        }
    }


    while (poly1 != NULL) {
        insert_term(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->link;
    }


    while (poly2 != NULL) {
        insert_term(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->link;
    }

    return result;
}

int main() {
    int n, m, coeff, exp, i;
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* sum = NULL;

    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &n);

    printf("Enter the terms in descending order of exponents (coeff exponent):\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insert_term(&poly1, coeff, exp);
    }

    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &m);

    printf("Enter the terms in descending order of exponents (coeff exponent):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &coeff, &exp);
        insert_term(&poly2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    display_poly(poly1);

    printf("Polynomial 2: ");
    display_poly(poly2);

    sum = add_polynomials(poly1, poly2);

    printf("Sum of polynomials: ");
    display_poly(sum);

    return 0;
}

