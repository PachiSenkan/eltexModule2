#include <stdio.h>
#include "mymath.h"

typedef struct {
    char symbol;
    char name[127];
    double (*function)(double, double);
} Function;

int main() {
    char operator;
    double num1, num2;

    Function functions[] = {
        {'+', "Сложение", add},
        {'-', "Вычитание", subtract},
        {'*', "Умножение", multiply},
        {'/', "Деление", divide},
        {'^', "Возведение в степень", power},
        {'%', "Остаток от деления", modulo}
    };

    int functions_count = sizeof(functions) / sizeof(Function);

    while (1) {
        printf("\nВозможные операции:\n");

        for (int i = 0; i < functions_count; i++) {
            printf("%c - %s\n", functions[i].symbol, functions[i].name);
        }

        printf("q - выход\n");
        printf("Введите операцию: ");
        scanf(" %c", &operator);

        if (operator == 'q') {
            break;
        }

        printf("Введите первое число: ");
        scanf("%lf", &num1);

        printf("Введите второе число: ");
        scanf("%lf", &num2);

        int function_found = 0;

        for (int i = 0; i < functions_count; i++) {
            if (operator == functions[i].symbol) {
                printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, functions[i].function(num1, num2));
                function_found = 1;
                break;
            }
        }

        if (!function_found) {
            printf("Неверная операция\n");
        }
    }

    return 0;
}