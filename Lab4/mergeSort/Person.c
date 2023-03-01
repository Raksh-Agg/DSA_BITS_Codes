#include "Person.h"
#include <stdio.h>
void print(Person _Person)
{
    printf("%-3d, %-20s, %-3d, %-3d, %-3d\n", _Person.id, _Person.name,_Person.age, _Person.height, _Person.weight);
}
void makeEqual(PerPtr a, PerPtr b)
{

    a->age = b->age;
    a->height = b->height;
    a->weight = b->weight;
    a->name = b->name;
    a->id = b->id;
}