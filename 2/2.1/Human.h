#ifndef HUMAN_H_
#define HUMAN_H_

#include "Occupation.h"
#include "Contacts.h"

typedef struct Human{
    char name[127];
    char surname[127];
    char patronymic[127];
    Occupation occupation;
    Contacts contacts;
} Human;

void set_contacts(Human* h);
void set_name(Human* h, char n[]);
void set_surname(Human* h, char s[]);
void set_patronymic(Human* h, char p[]);
//void set_occupation(Human* h, char _name[], char _position[]);
#endif 