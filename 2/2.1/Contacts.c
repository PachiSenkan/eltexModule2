#include "Contacts.h"
#include <stdio.h>
#include <string.h>

Phone initPhone(char number[]){
    Phone phone;
    strncpy(phone.number, number, 14);    
    return phone;
}

Email initEmail(char email[]){
    Email _email;
    strncpy(_email.email, email, 128);    
    return _email;
}

Social initSocial(char social[]){
    Social _social;
    strncpy(_social.name, social, 128);    
    return _social;
}

Messenger initMessenger(char messenger[]){
    Messenger _messenger;
    strncpy(_messenger.name, messenger, 128);    
    return _messenger;
}

Contacts initContacts(){
    Contacts contacts;
    contacts.e_size = 0;
    contacts.m_size = 0;
    contacts.p_size = 0;
    contacts.s_size = 0;
    return contacts;
}

void addPhone(Contacts* cont, char p[]){
    cont->phone_numbers[cont->p_size++] = initPhone(p);
}
void addEmail(Contacts* cont, char e[]){
    cont->emails[cont->e_size++] = initEmail(e);
}
void addSocial(Contacts* cont, char s[]){
    cont->socials[cont->s_size++] = initSocial(s);
}
void addMessenger(Contacts* cont, char m[]){
    cont->messengers[cont->m_size++] = initMessenger(m);
}
void clearContacts(Contacts* cont){
    int i = 0;
    for (i = 0; i < cont->p_size; i++){
        strncpy(cont->phone_numbers[i].number, "\0", 14);
    }
    cont->p_size = 0;
        for (i = 0; i < cont->e_size; i++){
        strncpy(cont->emails[i].email, "\0", 127);
    }
    cont->e_size = 0;
        for (i = 0; i < cont->s_size; i++){
        strncpy(cont->socials[i].name, "\0", 127);
    }
    cont->s_size = 0;
        for (i = 0; i < cont->m_size; i++){
        strncpy(cont->messengers[i].name, "\0", 127);
    }
    cont->m_size = 0;
}
void copyContacts(Contacts* c1, Contacts* c2){
    int i = 0;
    for (i = 0; i < c2->p_size; i++){
        addPhone(c1, c2->phone_numbers[i].number);
    }
    for (i = 0; i < c2->e_size; i++){
        addEmail(c1, c2->emails[i].email);
    }
    for (i = 0; i < c2->s_size; i++){
        addSocial(c1, c2->socials[i].name);
    }
    for (i = 0; i < c2->m_size; i++){
        addMessenger(c1, c2->messengers[i].name);
    }
}