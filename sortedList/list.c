#include "list.h"

typedef struct ListElement {
    Value value;
    struct ListElement * next;
    struct ListElement * previous;
} ListElement;

struct List {
    ListElement * head;
};

List * createList(bool * errorCode) {
    ListElement * guardian = calloc(1, sizeof(ListElement));
    List * list = calloc(1, sizeof(List));
    if (guardian == NULL || list == NULL) {
        *errorCode = true;
        return NULL;
    }
    list->head = guardian;
    return list;
}

void addElement(List * list, Position * mainPosition, Value value, bool * errorCode) {
    ListElement * position = *mainPosition;
    ListElement * newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL) {
        *errorCode = true;
        return;
    }
    newElement->value = value;
    if (position != NULL) {
        if (position->next != NULL) {
            position->next->previous = newElement;
        }
        newElement->previous = position;
        newElement->next = position->next;
        position->next = newElement;
    }
    else {
        newElement->previous = list->head;
        newElement->previous->next = newElement;
        newElement->next = NULL; //СКОРЕЕ ВСЕГО НЕ НУЖНО
    }
    *mainPosition = newElement;
}

Value deleteElement(List * list, Position * mainPosition, bool * errorCode) {
    ListElement * position = *mainPosition;
    if (position == NULL) {
        *errorCode = true;
        return 1000;
    }
    position->previous->next = position->next;
    if (position->next != NULL) {
        position->next->previous = position->previous;
    }
    *mainPosition = position->previous;
    Value deletedValue = position->value;
    free(position);
    return deletedValue;
}

void deleteList(List ** list) {
    ListElement * cleaner = (*list)->head;
    while (cleaner->next != NULL) {
        ListElement * temp = cleaner;
        cleaner = cleaner->next;
        free(temp);
    }
    *list == NULL;
}


//дописать
Value getValue(List * list, Position * mainPosition, bool * errorCode) {
    ListElement * position = *mainPosition;
    if (position == NULL) { //помещает на стражнтка если temp только создан
        position = list->head;
        *mainPosition = position; //мейби не нужно
    }
    if (position->next != NULL) {
        Value value = position->next->value;
        *mainPosition = position->next;
    }
    else {
        *errorCode = true;
        return 0;
    }
}