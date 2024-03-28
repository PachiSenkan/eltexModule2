#include "Utils.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isAllDigit(char str[]){
    for (int i = 0; str[i] != '\0'; i++){
        if (isdigit(str[i]) == 0){
            return 0;
        } 
    }
    return 1;
}

int isAllAlpha(char str[]){
    for (int i = 0; str[i] != '\0'; i++){
        if (isalpha(str[i]) == 0){
            return 0;
        } 
    }
    return 1;
}

void getFromUser(char buf[], char prompt[], int type){
    printf("Введите %s: ", prompt);
    char buffer[128];
    scanf("%s", buffer);
    switch(type){
        case 1:
            while (!isAllAlpha(buffer)){
                printf("Введите %s: ", prompt);
                scanf("%s", buffer);
            }
            break;
        case 2:
            while (!isAllDigit(buffer)){
                printf("Введите %s: ", prompt);
                scanf("%s", buffer);
            }
            break;
        case 3:
            break;
        default:
            break;
    }
    strncpy(buf, buffer, 128);
}