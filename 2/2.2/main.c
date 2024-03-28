#include <stdio.h>
#include "mymath.h"


int main() {
    char operator;
    double num1, num2;

    while (1) {
        printf("\nВведите операцию(+, -, *, /) q - выход: ");
        scanf(" %c", &operator);

        if (operator == 'q') {
            break;
        }

        printf("Введите первое число: ");
        scanf("%lf", &num1);

        printf("Введите второе число: ");
        scanf("%lf", &num2);

        switch (operator) {
            case '+':
                printf("%.2f + %.2f = %.2f",num1, num2, add(num1, num2));
                break;
            case '-':
                printf("%.2f - %.2f = %.2f",num1, num2, subtract(num1, num2));
                break;
            case '*':
                printf("%.2f * %.2f = %.2f",num1, num2, multiply(num1, num2));
                break;
            case '/':
                printf("%.2f / %.2f = %.2f",num1, num2, divide(num1, num2));
                break;
            default:
                printf("Неверная операция\n");
        }
    }
}