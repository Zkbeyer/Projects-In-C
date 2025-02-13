#include "lab5.h"

/*I added a stockitem pointer so I can malloc an array of stockitems later, I also added a numslots variable so I know how big my array is
at all times*/
struct VendingMachine_t {
    StockItem* machine;
    int numSlots;
};

/*First I malloc space for the struct itself, second I malloc space for the array of stockitems that my machine pointer will
point to. I then check to make sure it malloced correctly, returning NULL if not, and finally initializing everything to 0 and
returning the pointer*/
VendingMachine * newMachine(int numSlots){
    VendingMachine * newMachine = malloc(sizeof(VendingMachine));
    newMachine->machine = malloc(numSlots*sizeof(StockItem));
    if (!newMachine || !newMachine->machine){
        return NULL;
    }
    for(int i = 0; i < numSlots;i++){
        newMachine->machine[i].ID = 0;
        newMachine->machine[i].stock = 0;
        newMachine->machine[i].maxStock = 0;
        newMachine->machine[i].price = 0.0;
    }
    newMachine->numSlots = numSlots;
    return newMachine;
}

/*I iterate through the entire array looking for an empty slot, if there is an empty slot I add the item there and return 1, if there
is not an open slot, I simply return 0*/
int addStockItem(VendingMachine *vm, StockItem item){
    for(int i = 0; i < vm->numSlots ;i++){
        if (vm->machine[i].ID == 0){
            vm->machine[i] = item;
            return 1;
        }
    }
    return 0;
}

/*For this function I create an int variable to keep count. I then iterate through the array and check for any members where the
stock is > 0 and increment count accordingly then returning count*/
int countInStock(VendingMachine *vm){
    int count = 0;
    for(int i = 0; i < vm->numSlots;i++){
        if(vm->machine[i].stock > 0){
            count++;
        }
    }
    return count;
}

/*This function iterates through the array and looks for any member with a matching ID, if it finds one, it sets the result to that member and then
empties the slot and returns 1. If there is no matching ID in the array I simply return 0*/
int removeStockItem(VendingMachine *vm, int ID, StockItem *result){
    for(int i = 0; i < vm->numSlots ;i++){
        if (vm->machine[i].ID == ID){
            *result = vm->machine[i];
            vm->machine[i].ID = 0;
            vm->machine[i].stock = 0;
            vm->machine[i].maxStock = 0;
            vm->machine[i].price = 0.0;
            return 1;
        }
    }
    return 0;
}

/*I simply free the array first, and then the struct second*/
void freeVendingMachine(VendingMachine *vm){
    free(vm->machine);
    free(vm);
}