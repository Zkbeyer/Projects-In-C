#include "lab3.h"

void printBoard(int* board) {
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++){
            printf("%d", board[i]);
            if ((i+1)%8 == 0 && i!=0){
                printf("\n");
            }
    }
    printf("\n");
}

void printStats(int* board){
    printf("\nTotal Shots: %d\n", getShotsTaken(board));
    printf("Succesfull: %d\n", getHits(board));
    updateScore(board);
    printf("Score: %f\n", getScore(board));
}

int main(){
    int* board = newBoard();

    printBoard(board);

    printf("\nShips Left:%d\n", countRemainingShips(board));


    for(int i = 0; i < BOARD_SIZE; i++){
        if (i%2 == 0){
            board[i] = 1;
        }
    }

    printf("\n");

    printBoard(board);

    printf("\nShips Left:%d\n", countRemainingShips(board));


    for(int i = 0; i < BOARD_SIZE; i++){
        takeShot(board, i);
        printStats(board);
        printf("Ships Left:%d\n", countRemainingShips(board));
        printBoard(board);
    }



   

    endGame(board);

}
