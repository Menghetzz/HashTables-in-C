#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    char name[20];
    int age;
} Person;

int hash(char *name) {
    int hash = 0;
    for (int i = 0; i < strlen(name); i++) {
        hash += name[i];
    }
    return hash % MAX_SIZE;
}

void insert(Person person, Person **list) {    
    int hashCode = hash(person.name);
    list[hashCode] = malloc(sizeof(Person));
    list[hashCode]->age = person.age;
    strcpy(list[hashCode]->name, person.name);
}

void printAll(Person **list) {
    for(int i = 0; i < MAX_SIZE; i++) {
        if(list[i] != NULL) {
            printf("%d -> %s - %d\n", i, list[i]->name, list[i]->age);
        } else{
            printf("%d -> --------\n", i);
        }
    }
}

int main() {
    Person p1 = {"Manuel", 22};
    Person p2 = {"Giovanni", 20};
    Person p3 = {"Federico", 29};
    Person p4 = {"Francesco", 23};
    Person p5 = {"Giacomo", 22};
    Person *listPerson[MAX_SIZE] = {NULL};

    insert(p1, listPerson);
    insert(p2, listPerson);
    insert(p3, listPerson);
    insert(p4, listPerson);
    insert(p5, listPerson);

    printAll(listPerson);
}