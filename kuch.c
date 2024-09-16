#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}
int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;  // Operand, add to postfix
        } else if (ch == '(') {
            stack[++top] = ch;  // Left parenthesis, push to stack
        } else if (ch == ')') {
            // Right parenthesis, pop operators from stack and add to postfix until left parenthesis is encountered
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top != -1) {
                top--;  // Pop the left parenthesis
            }
        } else if (isOperator(ch)) {
            // Operator, pop operators from stack and add to postfix until an operator with lower precedence is encountered
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;  // Push the current operator to stack
        }
    }
    // Pop any remaining operators from stack and add to postfix
    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';  // Add null character to indicate the end of the postfix expression
}
int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}