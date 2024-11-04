#pragma once 

#include <stdbool.h>
#include <stdlib.h>

typedef int Value;

typedef struct ListElement * Position;

typedef struct List List;

List * createList(bool * errorCode);

void addElement(List * list, Position * position, Value value, bool * errorCode);

Value deleteElement(List * list, Position * position, bool * errorCode);

void deleteList(List ** list);

Value getValue(List * list, Position * mainPosition, bool * errorCode);