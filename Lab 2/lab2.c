#include "lab2.h"

/* In this function I simply initilize an int pointer and allocate enough space for the correct size of the array, 
then iterate through the array and set every element to 0*/
int * makeArray(int size){
    int *array;
    if( (array = malloc(size*sizeof(int)))){
    for (int i = 0; i < size; i++){
        array[i] = 0;
    }
    return array;
    }
    return NULL;
}

/*In this function I simply iterate through the array and check every position to see if it matches the wanted element
if it does I return the index it is in, if it is not I return -1*/
int indexOf(int *array, int size, int element){
    for (int i = 0; i < size; i++){
        if (array[i] == element){
            return i;
        }
    }
    return -1;
}

/* In this array I call the indexOf function to find the index of the numbers we want to start and end our array at, 
I then subtract them and add 1 to see how big our new array is going to be. I also check to make sure the numbers are actually
in the array. After that I set the result array to the old array with a new start and retun the size of the new array*/
int sliceArray(int *array, int size, int begin, int end, int **result){
    int startIndex = indexOf(array, size, begin);
    int endIndex = indexOf(array, size, end);
    //check to make sure the values are in the array
    if(indexOf(array, size, begin) == -1 || indexOf(array, size, end) == -1){
        return -1;
    }

    int spliceSize = endIndex - startIndex + 1;

    *result = (array + startIndex);
    return spliceSize;

}

/* I simply take the array pointer, free it, and then set it to NULL*/
void freeArray(int **array){
    free(*array);
    *array = NULL;
}
