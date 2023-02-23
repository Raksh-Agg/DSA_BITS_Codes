#ifndef PERSON_H
#define PERSON_H
struct person
{
	int id;
	char *name;
	int age;
	int height;
	int weight;
};
typedef struct person Person;
typedef Person* PerPtr;
PerPtr makePerson (int _id, char *_name, int _age, int _height, int _weight);
void print(Person _Person);
#endif
