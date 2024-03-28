#ifndef HANDBOOK_H_
#define HANDBOOK_H_

#include "Human.h"

typedef struct Handbook{
    int size;
    Human records[255];
} Handbook;

Handbook init_handbook();
void print_humans(Handbook* handbook);
void create_record(Handbook* handbook);
void delete_record(Handbook* handbook);
void edit_record(Handbook* handbook);

#endif 