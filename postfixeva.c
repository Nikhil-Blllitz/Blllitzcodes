#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100
int isop(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}
int Operation(int c1, int c2, char op) {
    switch(op) {
        case '+':return c1 + c2;
        case '-':return c1 - c2;
        case '*':return c1 * c2;
        case '/':return c1 / c2;
        case '%':return c1 % c2;
        case '^':return (int)pow(c1, c2);
        default:return 0;
    }
}
int evaluation(char postfix[]) {
    int stack[MAX],top =-1,i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            int operand = 0;
            // Keep reading digits until a non-digit character is encountered
            while (isdigit(postfix[i])) {
                operand = operand * 10 + (postfix[i] - '0');
                i++;
            }
            i--;
            stack[++top] = operand;
        } else if (isop(ch)) {
            int b = stack[top--];
            int a = stack[top--];
            int result = Operation(a, b, ch);
            stack[++top] = result;
        }
    }

    return stack[top];
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    scanf("%[^\n]", postfix);
    int result = evaluation(postfix);
    printf("Result: %d\n", result);
    return 0;
}
