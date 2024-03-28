#include <stdio.h>
#include "mymath.h"

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0){
        printf("\nДеление на ноль\n");
        return -1;
    }
    else{
        return a / b;
    }
}
