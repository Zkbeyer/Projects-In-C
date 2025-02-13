#include "lab10.h"

typedef struct Node Node;

struct Node {
    Node *next;
    void *data;
};

struct Queue_t {
    Node *head;
    Node *end;
    int size;
};

/*For this function I simply create a queue node that will act as the head of the queue. I also make sure to initilize evyrthing*/
Queue * newQueue(void) {
    Queue * n = malloc(sizeof(Queue));
    if(!n){
        return NULL;
    }
    n->head = NULL;
    n->end = NULL;
    n->size = 0;
    return n;
}

/*This function simply returns the size held in the head that is updated in other functions*/
int getSize(Queue *q){
    return q->size;
}

/* For this function I go to the end of the queue from my head and malloc a new node. After a quick check to make sure malloc worked
I set up this new node and update the header to make sure it has the correct end and size. I then return 1 on success.*/
int enQueue(Queue *q, void *data){
    Node *temp = q->end;
    Node *p = malloc(sizeof(Node));
    if(!p){
        return 0;
    }
    q->end = p;
    q->size ++;
    p->next = NULL;
    p->data = data;
    if (!q->head){
        q->head = p;
        return 1;
    }
    temp->next = p;
    return 1;
}

/*For this function I simply check to make sure there are items in the list, and if there are I return the first item's data*/
void * peek(Queue *q){
    if(q->head){
        return q->head->data;
    }
    return NULL;
}

/*For this function I make sure the list isnt empty. Then I update information in the head to remove the node. 
Finally I free the node and return the data*/
void * deQueue(Queue *q){
    if(!q->head){
        return NULL;
    }
    Node *temp = q->head;
    if(!temp->next){
        q->head = NULL;
    } else {
        q->head = temp->next;  
    }
    q->size --;
    void *n = temp->data;
    free(temp);
    return n;
}

/*For this function I simply iterate thorugh the list and remove everythign in it, before removeing the head.*/
void destroy(Queue *q){
    Node *cursor = q->head;
        while(cursor) {
            Node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        free(q);
}


