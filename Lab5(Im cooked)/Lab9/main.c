#include "lab9.h"

typedef struct Node Node;

struct Node {
    Node *next;
    char character;
};

struct StringBuilder_t {
    Node *head;
    Node *end;
    int size;
};


int main(){
    StringBuilder *head = newBuilder();

    printf("Size:%d\n", getSize(head));

    printf("\n%s\n", toStr(head));
    printf("Last M:%d\n\n", lastIndex(head, 'm'));


    appendChar(head, 'L');
    appendChar(head, 'O');
    printf("First:%c\n", firstChar(head));
    printf("Second:%c\n", head->head->next->character);
    printf("Size:%d\n", getSize(head));
    appendStr(head, "Mom");
    printf("%s\n", toStr(head));
    printf("Size:%d\n", getSize(head));
    printf("Last M:%d\n", lastIndex(head, 'm'));
    appendChar(head, 'm');
    printf("%s\n", toStr(head));
    printf("Last M:%d\n", lastIndex(head, 'm'));


}