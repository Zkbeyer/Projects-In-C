#include "lab1.h"

/* I simply use a temporary variable to hold the value that pointer a is pointing to, then 
set the value a is pointing to the value b is pointing to, then go back and set b to the original
a value */

void swap(int *a, int *b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
   
}

/* In This function I create two variables and iterate through a loop to find the location of the maximum and minimum 
values in the array, I then use my swap function with the pointer being the array plus the value of the location of the min,
or max value to swap their positions in the array.*/

int swapMaxMin(int array[], int size){
    int min = 0;
    int max = 0;
    for (int i = 0; i < size; i++){
        if (array[i] > array[max]){
            max = i;
        }
        if (array[i] < array[min]){
            min = i;
        }
    }
    //Check to make sure min and max have their own value
    if (min == max){
        return 1;
    } 
    swap((array + min), (array + max));
    return 0;
}

/* In this function I first check to make sure the string given isnt null, and if it is
I return 1. Then I iterate through a loop until I find the NULL character, then print 
the last character before the null before returning 0*/

int lastChar(char str[], char *result){
    if (str[0] == NULL){
        return 1;
    }
    int i = 0;
    while (str[i] != 0){
        i++;
    }
    *result = str[i-1];
    return 0;
}