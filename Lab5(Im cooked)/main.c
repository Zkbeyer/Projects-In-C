#include "lab5.h"

struct VendingMachine_t {
    StockItem* machine;
    int numSlots;
};

int main(){
    VendingMachine * machine = newMachine(5);

    StockItem item1;
    item1.ID = 1;
    item1.stock = 2;
    item1.maxStock = 3;
    item1.price = 4.5;

    StockItem item2;
    item2.ID = 2;
    item2.stock = 3;
    item2.maxStock = 4;
    item2.price = 5.5;

    StockItem item3;
    item3.ID = 3;
    item3.stock = 4;
    item3.maxStock = 5;
    item3.price = 6.5;

    StockItem result;

    addStockItem(machine, item1);
    addStockItem(machine, item2);
    addStockItem(machine, item3);

    printf("%d %d %d %f\n", machine->machine[0].ID, machine->machine[0].stock, machine->machine[0].maxStock, machine->machine[0].price);
    printf("%d %d %d %f\n", machine->machine[1].ID, machine->machine[1].stock, machine->machine[1].maxStock, machine->machine[1].price);
    printf("%d %d %d %f\n", machine->machine[2].ID, machine->machine[2].stock, machine->machine[2].maxStock, machine->machine[2].price);
    printf("%d %d %d %f\n\n", machine->machine[3].ID, machine->machine[3].stock, machine->machine[3].maxStock, machine->machine[3].price);

    printf("items:%d\n\n", countInStock(machine));

    removeStockItem(machine, 2, &result);

    printf("%d %d %d %f\n", machine->machine[0].ID, machine->machine[0].stock, machine->machine[0].maxStock, machine->machine[0].price);
    printf("%d %d %d %f\n", machine->machine[1].ID, machine->machine[1].stock, machine->machine[1].maxStock, machine->machine[1].price);
    printf("%d %d %d %f\n", machine->machine[2].ID, machine->machine[2].stock, machine->machine[2].maxStock, machine->machine[2].price);
    printf("%d %d %d %f\n\n", machine->machine[3].ID, machine->machine[3].stock, machine->machine[3].maxStock, machine->machine[3].price);
    
    printf("items:%d\n\n", countInStock(machine));

    addStockItem(machine, item2);

    printf("%d %d %d %f\n", machine->machine[0].ID, machine->machine[0].stock, machine->machine[0].maxStock, machine->machine[0].price);
    printf("%d %d %d %f\n", machine->machine[1].ID, machine->machine[1].stock, machine->machine[1].maxStock, machine->machine[1].price);
    printf("%d %d %d %f\n", machine->machine[2].ID, machine->machine[2].stock, machine->machine[2].maxStock, machine->machine[2].price);
    printf("%d %d %d %f\n\n", machine->machine[3].ID, machine->machine[3].stock, machine->machine[3].maxStock, machine->machine[3].price);
    
    printf("items:%d\n\n", countInStock(machine));

    printf("%d %d %d %f\n", result.ID, result.stock, result.maxStock, result.price);

    freeVendingMachine(machine);


}