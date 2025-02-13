#include "lab7.h"


struct VendingMachine_t { 
    StockItem item;
    VendingMachine * next;
};

int main (){
    VendingMachine* vm = newMachine();

    StockItem item1;
    item1.ID = 1;
    item1.stock = 2;
    item1.maxStock =5;
    item1.price = 2.5;

    StockItem item2;
    item2.ID = 2;
    item2.stock = 5;
    item2.maxStock =5;
    item2.price = 2.6;

    StockItem test;

    printf("Item Count: %d\n", countItems(vm));
    printf("ID: %d\n", vm->item.ID);
    printf("Full Count: %d\n", countFull(vm));

    addStockItem(vm,item1);

    printf("ID: %d\n", vm->next->item.ID);

    addStockItem(vm,item2);

    printf("ID 0: %d\n", vm->item.ID);
    printf("ID 1: %d\n", vm->next->item.ID);
    printf("ID 2: %d\n", vm->next->next->item.ID);

    printf("Item Count: %d\n", countItems(vm));
    printf("Full Count: %d\n", countFull(vm));

    printf("test ID: %d\n", test.ID);

    getStockItem(vm, 2, &test);

    printf("test ID: %d\n", test.ID);

    freeVendingMachine(vm);
}

