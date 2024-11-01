#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool validation(int array[], int arraySize) {
    for (int i = 1; i < arraySize; ++i) {
        if (array[i - 1] > array[i]) {
            return false;
        }
    }
    return true;
}

void swap(int *left, int * right) {
    *left = *left + *right;
    *right = *left - *right;
    *left = *left - *right;
}

int * bogoSort(int array[], int arraySize) {
    while (!validation(array, arraySize)) {
        for (int i = 0; i < arraySize; ++i) {
        swap(&(array[i]), &(array[rand() % arraySize]));
        }
    }
    return array;
}

int main(void) {
    int array[] = {3, 2};
    int arraySize = (sizeof(array) / sizeof(int));
    bogoSort(array, arraySize);

    return 0;
}
