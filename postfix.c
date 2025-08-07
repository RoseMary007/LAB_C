#include <stdio.h>
#include <ctype.h> 

#define SIZE 100

char stack[SIZE];
int top = -1;
char postfix[SIZE];

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

void push(char symbol) {
    if (top < SIZE - 1) {
        stack[++top] = symbol;
    } else {
        printf("Stack overflow\n");
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        return '\0'; 
    }
}

char peek() {
    if (top >= 0) {
        return stack[top];
    } else {
        return '\0';
    }
}

int main() {
    char infix[SIZE];
    int i = 0, j = 0;
    char symbol, temp;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while ((symbol = infix[i++]) != '\0') {
        if (isalnum(symbol)) {
            postfix[j++] = symbol; 
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (peek() != '(' && top != -1) {
                postfix[j++] = pop();
            }
            pop(); 
        } else if (isOperator(symbol)) {
            while (top != -1 && precedence(peek()) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

   
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
