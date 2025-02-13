#include "lab4.h"

void printStruct(GameBoard * board){
    printf("\nShots:%d\n", getShotsTaken(board));
    printf("Hits:%d\n", getHits(board));
    printf("Score:%f\n\n", getScore(board));
    for(int i = 0; i<BOARD_SIZE; i++){
        printf("%d", board->arena[i]);
        if( (i+1)%8 == 0 ){
            printf("\n");
        }
    }
}


int main(){
    GameBoard * board = newBoard();
    placeShip(board, 3);
    placeShip(board, 5);
    placeShip(board, 10);
    placeShip(board, 11);
    placeShip(board, 16);
    placeShip(board, 3);
    placeShip(board, 3);
    placeShip(board, 31);
    placeShip(board, 24);

    printf("Free Cells:%d\n", countFreeCells(board));

    for (int i =0; i< BOARD_SIZE;i++){
        takeShot(board, i);
        printStruct(board);
    }

    endGame(board);
}