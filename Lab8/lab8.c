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

// I wrote this helper Function to make initilize a Node for me //
Node * makeNode(Node *next, StockItem data) {
    Node *n = malloc(sizeof(Node));

    if(n) {
        *n = (Node){next, data};
    }

    return n;
}

/* This function creates a vending machine struct for me to act as the head of the linked list
I initilize the head to NULL an also initilize the length of the linked list before returning the pointer. */
VendingMachine * newMachine() {
    VendingMachine *machine = malloc(sizeof(VendingMachine));

    if(!machine) {
        return NULL;
    }

    machine->head = NULL;
    machine->size = 0;
    return machine;
}

/*For this function I create a temp node that starts at the front of the list, before iterating through the list I first check to make sure that 
requested ID is greater than zero, if so I add the node at the front of the list, I do the same if there are no items in the list yet. After
this initial check, I iterate through the array until I find a matching ID, if no matching ID is found I add the item to the end of the list. 
If a matching ID is found I simply add the Node after that ID.*/
int addStockItem(VendingMachine *vm, StockItem item, int afterID) {
    Node* temp = vm->head;
    if(afterID <= 0 || !vm->head){
        Node *n = makeNode(vm->head, item);
        if(!n){
            return 0;
        }
        vm->head = n;
        vm->size++;
        return 1;
    }
    while(temp->data.ID != afterID){
        if(!temp->next){
            Node *n = makeNode(NULL, item);
            if(!n){
                return 0;
            }
            temp->next = n;
            vm->size++;
            return 1;
        }
        temp = temp->next;
    }
    Node *n = makeNode(temp->next, item);
    if(!n) {
        return 0;
    }
    temp->next = n;
    vm->size++;
    return 1;
}

/* For this function I simply iterate through the array and print all the ID;s in the list*/
void printIDS(VendingMachine *vm){
    printf("Vending Machine:");
    for(Node* cursor = vm->head; cursor; cursor = cursor->next){
        printf(" %d,", cursor->data.ID);
    }
    printf("\n");
    return;
   
}

/*For this function I first make sure there are items in the list, if there are then I iterate through the array looking for a matching ID 
and a stock greater than 0, if I do I decrement stock and return 1, otherwise I simply return 0 */
int purchaseItem(VendingMachine *vm, int ID){
    Node* cursor = vm->head;
    if(!cursor){
        return 0;
    }
    while(cursor){
        if(cursor->data.ID == ID ){
            if(cursor->data.stock > 0){
                cursor->data.stock--;
                return 1;
            }
            return 0;
        }
        cursor = cursor->next;
    }
    return 0;
}

/*For this function I first check to make sure there are items in the list. If there are then I check to see if the first item is has the ID
Im looking for, if it does I remove that item, otherwise I iterate through the rest of the array looking for a matching ID, if I find the ID
I remove that item, if I dont find that ID I return 0*/
int removeStockItem(VendingMachine *vm, int ID, StockItem *result){
    Node *cursor = vm->head;
    if(!cursor){
        return 0;
    }
    if(cursor->data.ID == ID){
        *result = cursor->data;
        vm->head = cursor->next;
        free(cursor);
        vm->size--;
        return 1;
    }
    while(cursor->next){
        if(cursor->next->data.ID == ID){
            Node *temp = cursor->next;
            *result = temp->data;
            cursor->next = temp->next;
            free(temp);
            vm->size--;
            return 1;
        }
        cursor = cursor->next;
    }
    return 0;
}

/*In this function I simply iterate through the list freeing all memory allocated
I finish off by freeing the head.*/
void freeVendingMachine(VendingMachine *vm) {
    Node *cursor = vm->head;
    while(cursor) {
        Node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    free(vm);
}



