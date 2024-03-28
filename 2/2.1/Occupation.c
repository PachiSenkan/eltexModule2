#include "Occupation.h"

#include <stdio.h>
#include <string.h>


void set_occupation(Occupation* o, char _name[], char _position[]){
    strncpy(o->name, _name, 127);
    strncpy(o->position, _position, 127);
}