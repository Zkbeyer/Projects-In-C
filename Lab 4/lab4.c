#include "lab4.h"


/*For this function I create a new gameboard pointer and malloc a memory slot the size of gameboard then initilize everything inside the struct to
be 0. I then return the pointer if malloc worked, and return NULL if malloc failed*/
GameBoard * newBoard(){
    GameBoard * newBoard;
    if ((newBoard = malloc(sizeof(GameBoard)))){
    newBoard->shots = 0;
    newBoard->hits = 0;
    newBoard->score = 0.0;
    for(int i = 0; i<BOARD_SIZE; i++){
        newBoard->arena[i] = 0;
    }
    return newBoard;
    }
    return NULL;
}

/*For this function I immidiatly increment shots by one, then check to see if there was a ship in the guesssed cell
if so I increment hits, change the cell to -1, update the score and then return 1 for a hit. If there is no ship there I 
simply update the score and return 0 for a miss.*/
int takeShot(GameBoard *board, int cell){
    board->shots += 1;
    if(board->arena[cell] == 1){
        board->hits += 1;
        board->arena[cell] = -1;
        board->score = (float)board->hits / (float)board->shots;
        return 1;
    }
    board->score = (float)board->hits / (float)board->shots;
    return 0;

}

/* for this function I create a variable to keep track of the empty cells. I then iterate throught the array and increment my variable everytime I find a
0 in the array. I then return the variable at the end of the function*/
int countFreeCells(GameBoard *board){
    int empty = 0;
    for(int i = 0; i < BOARD_SIZE;i++){
        if(board->arena[i] == 0){
            empty += 1;
        }
    }
    return empty;
}

/*I just return the shots variable from the struct*/
int getShotsTaken(GameBoard *board){
    return board->shots;
}

/*I just returnm the hits variable from the struct*/
int getHits(GameBoard *board){
    return board->hits;
}

/*I just return the score variable from the struct*/
float getScore(GameBoard *board){
    return board->score;
}

/*I first check to see if the given cell is empty, if it is I add a 1 to represent a ship and return 1 to show success
If the given cell is not empty I simply return 0*/
int placeShip(GameBoard *board, int cell){
    if(board->arena[cell] == 0){
        board->arena[cell] = 1;
        return 1;
    }
    return 0;
}

/*I simply free the pointer I created in the earlier function*/
void endGame(GameBoard *board){
    free(board);
}