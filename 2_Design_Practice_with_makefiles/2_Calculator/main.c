#include<stdio.h>

#include "add.h"
#include "subtract.h"
#include "multiply.h"
#include "divide.h"

int main() {
    int a, b, c;
    char op;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
            _add(&a, &b, &c);
            printf("Result: %d\n", c);
            break;
        case '-':
            _subtract(&a, &b, &c);
            printf("Result: %d\n", c);
            break;
        case '*':
            _multiply(&a, &b, &c);
            printf("Result: %d\n", c);
            break;
        case '/':
            _divide(&a, &b, &c);
            printf("Result: %d\n", c);
            break;
        default:
            printf("Invalid operator!\n");
    }

    return 0;
}

