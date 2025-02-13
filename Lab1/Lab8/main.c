#include "lab8.h"

typedef struct Node Node;

struct Node {
    Node *next;
    StockItem data;
};

struct VendingMachine_t {
    Node *head;
    int size;
};

int getStockItem(VendingMachine *vm, int ID, StockItem *result) {
    Node *cursor = vm->head;

    // Another possible way to iterate over a linked list
    // Highly recommended
    while(cursor) {
        if(cursor->data.ID == ID) {
            *result = cursor->data;
            return 1;
        }
        cursor = cursor->next;
    }

    return 0;
}

int main(){
    VendingMachine *vm = newMachine();
    StockItem result;

    StockItem item1;
    item1.ID = 1;
    item1.maxStock = 5;
    item1.stock = 2;
    item1.price = 3.2;

    StockItem item2;
    item2.ID = 2;
    item2.maxStock = 6;
    item2.stock = 4;
    item2.price = 2.5;

    StockItem item3;
    item3.ID = 3;
    item3.maxStock = 3;
    item3.stock = 1;
    item3.price = 1.6;

    addStockItem(vm, item1, 7);
    printIDS(vm);

    addStockItem(vm, item2, 0);
    printIDS(vm);

    addStockItem(vm, item3, 5);
    printIDS(vm);

    getStockItem(vm, 1, &result);
    printf("\nStock: %d\n", result.stock);
    printf("Error Code: %d\n",purchaseItem(vm, 1));
    getStockItem(vm, 1, &result);
    printf("Stock: %d\n\n", result.stock);

    getStockItem(vm, 1, &result);
    printf("\nStock: %d\n", result.stock);
    printf("Error Code: %d\n",purchaseItem(vm, 1));
    getStockItem(vm, 1, &result);
    printf("Stock: %d\n\n", result.stock);

    getStockItem(vm, 1, &result);
    printf("\nStock: %d\n", result.stock);
    printf("Error Code: %d\n",purchaseItem(vm, 1));
    getStockItem(vm, 1, &result);
    printf("Stock: %d\n\n", result.stock);



    getStockItem(vm, 3, &result);
    printf("\nStock: %d\n", result.stock);
    printf("Error Code: %d\n",purchaseItem(vm, 3));
    getStockItem(vm, 3, &result);
    printf("Stock: %d\n\n", result.stock);


    getStockItem(vm, 2, &result);
    printf("\nStock: %d\n", result.stock);
    printf("Error Code: %d\n",purchaseItem(vm, 2));
    getStockItem(vm, 2, &result);
    printf("Stock: %d\n\n", result.stock);


    removeStockItem(vm, 3, &result);
    printIDS(vm);
    printf("%d\n", result.ID);

    removeStockItem(vm, 3, &result);
    printIDS(vm);
    printf("%d\n\n", result.ID);

    removeStockItem(vm, 2, &result);
    printIDS(vm);
    printf("%d\n\n", result.ID);

    removeStockItem(vm, 1, &result);
    printIDS(vm);
    printf("%d\n", result.ID);

    removeStockItem(vm, 1, &result);
    printIDS(vm);
    printf("%d\n\n", result.ID);

    
    freeVendingMachine(vm);
}