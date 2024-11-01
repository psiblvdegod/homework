#include "bogoSort.h"

int main(void) {
    if (!bogoSortTest()) {
        printf("Error. Test failed.\n");
        return -1;
    }
    int array[] = {4, 2, 3, 1, 7, 4};
    int arraySize = (sizeof(array) / sizeof(int));
    bogoSort(array, arraySize);
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
    return 0;
}
