#include "Person.h"
#include <stdio.h>
void print(Person _Person)
{
    printf("%-3d, %-20s, %-3d, %-3d, %-3d\n", _Person.id, _Person.name,_Person.age, _Person.height, _Person.weight);
}