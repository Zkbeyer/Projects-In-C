#include <stdlib.h>
#include <stdio.h>
#include "sorting.h"
#include "searching.h"

int compareInts(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

void print_int_array(int *array, int size) {
    printf("int[%d] = \n", size);
    for(int i = 0; i < size; ++i) {
        printf("%d%s", array[i],
            (i == (size - 1) ? "\n" : ", "));
    }
}

int main() {
    int size = 10;
    int *array = malloc(sizeof(int) * size);
    int maxRandom = 10000;

    srand(255);

    if(!array) {
        fputs("Failed to allocated primary array!", stderr);
        return EXIT_FAILURE;
    }

    for(int i = 0; i < size; ++i) {
        array[i] = rand() % (maxRandom + 1);
    }

    //print_int_array(array, size);

    bubbleSort(array, size, sizeof(int), compareInts);

    //print_int_array(array, size);

    int test = array[(int)(size * 0.79)];

    int result = linearSearch(array, size, sizeof(int), &test, compareInts);

    printf("found %d at index [%d]\n", test, result);

    

    

    free(array);
}
