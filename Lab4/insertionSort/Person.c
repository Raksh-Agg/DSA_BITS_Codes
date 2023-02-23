#include "Person.h"
#include <stdio.h>
void print(Person _Person)
{
    printf("%d, %s, %d, %d, %d\n", _Person.id, _Person.name,_Person.age, _Person.height, _Person.weight);
}