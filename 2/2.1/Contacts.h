#ifndef CONTACTS_H_
#define CONTACTS_H_

typedef struct Phone{
    char number[14];
} Phone;

typedef struct Email{
    char email[127];
} Email;

typedef struct Social{
    char name[127];
} Social;

typedef struct Messenger{
    char name[127];
} Messenger;

#define MAX_SIZES 5
typedef struct Contacts{
    Phone phone_numbers[MAX_SIZES];
    int p_size;
    Email emails[MAX_SIZES];
    int e_size;
    Social socials[MAX_SIZES];
    int s_size;
    Messenger messengers[MAX_SIZES];
    int m_size;
} Contacts;

Phone initPhone(char number[]);
Email initEmail(char email[]);
Social initSocial(char social[]);
Messenger initMessenger(char messenger[]);
Contacts initContacts();
void addPhone(Contacts* cont, char p[]);
void addEmail(Contacts* cont, char e[]);
void addSocial(Contacts* cont, char s[]);
void addMessenger(Contacts* cont, char m[]);
void clearContacts(Contacts* cont);
void copyContacts(Contacts* c1, Contacts* c2);
#endif 