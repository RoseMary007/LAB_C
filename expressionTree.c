#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100


char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}
char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}
char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}
int isOperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}
int isRightAssociative(char op) {
    return (op == '^');
}


void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    for (i = 0; i < strlen(infix); i++) {
        char ch = infix[i];
        if (ch == ' ') continue;
        if (isOperand(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(' && top != -1)
                postfix[k++] = pop();
            pop(); 
        }
        else if (isOperator(ch)) {
            while (isOperator(peek()) && ((precedence(ch) < precedence(peek())) 
                || (precedence(ch) == precedence(peek()) && !isRightAssociative(ch)))) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1)
        postfix[k++] = pop();
    postfix[k] = '\0';
}



typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;


Node* treeStack[MAX];
int treeTop = -1;

void pushNode(Node* node) {
    if (treeTop < MAX - 1)
        treeStack[++treeTop] = node;
}

Node* popNode() {
    if (treeTop >= 0)
        return treeStack[treeTop--];
    return NULL;
}


Node* buildExpressionTree(char postfix[]) {
    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = ch;
        newNode->left = newNode->right = NULL;

        if (isOperand(ch)) {
            pushNode(newNode);
        } else {
            newNode->right = popNode();
            newNode->left = popNode();
            pushNode(newNode);
        }
    }
    return popNode(); 
}


void preorder(Node* root) {
    if (root) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    Node* root = buildExpressionTree(postfix);

    printf("Preorder Traversal (Prefix)  : ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal(Postfix) : ");
    postorder(root);
    printf("\n");

    return 0;
}

