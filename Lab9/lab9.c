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

// Helper Function //
Node * makeNode(Node *next, char letter) {
    Node *n = malloc(sizeof(Node));

    if(n) {
        *n = (Node){next, letter};
    }

    return n;
}


/*for this function I simply allocate space for my header node for my linked list
I also initilize everything accordingly, returning NULL if the malloc fails*/
StringBuilder * newBuilder(void){
    StringBuilder *n = malloc(sizeof(StringBuilder));
    if(n) {
        n->head = NULL;
        n->end = NULL;
        n->size = 0;
        return n;
    }
    return NULL;
}

/* In this function, I simply return the size variable held in my head, I update this
variable in other functions to make sure it is accurate*/
int getSize(StringBuilder *b){
    return b->size;
}

/*For this function, I use my end pointer to append a character node to the end of my list in 0(1) time
I also make check to make sure this function doesnt break with no items in the list. I also adjust all other pointers
and increment size to make sure everything is accurate.*/
int appendChar(StringBuilder *b, char c){
    if(b->head == NULL){
        b->head = makeNode(NULL, c);
        if(b->head){
            b->end = b->head;
            b->size++;
            return 1;
        }
        return 0;
    }

    Node *temp = b->end;
    temp->next = makeNode(NULL, c);
    if(temp->next){
        b->end = temp->next;
        b->size++;
        return 1;
    }
    return 0;
}

/*for this function, I simply return the first object's character, returning the null character if there is nothing in the list*/
char firstChar(StringBuilder *b){
    if(b->head){
        return b->head->character;
    }
    return '\0';
}

/*For this function I use the idea that a string is an array and iterate through that array appending each character
individually to the end of my list, checking each time to make sure the malloc was succesful.*/
int appendStr(StringBuilder *b, char *s){
    for(int i = 0; s[i] != '\0'; i++){
        if(appendChar(b,s[i]) == 0){
            return 0;
        }
    }
    return 1;
}

/*In this function I first check to make sure there is a list to convert, then I malloc a character pointer large enough to hold the whole string
including the null terminator. After this I iterate through the array and put each character node into its own spot in the character array. Finally 
append the null terminator to the end of the string and return the string.*/
char * toStr(StringBuilder *b){
    if(b->head == NULL){
        return NULL;
    }
    char *string = malloc(sizeof(char) * ((b->size)+1));
    Node *cursor = b->head;
    int i = 0;
    while(cursor){
        string[i] = cursor->character;
        i++;
        cursor = cursor->next;
    }
    string[i] = '\0';
    return string;
}

/*In this function I simply iterate through the entire array noting everytime I match characters, updating if there is a later instance
of a matching character. After going through the array I return the index. The index will be -1 if no matching character is found.*/
int lastIndex(StringBuilder *b, char c){
    Node *cursor = b->head;
    int index = -1;
    for(int i = 0; cursor; i++){
        if(cursor->character == c){
            index = i;
        }
        cursor = cursor->next;
    }
    return index;
}

/* in this function, I simply iterate through the list and free everything associated with it.*/
void destroy(StringBuilder *b){
    Node *cursor = b->head;
        while(cursor) {
            Node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        free(b);
}
