#include <stdio.h>
#include <string.h>

#include "Contacts.h"
#include "Occupation.h"
#include "Human.h"
#include "Handbook.h"

/*
Написать программу для работы со списком контактов (телефонная книга).
Хранить сведения о Ф.И.О. человека, его месте работы и должности,
номерах телефона, адресах электронной почты, ссылки на страницы в
соцсетях и профили в мессенджерах.
Обязательными для заполнения являются фамилия и имя, остальные
поля заполняются при необходимости.
Для хранения данных использовать массивы.
Программа должна предоставлять возможность добавления,
редактирования и удаления контакта.
*/


int main(int argc, char* argv[]){
    Handbook h = init_handbook();
    while(1==1){
        printf("\n1. Вывести список контактов\n"
                "2. Добавить новый контакт\n"
                "3. Редактировать существующий контакт\n"
                "4. Удалить контакт\n"
                "5. Выход\n"
                "Введите команду: \n");
        int check;
        scanf("%d", &check);
        switch(check){
            case 1:
                print_humans(&h);
                break;
            case 2:
                create_record(&h);
                break;
            case 3:
                edit_record(&h);
                break;
            case 4:
                delete_record(&h);
                break;
            case 5:
                return 0;
            default:
                break;
        }
    }
    return 0;
}
