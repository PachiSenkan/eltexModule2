#include "Human.h"
#include "Utils.h"
#include <stdio.h>
#include <string.h>

void set_name(Human* h, char n[]){
    strncpy(h->name, n, 127);
}
void set_surname(Human* h, char s[]){
    strncpy(h->surname, s, 127);
}
void set_patronymic(Human* h, char p[]){
    strncpy(h->patronymic, p, 127);
}

void set_contacts(Human* h){
    h->contacts = initContacts();
    char buffer[128];
    for (int j = 0; j < MAX_SIZES; j++){
        getFromUser(buffer, "телефон (0 для перехода к следующему шагу)", 2);
        if (strcmp(buffer, "0") == 0){
            break;
        }
        addPhone(&h->contacts, buffer);
    }
    for (int j = 0; j < MAX_SIZES; j++){
        getFromUser(buffer, "электронную почту (0 для перехода к следующему шагу)", 3);
        if (strcmp(buffer, "0") == 0){
            break;
        }
        addEmail(&h->contacts, buffer);
    }
    for (int j = 0; j < MAX_SIZES; j++){
        getFromUser(buffer, "ссылку на социальную сеть (0 для перехода к следующему шагу)", 3);
        if (strcmp(buffer, "0") == 0){
            break;
        }
        addSocial(&h->contacts, buffer);
    }
    for (int j = 0; j < MAX_SIZES; j++){
        getFromUser(buffer, "ссылку на мессенджер (0 для перехода к следующему шагу)", 3);
        if (strcmp(buffer, "0") == 0){
            break;
        }
        addMessenger(&h->contacts, buffer);
    }
}