#include "list.h"

int main(void) {
    bool errorCode = false;
    List * list = createList(&errorCode);
    Position mainPosition = NULL;
    addElement(list, &mainPosition, 5, &errorCode);
    
    deleteList(&list);
}