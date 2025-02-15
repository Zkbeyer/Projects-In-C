#include <stdio.h>
#include <stdlib.h>

// partial typedef, must complete in implementation file
typedef struct VendingMachine_t VendingMachine;

typedef struct {
    int ID;
    // The amount of this item currently in stock
    int stock;
    // The max amount of this item that can fit in a slot
    int maxStock;
    // The purchase price of 1 of this item
    float price;
} StockItem;


VendingMachine* newMachine();

int addStockItem(VendingMachine *vm, StockItem item);

int countItems(VendingMachine *vm);

int countFull(VendingMachine *vm);

int getStockItem(VendingMachine *vm, int ID, StockItem *result);

void freeVendingMachine(VendingMachine *vm);



