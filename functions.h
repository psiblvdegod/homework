#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char * name;
    char * number;
    struct Contact * previous;
} Contact;

void addContact(Contact * contacts[], int * amountOfContacts, Contact ** mainPointer, char * addName, char * addNumber);
void newContact(Contact * contacts[], int * amountOfContacts, Contact ** mainPointer);
void readContactsFromFile(Contact * contacts[], int * amountOfContacts, Contact ** mainPointer, FILE * file);
void printAllContacts(Contact * contacts[], int amountOfContacts);
Contact * searchByNumber(Contact * contacts[], int amountOfContacts);
Contact * searchByName(Contact * contacts[], int amountOfContacts);
void saveContacts(Contact * contacts[], int amountOfContacts);