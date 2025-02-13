#include "lab10.h"

typedef struct Node Node;

struct Node {
    Node *next;
    void* data;
};

struct Queue_t {
    Node *head;
    Node *end;
    int size;
};

int main(){
    Queue *q = newQueue();
    int num = 4;
    char letter = 'l'; 
    printf("%d\n\n", getSize(q));

    enQueue(q, &num);
    printf("%d\n", getSize(q));
    int *temp1 = peek(q);
    printf("%d\n\n", *temp1);

    enQueue(q, &letter);
    printf("%d\n", getSize(q));
    int *temp2 = peek(q);
    printf("%d\n\n", *temp2);

    int *temp6 = deQueue(q);
    printf("%d\n", getSize(q));
    char *temp3 = peek(q);
    printf("%d\n", *temp6);
    printf("%c\n\n", *temp3);

    char *temp5 = deQueue(q);
    printf("%d\n", getSize(q));
    char *temp4 = peek(q);
    printf("%c\n", *temp5);
    printf("%p\n\n", temp4);

    destroy(q);

}