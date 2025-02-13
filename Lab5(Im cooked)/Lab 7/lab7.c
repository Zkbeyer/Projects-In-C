#include "lab7.h"

/*For the struct implementation I simply added a stockitem as well as a pointer to the next item in the vending machine*/
struct VendingMachine_t { 
    StockItem item;
    VendingMachine * next;
};

/*For this function I simply initialize an empty vending machine struct to act as the head of the linked list, I initialize everything to 0
and return the empty struct*/
VendingMachine * newMachine(){
    VendingMachine * newMachine = malloc(sizeof(VendingMachine));
    if(!newMachine){
        return NULL;
    }

    newMachine->item.ID = 0;
    newMachine->item.stock = 0;
    newMachine->item.maxStock = 0;
    newMachine->item.price = 0.0;
    newMachine->next = NULL;

    return newMachine;
}

/*For this function I first create a new VendingMachine struct and add the needed data to said struct.
I then have then set the next pointer to whatever was previously first and then make this new item the first in the list*/
int addStockItem(VendingMachine *vm, StockItem item){
    VendingMachine * newItem = malloc(sizeof(VendingMachine));
    if (!newItem){
        return 0;
    }

    newItem->item = item;
    newItem->next = vm->next;
    vm->next = newItem;

    return 1;
}

/*For this function, I first initialize a count variable and then make sure that I am starting at the first item in the 
list instead of the header. I then itterate through the linked list until I reach the end, incrementing count everytime there is another 
item. Finally I simply return count*/
int countItems(VendingMachine *vm){
    int count = 0;
    vm = vm->next;
    while(vm != NULL){
        count++;
        vm = vm->next;
    }
    return count;
}

/*For this function, I first initialize a count variable and then make sure that I am starting at the first item in the 
list instead of the header. I then itterate through the linked list until I reach the end, incrementing count everytime there is an 
item where stock == maxStock. Finally I simply return count*/
int countFull(VendingMachine *vm){
    int count = 0;
    vm = vm->next;
    while(vm != NULL){
        if(vm->item.stock == vm->item.maxStock){
            count++;
        }
        vm = vm->next;
    }
    return count;
}

/*For this function I first make sure that I am starting at the first item in the list instead of the header.
Then I itterate through the list until I find the matching ID number. I then update the result pointer and return 1. If there is
no ID matching the requested ID, then I return 0 to show the search failed.*/
int getStockItem(VendingMachine *vm, int ID, StockItem *result){
    vm = vm->next;
    while(vm != NULL){
        if(vm->item.ID == ID){
            *result = vm->item;
            return 1;
        }
        vm = vm->next;
    }
    return 0;
}

/*For this function I create a temporary pointer to help with the freeing. I then set the temp variable to point to what vm was and have vm go to the 
next item while freeing the temp variable. I then repeat this proccess until I have gone through the entire linked list, and then return to end the function.*/
void freeVendingMachine(VendingMachine *vm){
    VendingMachine * temp = vm;
    while(vm != NULL){
        vm = vm->next;
        free(temp);
        temp = vm;
    }
    return;
}
