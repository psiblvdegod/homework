#include "tests.h"
#include "phoneDirectory.h"
#include <string.h>

void phoneDirectoryTest(int *errorCode) {
    Directory directory = createDirectory(10, errorCode);
    addContact(directory, "1st", "2nd", errorCode);
    addContact(directory, "3rd", "4th", errorCode);
    const bool test1 = strcmp(searchByName(directory, "1st", errorCode), "2nd") == 0;
    const bool test2 = strcmp(searchByNumber(directory, "4th", errorCode), "3rd") == 0;
    const bool test3 = searchByName(directory, "5th", errorCode) == NULL;
    const bool test = test1 && test2 && test3;
    if (*errorCode == 0 && !test) { // tests failed but there are no errors
        *errorCode = -1;
    }
}