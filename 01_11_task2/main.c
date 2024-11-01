#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSorted(int array[], int arraySize) {
    for (int i = 1; i < arraySize; ++i) {
        if (array[i - 1] > array[i]) {
            return false;
        }
    }
    return true;
}
 
void bogoSort(int array[], int arraySize) {
    while (!isSorted(array, arraySize)) {
        for (int i = 0; i < arraySize; ++i) {
            int tempForSwap = array[i];
            int randomIndex = rand() % arraySize;
            array[i] = array[randomIndex];
            array[randomIndex] = tempForSwap;
        }
    }
}

bool bogoSortTest() {
    int testArray[] = {1, 3, 4, 6, 9};
    int testArraySize = sizeof(testArray) / sizeof(int);
    bogoSort(testArray, testArraySize);
    return isSorted(testArray, testArraySize);
}

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