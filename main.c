#include "lab1.h"

int main() {
    int size = 3;
    int array[3] = {5, 0, 13};

    printf("Array Before: %d %d %d\n", array[0], array[1], array[2]);
    swapMaxMin(array,size);
    printf("Array After: %d %d %d\n", array[0], array[1], array[2]);
    

    char str[10]= "Your Mom";
    char result;

    lastChar(str, &result);

    printf("string: %s\n", str);
    printf("result: %c\n", result);
    }