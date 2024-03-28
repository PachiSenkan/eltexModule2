#ifndef OCCUPATION_H_
#define OCCUPATION_H_

typedef struct Occupation{
    char name[127];
    char position[127];
} Occupation;

void set_occupation(Occupation* o, char _name[], char _position[]);

#endif 