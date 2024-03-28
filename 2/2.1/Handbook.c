#include "Handbook.h"
#include "Occupation.h"
#include "Utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 16

Handbook init_handbook(){
    Handbook handbook;
    handbook.size = 0;
    return handbook;
}

void print_humans(Handbook* handbook){
    for (int i = 0; i < handbook->size; i++){
        Human person = handbook->records[i];
        printf("\n%d. %s %s %s\n", i+1, person.name, person.surname, person.patronymic);
        if (isAllAlpha(person.occupation.name)){
            printf("    %s: %s\n", person.occupation.name, person.occupation.position);
        }
        printf("    Телефоны:       Эл.почты:      Соц.сети:      Мессенджеры:\n");

        for (int c = 0; c < MAX_SIZES; c++){
            if (c <= person.contacts.p_size){
                printf("%+13s", person.contacts.phone_numbers[c].number);
            }
            else{printf("             ");}
            if (c <= person.contacts.e_size){
                printf("%+15s", person.contacts.emails[c].email);
            }
            else{printf("               ");}
            if (c <= person.contacts.s_size){
                printf("%+15s", person.contacts.socials[c].name);
            }
            else{printf("               ");}
            if (c <= person.contacts.m_size){
                printf("%+16s\n", person.contacts.messengers[c].name);
            }
            else{printf("\n");}
        }
    }
}

void create_record(Handbook* handbook){
    char buffer[128];
    Human human;
    getFromUser(buffer, "имя", 1);
    set_name(&human, buffer);
    getFromUser(buffer, "фамилию", 1);
    set_surname(&human, buffer);
    getFromUser(buffer, "отчество", 1);
    set_patronymic(&human, buffer);
    printf("Ввести данные о месте работы? \n1. Да\n2. Нет\nВвести: ");
    scanf("%s", buffer);
    while (isAllDigit(buffer) != 1){
        printf("Ввести данные о месте работы? \n1. Да\n2. Нет\nВвести: ");
        scanf("%s", buffer);
    }
    if (atoi(buffer) == 1){
        char oc[128];
        char pos[128];
        getFromUser(oc, "место работы", 1);
        getFromUser(pos, "должность", 1);
        set_occupation(&human.occupation, oc, pos);
    };
    printf("Ввести данные о контактах? \n1. Да\n2. Нет\nВвести: ");
    scanf("%s", buffer);
    while (isAllDigit(buffer) != 1){
        printf("Ввести данные о контактах? \n1. Да\n2. Нет\nВвести: ");
        scanf("%s", buffer);
    }
    
    if (atoi(buffer) == 1){
        set_contacts(&human);
    }
    

    handbook->records[handbook->size++] = human;
};               

void delete_record(Handbook* handbook){
    char buffer[128];
    printf("Введите имя контакта: ");
    scanf("%s", buffer);
    while (isAllAlpha(buffer) != 1){
        printf("Введите имя контакта: ");
        scanf("%s", buffer);
    }
    int del = 0;
    for (int i = 0; i < handbook->size; i++){
        if (strcmp(handbook->records[i].name, buffer) == 0){
            del = 1;
            for (int j = i; j < handbook->size - 1; j++){
                set_name(&handbook->records[j], handbook->records[j+1].name);
                set_surname(&handbook->records[j], handbook->records[j+1].surname);
                set_patronymic(&handbook->records[j], handbook->records[j+1].patronymic);
                set_occupation(&handbook->records[j].occupation, handbook->records[j+1].occupation.name, handbook->records[j+1].occupation.position);
                clearContacts(&handbook->records[j].contacts);
                copyContacts(&handbook->records[j].contacts, &handbook->records[j+1].contacts);
            }
            set_name(&handbook->records[handbook->size], "\0");
            set_surname(&handbook->records[handbook->size], "\0");
            set_patronymic(&handbook->records[handbook->size], "\0");
            set_occupation(&handbook->records[handbook->size].occupation, "\0", "\0");
            clearContacts(&handbook->records[handbook->size].contacts);
            handbook->size -= 1;
            break;
        }
    }
    if (del == 0){
        printf("Контакта с таким именем не найдено\n");
    }
    else{
        printf("Контакт удален\n");
    }
}

void edit_record(Handbook* handbook){
    char buffer[128];
    printf("Введите имя контакта: ");
    scanf("%s", buffer);
    while (isAllAlpha(buffer) != 1){
        printf("Введите имя контакта: ");
        scanf("%s", buffer);
    }
    for (int i = 0; i < handbook->size; i++){
        if (strcmp(handbook->records[i].name, buffer) == 0){
            while(1==1){
                printf("\n1. Изменить ФИО\n"
                        "2. Изменить место работы\n"
                        "3. Изменить контакты\n"
                        "4. Выход\n"
                        "Введите команду: \n");
                int check;
                scanf("%d", &check);
                switch(check){
                    case 1:
                        char buffer[128];
                        getFromUser(buffer, "имя", 1);
                        set_name(&handbook->records[i], buffer);
                        getFromUser(buffer, "фамилию", 1);
                        set_surname(&handbook->records[i], buffer);
                        getFromUser(buffer, "отчество", 1);
                        set_patronymic(&handbook->records[i], buffer);
                        break;
                    case 2:
                        printf("1. Ввести место работы заново\n2. Очистить место работы\nВвести: ");
                        scanf("%s", buffer);
                        while (isAllDigit(buffer) != 1){
                            printf("1. Ввести место работы заново\n2. Очистить место работы\nВвести: ");
                            scanf("%s", buffer);
                        }
                        if (atoi(buffer) == 1){
                            char oc[128];
                            char pos[128];
                            getFromUser(oc, "место работы", 1);
                            getFromUser(pos, "должность", 1);
                            set_occupation(&handbook->records[i].occupation, oc, pos);
                        }
                        else{
                            set_occupation(&handbook->records[i].occupation, "\0", "\0");
                        }
                        break;
                    case 3:
                    printf("1. Ввести контакты заново\n2. Очистить контакты\nВвести: ");
                    scanf("%s", buffer);
                    while (isAllDigit(buffer) != 1){
                        printf("1. Ввести контакты заново\n2. Очистить контакты\nВвести: ");
                        scanf("%s", buffer);
                    }

                    if (atoi(buffer) == 1){
                        set_contacts(&handbook->records[i]);
                    }
                    else{
                        clearContacts(&handbook->records[i].contacts);
                    }
                        break;
                    case 4:
                        return;
                }
            }
        }
    }
}
