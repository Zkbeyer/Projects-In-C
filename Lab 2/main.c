#include "lab2.h"

int main(void){
    int size = 6;
    int *array = makeArray(size);

    for(int i = 0; i < size; i++){
        array[i] = i + i + 2;
        printf("%d\n", array[i]);
    }

    printf("6 at %d\n", indexOf(array,size,6));
    printf("10 at %d\n", indexOf(array,size,10));
    printf("30?: %d\n", indexOf(array,size,30));

    

    int *result;
    int newSize = sliceArray(array, size, 6, 10, &result);

    printf("\n%d\n\n", sliceArray(array, size, 20, 10, &result));

    printf("size:%d\n", newSize);

    for(int i = 0; i < newSize; i++){
        printf("%d\n", result[i]);
    }
    printf("\n%d\n\n", (result[newSize - 1]));

    freeArray(&array);

    if (array == NULL){
        printf("Yes\n");
    }
    
}